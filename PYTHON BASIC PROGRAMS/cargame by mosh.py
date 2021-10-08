command = ""
started = False

while True:
    command = input("> ").lower()
    if command == "start":
        if started :
            print("Car is already Started !!")
        else:
            started = True
            print("The Car started...")
    elif command == "stop":

        if not started:
            print("Car is already Stopped!!!")
        else:
            started = False
            print("car  stopped!!")

    elif command == "help":
        print("""
start - to start the car
stop - to stop the car
quit - to quit
        """)
    elif command == "quit":
        break
    else:
        print("Sorry sir don't understand thatf!!")