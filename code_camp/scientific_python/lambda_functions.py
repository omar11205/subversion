expenses = []


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
    return print(sum(map(lambda x: x['amount'], expenses)))


add_expense(expenses, 100, 'Food')
add_expense(expenses, 140, 'Cleaning Products')
add_expense(expenses, 500, 'Rent')
add_expense(expenses, 1000, 'For having fun')
total_expenses(expenses)
