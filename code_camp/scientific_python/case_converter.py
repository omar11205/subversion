"""
    Convert from camelCase or PascalCase to snake_case
    Use the ''.join() string method to convert the list of characters into a string.
    For PascalCase: The easiest way to strip such unwanted character
    is by using the .strip() string method and passing
    an underscore to the method as argument.
"""


def convert_to_snake_case(pascal_or_camel_cased_string):
    snake_cased_char_list = []
    for char in pascal_or_camel_cased_string:
        if char.isupper():
            converted_character = '_' + char.lower()
            snake_cased_char_list.append(converted_character)
        else:
            snake_cased_char_list.append(char)
    snake_cased_string = ''.join(snake_cased_char_list)
    clean_snake_cased_string = snake_cased_string.strip('_')
    return clean_snake_cased_string


# this functions goes with python list comprehension to do the same as convert_to_snake_case()
def convert_to_snake_case_comprehensive(pascal_or_camel_cased_string):
    # Inside the space you left between the pair of square braces,
    # you can describe the value that you would like to include in the list based on a given condition.
    snake_cased_char_list = [
        '_' + char.lower() if char.isupper() else char
        for char in pascal_or_camel_cased_string
    ]
    return ''.join(snake_cased_char_list).strip('_')


def main():
    print(convert_to_snake_case('aLongAndComplexString'))
    print(convert_to_snake_case_comprehensive('IAmAPascalCasedString'))


if __name__ == '__main__':
    main()

