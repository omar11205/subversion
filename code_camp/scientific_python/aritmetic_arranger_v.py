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
            return "Error: Operator must be '+' or '-'."

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

    max_len_spacing = []  # stores the max length
    for i in range(len(operators)):
        max_len_spacing.append(max(len(first_operators[i]), len(second_operators[i]))+1)

    fo_spaced_list = []   # first operators with the required spacing
    so_spaced_list = []   # second operators with the required spacing
    re_spaced_list = []   # results with the required spacing
    for i in range(len(max_len_spacing)):
        fo_align_numb_str = f" {first_operators[i]:>{max_len_spacing[i]}}"
        so_align_numb_str = f"{second_operators[i]:>{max_len_spacing[i]}}"
        fo_spaced_list.append(fo_align_numb_str)
        so_spaced_list.append(so_align_numb_str)
        if show_answers:
            so_align_numb_str = f" {results[i]:>{max_len_spacing[i]}}"
            re_spaced_list.append(so_align_numb_str)

    first_line_string = ''
    spacing = ' ' * 4
    for i, spaced in enumerate(fo_spaced_list):
        if i != len(fo_spaced_list) - 1:
            first_line_string += str(spaced) + spacing
        else:
            first_line_string += str(spaced)

    second_line_string = ''
    for i, spaced in enumerate(so_spaced_list):
        if i != len(so_spaced_list) - 1:
            second_line_string += operators[i] + str(spaced) + spacing
        else:
            second_line_string += operators[i] + str(spaced)

    dashed_line_str = ''
    for i in range(len(max_len_spacing)):
        if i != len(max_len_spacing) - 1:
            dashed_line_str += '-'*(max_len_spacing[i]+1) + spacing
        else:
            dashed_line_str += '-'*(max_len_spacing[i]+1)

    results_line_str = ''
    for i, spaced in enumerate(re_spaced_list):
        if i != len(re_spaced_list) - 1:
            results_line_str += str(spaced) + spacing
        else:
            results_line_str += str(spaced)

    if show_answers:
        arranged_problems = first_line_string + '\n' + second_line_string + '\n' + dashed_line_str + '\n' + results_line_str
    else:
        arranged_problems = first_line_string + '\n' + second_line_string + '\n' + dashed_line_str

    return arranged_problems


print(arithmetic_arranger(["3801 - 2", "123 + 49"]))





