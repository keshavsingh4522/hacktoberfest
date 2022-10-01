def GetLoginfo():
    creds=open('creds.txt','r')
    username=creds.read()
    creds.close()
    access=open('access.txt','r')
    password=list(access.read())
    pw=password[10:(len(password)-1)]
    password=''
    for i in pw:
        password+=i
    access.close()
    return (username,password)

def customError(errornum):
    if errornum==0:
        print('CustomError00-UnexpectedEvent')
