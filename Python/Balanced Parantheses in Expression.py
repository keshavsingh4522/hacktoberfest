'''
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.
Input:
{[()]}
Output:
1
'''
def isBalanced(s):
        stk=[]
        top=-1
        for i in range(len(s)):
            if(s[i]=='(' or s[i]=='{' or s[i]=='['):
                stk.append(s[i])
                top+=1
                continue
            if(s[i]==')' or s[i]=='}' or s[i]==']'):
                if top==-1:
                    return 0
                ele=stk.pop()
                top-=1
                if(ele=='(' and s[i]!=')') or (ele=='{' and s[i]!='}') or (ele=='[' and s[i]!=']'):
                    return 0
                else:
                    continue
        if top>-1:
            return 0
        else:
            return 1

s=input()
print(isBalanced(s))
