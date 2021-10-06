def battle_of_numbers(numbers):
	winner=numbers[0]
	for num in numbers:
		if num>winner: winner=num
	return winner
