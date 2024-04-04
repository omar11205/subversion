def arithmetic_arranger(problems, show_answers=False):

    # Check if the problems list exceeds the limits
    if len(problems) > 5:
        return "Error: Too many problems."

    allowed_operators = ['+', '-']
    first_operators = []
    second_operators = []
    operators = []
    results = []

    for problem in problems:
        first_number, operator, second_number = problem.split(' ')

        if operator not in allowed_operators:
            return "Error: Operator must be '+' or '-"

        only_contains_digits = first_number.isdigit() and second_number.isdigit()
        if not only_contains_digits:
            return 'Error: Numbers must only contain digits.'

        less_than_four_digits = len(first_number) <= 4 and len(second_number) <= 4
        if not less_than_four_digits:
            return 'Error: Numbers cannot be more than four digits.'

        first_operators.append(int(first_number))
        second_operators.append(int(second_number))
        operators.append(operator)

    for i in range(len(operators)):
        if operators[i] == '+':
            results.append(first_operators[i] + second_operators[i])
        elif operators[i] == '-':
            results.append(first_operators[i] - second_operators[i])

    for i in range(len(results)):
        print(f'{first_operators[i]} {operators[i]} {second_operators[i]} = {results[i]}')


arithmetic_arranger(['324 + 546', '124 - 136'])




