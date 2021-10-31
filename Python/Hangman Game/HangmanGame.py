#############################################
#######THIS IS THE HANGMAN GAME PROJECT########
############# BY SHOURYA PANT ################
############################################ 
import pygame
import random
import os

pygame.init()
winHeight = 1000
winWidth = 1000
win=pygame.display.set_mode((winWidth,winHeight))
pygame.display.set_caption("Hangman Game!")

##################################################
### Initializing The COLOURS that will be used in the PROJECT###
##################################################

BLACK = (0,0, 0)
WHITE = (255,255,255)
RED = (255,0, 0)
GREEN = (50,205,50)
BLUE = (0,0,255)
LIGHT_BLUE = (51,161,201)
PURPLE=(150,0,211)
ORANGE=(255,69,0)
MAGENTA=(220,25,60)
YELLOW=(255,215,0)
RANDOMCOLOUR=(255,20,147)

##############################################################
#### Initializing The FONTS AND VARIABLES that will be used in the PROJECT####
##############################################################

btn_font = pygame.font.SysFont("Algerian", 30)
guess_font = pygame.font.SysFont("Permanentmarker", 40)
lost_font = pygame.font.SysFont('Ravie', 24)
word_font=pygame.font.SysFont('Jokerman', 30)
TITLE_FONT=pygame.font.SysFont('Permanentmarker',40)
word = ''
buttons = []
guessed = []
hangmanPics = [pygame.image.load(('resources/hangman0.png')), pygame.image.load('resources/hangman1.png'), pygame.image.load('resources/hangman2.png'), pygame.image.load('resources/hangman3.png'), pygame.image.load('resources/hangman4.png'), pygame.image.load('resources/hangman5.png'), pygame.image.load('resources/hangman6.png')]

limbs = 0

#################################################################################
## DEFINING THE REDRAW GAME WINDOW FUNCTION THAT WILL PLAY A MAIN ROLE IN OUR PROJECT ##
#################################################################################

def redraw_game_window():
    global guessed
    global hangmanPics
    global limbs
    win.fill(LIGHT_BLUE)
    text = TITLE_FONT.render("HANGMAN BY SHOURYA PANT", 1, YELLOW)
    win.blit(text, (winWidth/2 - text.get_width()/2, 480))
    # Buttons
    for i in range(len(buttons)):
        if buttons[i][4]:
            pygame.draw.circle(win, BLACK, (buttons[i][1], buttons[i][2]), buttons[i][3])
            pygame.draw.circle(win, buttons[i][0], (buttons[i][1], buttons[i][2]), buttons[i][3] - 2)
            label = btn_font.render(chr(buttons[i][5]), 1, BLACK)
            win.blit(label, (buttons[i][1] - (label.get_width() / 2), buttons[i][2] - (label.get_height() / 2)))

    spaced = spacedOut(word, guessed)
    label1 = guess_font.render(spaced, 1, PURPLE)
    rect = label1.get_rect()
    length = rect[2]
    
    win.blit(label1,(winWidth/2 - length/2, 400))

    pic = hangmanPics[limbs]
    win.blit(pic, (winWidth/2 - pic.get_width()/2 + 20, 150))
    pygame.display.update()

###########################################################################
### DEFINING THE RANDOM WORD FUNCTION THAT WILL GENERATE A RANDOMIZED WORD ###
##################### FROM THE GIVEN FILE WORDS.TXT ###########################
##########################################################################

def randomWord():
    file = open('resources/words.txt')
    f = file.readlines()
    i = random.randrange(0, len(f) - 1)

    return f[i][:-1]


def hang(guess):
    global word
    if guess.lower() not in word.lower():
        return True
    else:
        return False


def spacedOut(word, guessed=[]):
    spacedWord = ''
    guessedLetters = guessed
    for x in range(len(word)):
        if word[x] != ' ':
            spacedWord += '_ '
            for i in range(len(guessedLetters)):
                if word[x].upper() == guessedLetters[i]:
                    spacedWord = spacedWord[:-2]
                    spacedWord += word[x].upper() + ' '
        elif word[x] == ' ':
            spacedWord += ' '
    return spacedWord
            

def buttonHit(x, y):
    for i in range(len(buttons)):
        if x < buttons[i][1] + 20 and x > buttons[i][1] - 20:
            if y < buttons[i][2] + 20 and y > buttons[i][2] - 20:
                return buttons[i][5]
    return None

###########################################################################
###############DETERMINING WHETHER THE USER IS WINNER OR LOSER ################
##########################################################################

def end(winner=False):
    global limbs
    lostTxt = 'You Lost, press any key to play again...'
    winTxt = 'WINNER!, press any key to play again...'
    redraw_game_window()
    pygame.time.delay(1000)
    win.fill(GREEN)

    if winner == True:
        label = lost_font.render(winTxt, 1, RANDOMCOLOUR)
    else:
        label = lost_font.render(lostTxt, 1, ORANGE)

    wordTxt = lost_font.render(word.upper(), 1, RED)
    wordWas = word_font.render('The phrase was: ', 1, BLUE)

    win.blit(wordTxt, (winWidth/2 - wordTxt.get_width()/2, 295))
    win.blit(wordWas, (winWidth/2 - wordWas.get_width()/2, 245))
    win.blit(label, (winWidth / 2 - label.get_width() / 2, 140))
    pygame.display.update()
    again = True
    while again:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            if event.type == pygame.KEYDOWN:
                again = False
    reset()


def reset():
    global limbs
    global guessed
    global buttons
    global word
    for i in range(len(buttons)):
        buttons[i][4] = True

    limbs = 0
    guessed = []
    word = randomWord()

###########################################################################
#############ADDING THE ALPHABETS BUTTON IN OUR HANGMAN GAME ################
###########################################################################

increase = round(winWidth / 13)
for i in range(26):
    if i < 13:
        y = 40
        x = 25 + (increase * i)
    else:
        x = 25 + (increase * (i - 13))
        y = 85
    buttons.append([LIGHT_BLUE, x, y, 20, True, 65 + i])

word = randomWord()
inPlay = True

while inPlay:
    redraw_game_window()
    pygame.time.delay(10)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            inPlay = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                inPlay = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            clickPos = pygame.mouse.get_pos()
            letter = buttonHit(clickPos[0], clickPos[1])
            if letter != None:
                guessed.append(chr(letter))
                buttons[letter - 65][4] = False
                if hang(chr(letter)):
                    if limbs != 5:
                        limbs += 1
                    else:
                        end()
                else:
                    print(spacedOut(word, guessed))
                    if spacedOut(word, guessed).count('_') == 0:
                        end(True)

pygame.quit()