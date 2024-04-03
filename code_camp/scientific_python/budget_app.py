class Category:
    def __init__(self, name):
        self.name = name
        self.ledger = []

    def deposit(self, amount, description=""):
        self.ledger.append({"amount": amount, "description": description})

    def withdraw(self, amount, description=""):
        if self.check_funds(amount):
            self.ledger.append({"amount": -amount, "description": description})
            return True
        return False

    def get_balance(self):
        return sum(item['amount'] for item in self.ledger)

    def transfer(self, amount, category):
        if self.check_funds(amount):
            self.withdraw(amount, f"Transfer to {category.name}")
            category.deposit(amount, f"Transfer from {self.name}")
            return True
        return False

    def check_funds(self, amount):
        return amount <= self.get_balance()

    def __str__(self):
        title = f"{self.name:*^30}\n"
        items = ""
        total = 0
        for item in self.ledger:
            items += f"{item['description'][:23]:23}{item['amount']:>7.2f}\n"
            total += item['amount']
        output = title + items + f"Total: {total:.2f}"
        return output


def create_spend_chart(categories):
    category_names = []
    spent_percentages = []
    total_spent = 0

    for category in categories:
        withdrawals = sum(item['amount'] for item in category.ledger if item['amount'] < 0)
        total_spent += withdrawals
        category_names.append(category.name)
        spent_percentages.append(withdrawals)

    for i in range(len(spent_percentages)):
        spent_percentages[i] = (spent_percentages[i] / total_spent) * 100
        spent_percentages[i] = spent_percentages[i] // 10 * 10

    chart = "Percentage spent by category\n"
    for i in range(100, -1, -10):
        chart += str(i).rjust(3) + "| "
        for percentage in spent_percentages:
            if percentage >= i:
                chart += "o  "
            else:
                chart += "   "
        chart += "\n"

    chart += "    " + "-" * (len(category_names) * 3 + 1) + "\n"

    max_length = max(len(name) for name in category_names)
    for i in range(max_length):
        chart += "     "
        for name in category_names:
            if i < len(name):
                chart += name[i] + "  "
            else:
                chart += "   "
        if i < max_length - 1:
            chart += "\n"

    return chart


food = Category("Food")
food.deposit(1000, "deposit")
food.withdraw(10.15, "groceries")
food.withdraw(15.89, "restaurant and more food for dessert")
clothing = Category("Clothing")
food.transfer(500, clothing)
clothing.withdraw(200, "sex shop")

print(food)
print(clothing)
print(create_spend_chart([food, clothing]))
