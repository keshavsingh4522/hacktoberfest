secret_number = 9
Guess_count=0
Guess_limit =3
while Guess_count< Guess_limit:
    Guess = input("Guess: ")
    if int(Guess) == secret_number:
        print("Hurreyy..You Win!!")
        break
    #if Guess_count == 2:
     #   print("Sorry you failed!")
    Guess_count = Guess_count + 1
else:
    print("Sorry you failed!")