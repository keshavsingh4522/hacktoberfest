def calculate_bmi(height, weight):
    return round(height/(weight**2), 2)

def int_only_input(string):
    while True:
        x = input(string)
        if x.isnumeric():
            return int(x) 
        print('invalid input! try again!')
    
def main():
    while True:
        weight = int_only_input('what is your weight in kg?\n')
        height = int_only_input('what is your height in meters?\n')
        bmi = calculate_bmi(height, weight)
        print(f'{bmi} is your bmi')
        answer = input('do you want to exit? [y/n]')
        if answer.lower() in {'y', 'yes'}:
            break
    print('thank you for using our service!')

if __name__ == '__main__':
    main()

