# Simple Jumble Word Game In Python
import random
import time

def main():
    # make a list of words
    words = ["python", "jumble", "easy", "difficult", "answer", "xylophone"]
    # pick a random word
    word = random.choice(words)
    # create a variable to use later to see if the guess is correct
    correct = word
    # create a jumbled version of the word
    jumble = ""
    while word:
        position = random.randrange(len(word))
        jumble += word[position]
        word = word[:position] + word[(position + 1):]
    # start the game
    print(
        """
        Welcome to the word jumble game!
        Unscramble the letters to make a word.
        (Press the enter key at the prompt to quit.)
        """
    )
    print("The jumble is:", jumble)
    guess = input("Your guess: ")
    while guess != correct and guess != "":
        print("Sorry, that's not it.")
        guess = input("Your guess: ")
    if guess == correct:
        print("That's it! You guessed it!\n")
    print("Thanks for playing.")
    time.sleep(5)

main()
