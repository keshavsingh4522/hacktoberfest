# Python Program to check for vowels

word = input('Enter a word: ')

vowels = ['a', 'e', 'i', 'o', 'u']

result = "Your word has no vowels!"
for letter in vowels:
    if letter in word:
        result = "Your word has a vowel!"
        break

print(result)