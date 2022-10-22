'''
r is the breadth of the graphic
c is the length of the graphic

'''
def welcome_graphic(r,c):
  l=[]
  for i in range(1,r//2 + 1):
    s = (".|."*(2*i-1)).center(c,"-")
    print(s)
    l.append(s)       
  print("WELCOME".center(c,"-"))
  print(*reversed(l) , sep="\n")
 

welcome_graphic(7,21)
