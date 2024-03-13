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
        constraints = [(nums, '')]


# new_password = generate_password(8)
# print(new_password)
pattern = 'l+'
quote = 'Not all those who wander are lost.'
print(re.findall(pattern, quote))
