def arithmetic_arranger(problems, show_answers=False):
    # Check if the number of problems exceeds the limit
    if len(problems) > 5:
        return "Error: Too many problems."

    arranged_problems = ""
    # Initialize lists to store each part of the problem for later arrangement
    first_operands = []
    second_operands = []
    operators = []

    # Iterate through each problem
    for problem in problems:
        # Split the problem into operands and operator
        operand1, operator, operand2 = problem.split()

        # Check if the operator is valid
        if operator not in ['+', '-']:
            return "Error: Operator must be '+' or '-'."

        # Check if operands contain only digits
        if not operand1.isdigit() or not operand2.isdigit():
            return "Error: Numbers must only contain digits."

        # Check if the operands are not more than four digits
        if len(operand1) > 4 or len(operand2) > 4:
            return "Error: Numbers cannot be more than four digits."

        # Append operands and operator to their respective lists
        first_operands.append(operand1)
        second_operands.append(operand2)
        operators.append(operator)

    # Calculate the width needed for formatting
    max_widths = [max(len(operand1), len(operand2)) for operand1, operand2 in zip(first_operands, second_operands)]

    # Arrange the problems vertically
    for i in range(len(problems)):
        arranged_problems += f"{first_operands[i]:>{max_widths[i]+2}}    "
    arranged_problems = arranged_problems.rstrip() + "\n"

    for i in range(len(problems)):
        arranged_problems += f"{operators[i]} {second_operands[i]:>{max_widths[i]}}    "
    arranged_problems = arranged_problems.rstrip() + "\n"

    for i in range(len(problems)):
        arranged_problems += f"{'-'*(max_widths[i]+2)}    "
    arranged_problems = arranged_problems.rstrip()

    # If show_answers is True, calculate and append the answers
    if show_answers:
        arranged_problems += "\n"
        answers = ""
        for i in range(len(problems)):
            operand1 = int(first_operands[i])
            operand2 = int(second_operands[i])
            if operators[i] == '+':
                answer = operand1 + operand2
            else:
                answer = operand1 - operand2
            max_width = max_widths[i]
            answers += f"{answer:>{max_width+2}}    "
        arranged_problems += answers.rstrip()

    return arranged_problems


print(arithmetic_arranger(["32 + 698", "3801 - 2", "45 + 43", "123 + 49"]))
print(arithmetic_arranger(["32 + 8", "1 - 3801", "9999 + 9999", "523 - 49"], True))
print(arithmetic_arranger(["3801 - 2", "123 + 49"]))

