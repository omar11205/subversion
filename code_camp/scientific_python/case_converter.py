'''
    Convert from camelCase or PascalCase to snake_case
    Use the ''.join() string method to convert the list of characters into a string.
    For PascalCase: The easiest way to strip such unwanted character is by using the .strip() string method and passing
    an underscore to the method as argument.
'''

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


def main():
    print(convert_to_snake_case('aLongAndComplexString'))


if __name__ == '__main__':
    main()

