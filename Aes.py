### Install pycrypto using "pip install pycrypto"
from Crypto.Cipher import AES

encryption_key = 32 * b'\x69'

text1 = input("input text : ")

text = text1.encode()
text_padded = text + (AES.block_size - (len(text) % AES.block_size)) * b'\x00'
iv = 16 * b'\x00'
cipher = AES.new(encryption_key, AES.MODE_CBC, iv)
cipher_enc = cipher.encrypt(text_padded)

print("Result = ", cipher_enc.hex())
