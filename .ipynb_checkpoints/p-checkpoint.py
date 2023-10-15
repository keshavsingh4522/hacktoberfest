# writing data in p.csv file
f=open('CONTRIBUTERS.md','r')
f1=open('p.csv','w')
f1.write('Name,Github\n')
f.readline()
f.readline()
# f1.write("{'CONTRIBUTERS-DETAILS':[")
d=dict()
for i in f:
    i=i.split('|')
    name=i[1].strip()
    username=i[2].split('[@')[1].split(']')[0].strip()
    f1.write(name+','+username+'\n')
#     d[username]=name
#     print()
# f1.write("]}")
f.close()
f1.close()

# printing code
import pandas as pd
df=pd.read_csv('p.csv')
df=df.sort_values('Name')
df.to_csv('CONTRIBUTERS.csv')
print("<table>\n<tr>")
c=0
for i,j in zip(df['Name'],df['Github']):
    if c==6:
        print('\n</tr>\n<tr>')
        c=0
    c+=1
    html='''<td align="center"><a href="https://github.com/{0}"><img src="https://avatars3.githubusercontent.com/{0}?size=400" width="100px;" alt=""/><br /><sub><b>{1}</b></sub></a><br /><a href="https://github.com/keshavsingh4522/hacktoberfest2020/commits?author={0}" title="Code">💻</a></td>'''.format(j,i)
    print(html) #.encode('utf8')
#     with open('p.txt', "w", encoding="utf-8") as f:
#         f.write(html)
#     print(i,j)
print('</tr>')
print('</table>')