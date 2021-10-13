# an implementation of the ViginereCipher
# Author: @ladokp

class VigenereCipher(object):

    def __init__(self, alphabet: str, password: str):
        self.alphabet = alphabet
        self.password = password

    def encode(self, message: str, shifting_mode: int = 1):
        return_value = ""

        for i in range(0, len(message)):
            character = message[i]
            if character in self.alphabet:
                alphabet_position = self.alphabet.index(character)
                password_shift = self.alphabet.index(self.password[i % len(self.password)])
                alphabet_shift = (alphabet_position + (shifting_mode * password_shift)) % len(self.alphabet)

                return_value += self.alphabet[alphabet_shift]
            else:
                return_value += character

        return return_value

    def decode(self, message: str):
        return self.encode(message, shifting_mode=-1)


# Little test program for ViginereCipher class
alphabet = input("Enter alphabet: ")
password = input("Enter password: ")
message = input("Enter message to encrypt: ")

encryptor = VigenereCipher(alphabet, password)
encoded_message = encryptor.encode(message)

print("Encrypted text: {0}".format(encoded_message))
print("Decrypted text: {0}".format(encryptor.decode(encoded_message)))