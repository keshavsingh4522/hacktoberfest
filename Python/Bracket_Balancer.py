# balanced parentheses in an expression
ol = ["[","{","("]
cl = ["]","}",")"]
  
# Function to check parentheses
def check(myStr):
    st = []
    for i in myStr:
        if i in ol:
            st.append(i)
        elif i in cl:
            pos = cl.index(i)
            if ((len(st) > 0) and
                (ol[pos] == st[len(st)-1])):
                st.pop()
            else:
                return "Unbalanced"
    if len(st) == 0:
        return "Balanced"
    else:
        return "Unbalanced"
  
  
STR = "{[]{()}}"
print(STR,"-", check(STR))
  
STR = "[{}{})(]"
print(STR,"-", check(STR))
