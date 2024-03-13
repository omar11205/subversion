import re
# import random
import secrets
import string

'''
    The purpose of this code is to randomly generate a password
'''


def generate_password(length, nums, special_chars, uppercase, lowercase):
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

    # However random module is still predictable, so for cryptographic purpuses use instead
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
            (special_chars, (special_chars, r'[^a-zA-Z0-9]'))  # negates (^) all characters except special ones
        ]


# new_password = generate_password(8)
# print(new_password)
# pattern = 'w[ha]' <- match wh or wa
# pattern = '[^a-z]t' <- match all that isn't a-z followed by a t
# pattern = '.+' <- matches one or more occurrences of any character except for a newline
# pattern = '\.' <- scape the special character . to find points
# n Python, a raw string is a string literal prefixed with an 'r' or 'R'.
# When you prefix a string with 'r' or 'R', Python treats backslashes ('\')
# as literal characters, rather than as escape characters.
# pattern = r'\.'
pattern = r'l+'
quote = 'Not all those who wander are lost.'
print(re.findall(pattern, quote))
