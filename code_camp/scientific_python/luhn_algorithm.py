"""
    The Luhn algorithm is as follows:
    From the right to left, double the value of every second digit; if the product is greater than 9, sum the digits of the products.
    Take the sum of all the digits.
    If the sum of all the digits is a multiple of 10, then the number is valid; else it is not valid.
    Assume an example of an account number "7992739871" that will have a check digit added, making it of the form 7992739871x:
    Account number      7   9  9  2  7  3  9   8  7  1  x
    Double every other  7  18  9  4  7  6  9  16  7  2  x
    Sum 2-char digits   7   9  9  4  7  6  9   7  7  2  x
"""


def verify_card_number(card_number):
    sum_of_odd_digits = 0
    card_number_last_two_of_last_four = card_number[0:4:2]
    card_number_start_to_end = card_number[::]
    card_number_last_four_reversed = card_number[-1:-5:-1]
    card_number_reversed = card_number[::-1]
    odd_digits = card_number_reversed[::2]
    for digit in odd_digits:  # "for each element of odd_digits as char"
        # type error, trying to add a string to an integer for that use int(digit)
        sum_of_odd_digits += int(digit)
    print(sum_of_odd_digits)
    sum_of_even_digits = 0
    even_digits = card_number_reversed[1::2]
    for digit in even_digits:
        number = int(digit)*2
        if number >= 10:
            number = (number // 10) + (number % 10)
            print(number)
        sum_of_even_digits += number
    total = sum_of_even_digits + sum_of_odd_digits
    print(total)
    return total % 10 == 0


def main():
    card_number = '4111-1111-4555-1142'
    # replace in the string hyphens and blank spaces for empty spaces
    card_translation = str.maketrans({'-': '', ' ': ''})
    translated_card_number = card_number.translate(card_translation)

    print(translated_card_number)

    if verify_card_number(translated_card_number):
        print('VALID!')
    else:
        print('INVALID!')


main()
