def verify_card_number(card_number):
    sum_of_odd_digits = 0
    # You have accessed elements (characters) of a string before,
    # using the index operator []
    # . You can also use the index operator to access
    # a range of characters in a string with string[x:y:h]:
    # Where x is the starting index, y is the ending index, and h is the step
    # (the amount of characters to skip over).
    # first four numbers of card number card_number_reversed = card_number[0:4]

    # every second digit of the first four digits of card_number
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
    print(card_number_reversed)
    print(even_digits)


def main():
    card_number = '4111-1111-4555-1142'
    # replace in the string hyphens and blank spaces for empty spaces
    card_translation = str.maketrans({'-': '', ' ': ''})
    translated_card_number = card_number.translate(card_translation)

    print(translated_card_number)

    verify_card_number(translated_card_number)


main()
