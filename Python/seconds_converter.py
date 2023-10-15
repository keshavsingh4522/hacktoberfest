# Python Program to Convert seconds
# into hours, minutes and seconds
  
def convert(seconds):
    seconds = seconds % (24 * 3600)
    hour = seconds // 3600
    seconds %= 3600
    minutes = seconds // 60
    seconds %= 60
      
    return "%d:%02d:%02d" % (hour, minutes, seconds)
      
# Driver program
n = input('Enter the seconds to ocnvers to hours and minutes: ')
print(convert(n))