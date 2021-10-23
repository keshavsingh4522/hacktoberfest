# Python code for a stopwatch

# importing the time module 
import time

print("Press ENTER to start the stopwatch")
print("and, press CTRL + C to stop the stopwatch")

# infinite loop
while True:
    try:
        input() #For ENTER
        start_time = time.time()
        print("Stopwatch started...")
        
    except KeyboardInterrupt:
        print("Stopwatch stopped...")
        end_time = time.time()
        print("The total time:", round(end_time - start_time, 2),"seconds")
        break # breaking the loop
