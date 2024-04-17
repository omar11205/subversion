def arithmetic_arranger(problems, show_answers=False):

    # Check if the problems list exceeds the limits
    if len(problems) > 5:
        return "Error: Too many problems."

    allowed_operators = ['+', '-']
    first_operators = []
    second_operators = []
    operators = []
    results = []
    first_operators_int = []
    second_operators_int = []

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

        first_operators.append(first_number)
        second_operators.append(second_number)
        operators.append(operator)

        if show_answers:
            first_operators_int.append(int(first_number))
            second_operators_int.append(int(second_number))

    if show_answers:
        for i in range(len(operators)):
            if operators[i] == '+':
                results.append(first_operators_int[i] + second_operators_int[i])
            elif operators[i] == '-':
                results.append(first_operators_int[i] - second_operators_int[i])

    max_len_spacing = []
    string_result = ''
    first_operands_string = ''
    spacing = ' '*4
    for i in range(len(operators)):
        max_len_spacing.append(max(len(first_operators[i]), len(second_operators[i]))+1)

    fo_dashed_list = []
    for i in range(len(max_len_spacing)):
        # Using f-string (Python 3.6+)
        dash_str = '-' * max_len_spacing[i]
        num_to_replace = len(dash_str) - len(first_operators[i])
        dashed_string = dash_str[:num_to_replace] + first_operators[i]
        fo_dashed_list.append(dashed_string)

    for i, dashed in enumerate(fo_dashed_list):
        if i != len(fo_dashed_list) - 1:  # Verificar si no es el último elemento
            first_operands_string += str(dashed) + spacing  # Agregar el número seguido de cuatro espacios a la cadena
        else:
            first_operands_string += str(dashed)  # Agregar el último número sin espacios adicionales al final

    # for i in range(len(max_len_spacing)):
    #     string_result += max_len_spacing[i] +

    print(fo_dashed_list)
    print(first_operands_string)
    

arithmetic_arranger(['34 + 1546', '1 - 134', '12 - 1000', '1000 + 900'])





