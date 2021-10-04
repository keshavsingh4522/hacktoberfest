##find the class and network address of a given IP address
x=input("Enter IP:")
ip=x.split(".")
m=int(ip[0])
if m>=1 and m<128:
    print("Class A")
    print("Network address: "+ ip[0] + ".0.0.0")
elif m>=128 and m<192:
    print("Class B")
    print("Network address: "+ ip[0] + "."+ip[1]+ ".0.0")
elif m>=192 and m<224:
    print("Class C")
    print("Network address: "+ ip[0] + "."+ip[1]+"." +ip[2]+ ".0")
elif m>=224 and m<240:
    print("Class D")
else:
    print("Class E")
