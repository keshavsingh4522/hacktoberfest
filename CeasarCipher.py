def encrypt():
    message=input("Type in your message: ")
    shift=int(input("Enter shift: "))
    msg=alphabets[shift:] + alphabets[0:shift]
    output=""
    for letter in message.lower():
        if letter.isalpha():
            output+=msg[alphabets.index(letter)]
        elif letter.isspace():
            output+=" "
        else:
            output+=letter
    print(output)


def decrypt():
    message=input("Type in your code: ")
    shift=int(input("Enter shift: "))
    msg=alphabets[shift:] + alphabets[0:shift]
    output=""
    for letter in message.lower():
        if letter.isalpha():
            output+=alphabets[msg.index(letter)]
        elif letter.isspace():
            output+=" "
        else:
            output+=letter
    print(output)

alphabets="abcdefghijklmnopqrstuvwxyz"
to_do=input("Type in 'encode' to encrypt or 'decode' to decrypt: ")
if to_do=="encode":
    encrypt()
elif to_do=="decode":
    decrypt()
else:
    print("ERROR! Type in proper function!")
