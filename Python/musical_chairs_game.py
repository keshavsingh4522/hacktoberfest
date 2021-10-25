from pygame import mixer
import time
import random

# Asking how many people are present.
number_of_people = int(input("Enter the number of people present."))

# Starting the mixer
mixer.init()

# Loading the song
mixer.music.load("song.mp3")

# Setting the volume
mixer.music.set_volume(0.3)

# Start playing the song
mixer.music.play()


i = 0
# Loop running no. of people present
while i < number_of_people:
	# Waiting For Some Time Randomly
	timeToWait = random.randint(1,100)
	time.sleep(timeToWait)
	# Pausing the music
	mixer.music.pause()	
	# Waiting for Three minutes for physical activities
	time.sleep(5)
	# Resuming the music
	mixer.music.unpause()
	i+=1
