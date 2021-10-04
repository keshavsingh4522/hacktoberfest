# Number Guessing Game

# importing module
import random
import pyttsx3 as pyt

engine = pyt.init()
newVoiceRate = 125
eng_voice = 'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_DAVID_11.0'

engine.setProperty('voice', eng_voice)
engine.setProperty('rate', newVoiceRate)

pyt.speak('Welcome to Number Guessing Game')
engine.runAndWait()
pyt.speak('Enter Number of Chances')
chance = int(input("Total Chances --> "))

try_again = 'yes'
while try_again == 'yes':
    rand_num = random.randint(1, 10)
    pyt.speak("Enter Number between 1 to 10")
    counting = 0
    while counting < chance:
        if counting == chance-1:
            pyt.speak("It's your last chance")
        else:
            pyt.speak(f"It's Your Chance {counting + 1}")
        num = int(input('-->'))

        if counting == chance-1 and num != rand_num:
            pyt.speak('Sorry! your chance is finished ... and You loss the game')
            print('You Loss')
            pyt.speak(f"Correct number is : {rand_num}")
            break

        elif num == rand_num:
            pyt.speak("Nice trial You won the game")
            print('You Won')
            break

        elif num > rand_num:
            pyt.speak("Give some smaller number")

        elif num < rand_num:
            pyt.speak("Give some greater number")

        counting += 1

    pyt.speak("Do you want to Play again?")
    try_again = input("Want to Play again?? (yes or no) : ")
    if try_again == 'yes':
        pyt.speak('Welcome again in Number Guessing Game')
    else:
        pyt.speak('Thank You for Playing Number Guessing Game ... Come Soon')