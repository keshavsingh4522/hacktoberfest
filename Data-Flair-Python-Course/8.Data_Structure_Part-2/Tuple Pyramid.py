def pyramid(string,height):
    tup=(string)
    for index in range(1,height+1):
        tup=(tup,index)
        print(tup)
