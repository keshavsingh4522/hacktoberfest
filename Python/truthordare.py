import numpy as np


# def EnterNames(n):
# 	list_of_players = []
# 	for i in range(n):
# 		naam = input("Enter Player " + str(i+1) + " name: ")
# 		list_of_players.append(naam)
# 	return list_of_players	





def EnterPlayer():
	playersk = list(input("Enter Players names with spaces: ").split(' '))
	return playersk



def truth_or_dare(listy):
	catch = np.random.choice(listy, size=1, replace=True)
	print(catch)



if __name__ == '__main__':
	# no = int(input("Enter Number of Players: "))
	# ls = EnterNames(no)

	# sinema = []
	# for i in range(100):
	# 	sinema.append(truth_or_dare(['maverick','vikki','abhi', 'anu', 'shikari', 'ankit', 'amri']))

	skl = EnterPlayer()
	while True:
		e = int(input("Enter any integer except 0 : "))
		if e != 0:
			truth_or_dare(skl)
		else:
			pass

		# print(skl)


