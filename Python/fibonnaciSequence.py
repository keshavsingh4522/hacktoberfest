print('-'*30)                                               # Decoration
print(' '*5,'Fibonnaci sequence')                           # Title
print('-'*30)                                               # Decoration
n = int(input('How many terms do you want to show? '))      # Question
t1 = 0                                                      # predefined variables to create the sequence
t2 = 1                                                      # predefined variables to create the sequence
print('-'*30)                                               # Decoration
print('{} → {}'.format(t1, t2), end='')                     # Show t1 and t2
cont = 3                                                    # Variable for the sequence
while cont <= n:                                            # While to create the sequence
    t3 = t1 + t2                                            # Add the last two numbers
    print(' → {}'.format(t3), end='')                       # Show sum result
    t1 = t2                                                 # Change the last numbers
    t2 = t3                                                 # Change the last numbers
    cont+= 1                                                # Add one in variable cont
print(' → END')                                             # Decoration
print('-'*30)                                               # Decoration
