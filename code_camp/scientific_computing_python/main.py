import time

text = "Hello Zaira"
shift = 3
custom_key = "python"

def caesar(message, offset):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    encrypted_text = ''
    for char in message.lower():
        if char == ' ':
            encrypted_text += char
        else:
            index = alphabet.find(char)
            new_index = (index + offset) % len(alphabet)
            encrypted_text += alphabet[new_index]
            print("index: ", index, "new index: ", new_index, "encrypted_text: ", encrypted_text)
    print('plain text', message)
    print('encrypted text:', encrypted_text)


def vigenere(message, key, direction=1):
    key_index = 0
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    final_message = ''
    for char in message.lower():
        # Append space to the message
        if char == ' ':
            final_message += char
        else:
            # Find the right key character to encode
            key_char = key[key_index % len(key)]
            key_index += 1

            # Define the offset and the encrypted letter
            offset = alphabet.index(key_char)
            index = alphabet.find(char)
            new_index = (index + offset*direction) % len(alphabet)
            final_message += alphabet[new_index]

    return final_message


caesar(text, shift)
encryption = vigenere(text, custom_key)
print(encryption)
decryption = vigenere(encryption, custom_key, -1)
print(decryption)



