"""
    Playfair cipher encryption and decryption using python
"""


def matrix(x, y, position):
    return [[position for i in range(x)] for j in range(y)]


def get_index(c, matrix):
    loc = list()
    if c == 'J':
        c = 'I'
    for i, j in enumerate(matrix):
        for k, l in enumerate(j):
            if c == l:
                loc.append(i)
                loc.append(k)
                return loc


def encryption(message, matrix):
    i = 0
    for s in range(0, len(message)+1, 2):
        if s < len(message)-1:
            if message[s] == message[s+1]:
                message = message[:s+1]+'X'+message[s+1:]
    if len(message) % 2 != 0:
        message = message[:]+'X'
    print("CIPHER TEXT:", end=' ')
    cipher_text = ''
    while i < len(message):
        loc = list()
        loc = get_index(message[i], matrix)
        loc1 = list()
        loc1 = get_index(message[i+1], matrix)
        if loc[1] == loc1[1]:
            cipher_text += str(matrix[(loc[0]+1) % 5][loc[1]]) + \
                str(matrix[(loc1[0]+1) % 5][loc1[1]])
        elif loc[0] == loc1[0]:
            cipher_text += str(matrix[loc[0]][(loc[1]+1) % 5]) + \
                str(matrix[loc1[0]][(loc1[1]+1) % 5])
        else:
            cipher_text += str(matrix[loc[0]][loc1[1]]) + \
                str(matrix[loc1[0]][loc[1]])
        i = i+2
    return cipher_text


def decryption(cipher_text, matrix):
    print("PLAIN TEXT:", end=' ')
    plain_text = ''
    i = 0
    while i < len(cipher_text):
        loc = list()
        loc = get_index(cipher_text[i], matrix)
        loc1 = list()
        loc1 = get_index(cipher_text[i+1], matrix)
        if loc[1] == loc1[1]:
            plain_text += matrix[(loc[0]-1) % 5][loc[1]] + \
                matrix[(loc1[0]-1) % 5][loc1[1]]
        elif loc[0] == loc1[0]:
            plain_text += matrix[loc[0]][(loc[1]-1) %
                                         5] + matrix[loc1[0]][(loc1[1]-1) % 5]
        else:
            plain_text += matrix[loc[0]][loc1[1]] + matrix[loc1[0]][loc[1]]
        i = i+2
    return plain_text


def main():

    key = input("Enter key: ").replace(" ", "").upper()
    result = list()

    for c in key:
        if c not in result:
            if c == 'J':
                result.append('I')
            else:
                result.append(c)
    flag = 0
    for i in range(65, 91):  # storing other character
        if chr(i) not in result:
            if i == 73 and chr(74) not in result:
                result.append("I")
                flag = 1
            elif flag == 0 and i == 73 or i == 74:
                pass
            else:
                result.append(chr(i))
    k = 0
    my_matrix = matrix(5, 5, 0)  # initialize matrix
    for i in range(0, 5):  # making matrix
        for j in range(0, 5):
            my_matrix[i][j] = result[k]
            k += 1

    message = input("Enter Message: ").replace(' ', '').upper()

    cipher = encryption(message, my_matrix)
    print(f"Cipher Text: {cipher}")
    plain_text = decryption(cipher, my_matrix)
    print(f"Plain Text: {plain_text}")


if __name__ == '__main__':
    print("\nPlayFair Cipher Encryption and Decryption\n-------------------------------\n")
    main()