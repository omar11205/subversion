import re
# import random
import secrets
import string

'''
    The purpose of this code is to randomly generate a password
'''


def generate_password(length=8, nums=1, special_chars=1, uppercase=1, lowercase=1):
    # Define the possible characters for the password
    letters = string.ascii_letters
    digits = string.digits
    symbols = string.punctuation

    # In python concatenate is equal to: string + string ...
    all_characters = letters + digits + symbols

    # Random return a random float between 0 and 1, excluding 1, including 0
    # print(random.random())

    # Choice selects randomly a character from a string
    # print(random.choice(all_characters))
    # print(all_characters)

    # However random module is still predictable, so for cryptographic purposes use instead
    # the secrets module
    # print(secrets.choice(all_characters))
    while True:
        password = ''
        # Generating Password
        for _ in range(length):
            password += secrets.choice(all_characters)
        constraints = [
            (nums, r'[0-9]'),
            (lowercase, r'[a-z]'),
            (uppercase, r'[A-Z]'),
            (special_chars, fr'[{symbols}]')
            # matches all ascii symbols
            # r'' + f'' = fr''
            # f'' is used for string interpolation
        ]
        # all is a function who evaluates if all the conditions passed in form of a list are true and returns True
        # otherwise returns False: all([conditional1, conditional2, ...]) but it can be shorted to
        # all(conditional1, conditional2, ...)
        # using list comprehension syntax I can do in order to create a list of conditionals
        # and evaluate if all are True:
        #
        # if all([
        #   constraint <= len(re.findall(pattern, password))
        #   for constraint, pattern in constraints
        # ]):
        #   break
        # and simplifying:
        if all(
            constraint <= len(re.findall(pattern, password))
            for constraint, pattern in constraints
        ):
            break
    return password


# pattern = 'w[ha]' <- match wh or wa
# pattern = '[^a-z]t' <- match all that isn't a-z followed by a t
# pattern = '.+' <- matches one or more occurrences of any character except for a newline
# pattern = '\.' <- scape the special character . to find points
# n Python, a raw string is a string literal prefixed with an 'r' or 'R'.
# When you prefix a string with 'r' or 'R', Python treats backslashes ('\')
# as literal characters, rather than as escape characters.
# pattern = r'\.' <- now matches '\.'
# pattern = r'\d' matches decimals like a normal regular expression for javascript or other languages
# pattern = r'\D' matches all characters less decimals == [^0-9]
# pattern = r'\w' matches all alphanumeric characters and '_'
# pattern = r'\W' matches all characters less alphanumeric characters and '_'


if __name__ == '__main__':
    new_password = generate_password()
    print(new_password)

