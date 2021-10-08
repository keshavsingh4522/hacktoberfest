weight = input("Weight: ")
units = input(f'(L)bs or (K)g:')

if units == 'L' or 'l':  # if unit.upper() == "L":
    print( f'you are {int(weight) * 0.45} kilos')
else:
    print(f' You are {int(weight) /0.45} pounds ')



