help = input('>')
while help != " " :
    if help.upper() == "HELP":
        request = input(f'start - to start the car \n'
                    f'stop - to stop the car \n'
                    f'quit - to exit \n')
        if request.upper() == "START":
             print("Car started...Ready to go!")
        elif request.upper() == "STOP":
            print("Car Stopped!!")
        elif request.upper() == "QUIT":
            print("Exitng from the car")
            break
    else:
        print("Sorry I don't understand that....")
else:
    print("I did'nt get it sir!!")
