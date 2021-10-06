def game_of_tuples():
    s=input("Enter a string of numbers separated with spaces")
    return tuple([int(item) for item in s.split(' ')])
