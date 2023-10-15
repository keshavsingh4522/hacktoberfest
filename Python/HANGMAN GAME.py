import string
import random

# Guess the Word Game
MAX_INCORRECT_GUESSES = 6

def main():
    show_game_description()
    draw_hangman_game(0)
    play_game()
                
def play_game():
    incorrect_guess_counter = 0
    correct_letters = list(WINNING_WORD)
    correct_guesses = []
    incorrect_guess_letters = []
    while incorrect_guess_counter < 6:
    # Get user_letter_guess
        user_letter_guess = input('Guess a letter! (a-z): ')
        # If user enters a capital letter, lowercase it
        user_letter_guess = user_letter_guess.lower()
        # break out of program
        if user_letter_guess == '':
            break
        # Input check: make sure only one letter, and a letter in the alphabet
        while len(user_letter_guess) != 1 or user_letter_guess not in string.ascii_letters:
            user_letter_guess = input('Please enter one letter at a time and guess a letter in the alphabet! (a-z): ')
        # Exit out of program
            if user_letter_guess == '':
                break
        # If user already guessed a letter
        if user_letter_guess in correct_guesses or user_letter_guess in incorrect_guess_letters:
            print('You already guessed that letter!')
        # If user guessed a correct letter in the correct word
        elif user_letter_guess in correct_letters and user_letter_guess not in correct_guesses:
            correct_guesses.append(user_letter_guess)
            guessed = []
            for letters in correct_letters:
                if letters in correct_guesses:
                    guessed.append(letters)
                else:
                    guessed.append('_')
            display_guessed = ' '.join(guessed)
            print(f'The correct letters you have guessed are: {display_guessed}')
            display_incorrect_guess_letters = ' '.join(incorrect_guess_letters)
            print(f'Your incorrect guessed letters are: {display_incorrect_guess_letters}')
            # If the user guessed all the correct letters the user WINS
            if guessed == correct_letters:
                winning_game_message(WINNING_WORD)
                break
        # If the user did not guess a correct letter
        elif user_letter_guess not in WINNING_WORD:
            incorrect_guess_counter += 1
            draw_hangman_game(incorrect_guess_counter)
            print('You guessed an incorrect letter!')
            incorrect_guess_letters.append(user_letter_guess)
            display_incorrect_guess_letters = ' '.join(incorrect_guess_letters)
            print(f'Your incorrect guessed letters are: {display_incorrect_guess_letters}')
            display_correct_guesses = ' '.join(correct_guesses)
            print(f'Your correct guesses are: {display_correct_guesses}')
        # User loses at maximum incorrect guesses
        if incorrect_guess_counter == MAX_INCORRECT_GUESSES:
            losing_game_message()

def show_game_description():
    print(f"I'm thinking of a word with {len(WINNING_WORD)} letters.") # put the description/directions here
    print(f'You have {MAX_INCORRECT_GUESSES} chances to guess the correct word! ')
    print(f'If you want to exit the program at any time, hit enter.')

def winning_game_message(WINNING_WORD):
    print('')
    print('You\'ve guessed the correct word!')
    print(f'The correct word was {WINNING_WORD}.')
    print('Congratulations!!! 😍🎉🎈')
    draw_happy_man()
    print('')

def losing_game_message():
    print(f'Sorry! You\'ve reached the maximum allowed guesses of {MAX_INCORRECT_GUESSES}.  You lose 😢😭💔')
    print(f'The word I was thinking of was: {WINNING_WORD}')
    print('')

def draw_hangman_game(incorrect_guesses):
    if incorrect_guesses == 0:
        print('   ____')
        print('  |    |')
        print('       |')
        print('       |')
        print('       |')
        print('   ____|____')
    elif incorrect_guesses == 1:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print('       |')
        print('       |')
        print('   ____|____')
    elif incorrect_guesses == 2:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print('  |    |')
        print('       |')
        print('   ____|____')
    elif incorrect_guesses == 3:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print(' /|    |')
        print('       |')
        print('   ____|____')
    elif incorrect_guesses == 4:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print(' /|\   |')
        print('       |')
        print('   ____|____')
    elif incorrect_guesses == 5:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print(' /|\   |')
        print(' /     |')
        print('   ____|____')
    elif incorrect_guesses == 6:
        print('   ____')
        print('  |    |')
        print('  O    |')
        print(' /|\   |')
        print(' / \   |')
        print('   ____|____')

def draw_happy_man():
        print(' \O/ ')
        print('  |  ')
        print(' / \ ')

# Correct word to win the game
# I put this at the end to hide the winning word
WINNING_WORDS = [
                'lightsaber', 'starwars', 'yoda', 'jedi', 'sith', 'stormtrooper', 'deathstar', 'cantina', \
                'moff', 'padawan', 'droid', 'darksaber', 'grievous', 'destroyer', 'padme', 'spaceship', \
                'tatooine', 'chewbacca', 'skywalker', 'vader', 'republic', 'force', 'galaxy', 'empire', \
                'darkside', 'clones', 'falcon', 'ewok', 'wookie'
                 ]
WINNING_WORD = random.choice(WINNING_WORDS)

if __name__=='__main__':
    main()
