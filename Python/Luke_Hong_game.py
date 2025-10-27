import random

print("Welcome to the Number Guessing Game!")
print("I'm thinking of a number between 1 and 100.")

# generate a random number
secret_number = random.randint(1, 100)

# keep track of attempts
attempts = 0

while True:
    guess = input("Take a guess (or type 'quit' to stop): ")

    if guess.lower() == "quit":
        print("Goodbye!")
        break
      
    if not guess.isdigit():
        print("Please enter a number!")
        continue

    guess = int(guess)
    attempts += 1

    if guess < secret_number:
        print("Too low! Try again.")
    elif guess > secret_number:
        print("Too high! Try again.")
    else:
        print(f"🎉 You got it! The number was {secret_number}.")
        print(f"It took you {attempts} tries.")
        break
