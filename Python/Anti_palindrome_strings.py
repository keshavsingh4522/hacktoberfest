for _ in range(int(input())):
    s = input()
    
    if(s==s[::-1]):
        print(-1)
    else:
        print(''.join(sorted(s)))