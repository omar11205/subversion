def add_expense(expenses, amount, category):
    # A dictionary is another built-in data type in Python.
    # A dictionary is a collection of data in the form of key-value pairs.
    expenses.append({'amount': amount, 'category': category})
    pass


def print_expenses(expenses):
    for expense in expenses:
        print(f'Amount: {expense["amount"]}, Category: {expense["category"]}')
        pass


def total_expenses(expenses):
    return sum(map(lambda expense: expense['amount'], expenses))


'''
    The values that are declared within a function when the function is called are known as an argument. 
    The variables that are defined when the function is declared are known as parameters.
'''


def filter_expenses_by_category(expenses, category):
    # expense["category"] == category returns false if the value of the parameter 'category' is not the same as
    # stored at the key expense["category"]
    return filter(lambda expense: expense["category"] == category, expenses)


def main():
    expenses = []
    add_expense(expenses, 100, 'Food')
    add_expense(expenses, 20, 'Food')
    add_expense(expenses, 140, 'Cleaning Products')
    add_expense(expenses, 500, 'Rent')
    add_expense(expenses, 1000, 'For having fun')
    total_expenses(expenses)