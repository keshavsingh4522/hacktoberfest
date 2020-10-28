# start saving data in CONTRIBUTERS.md file
f=open('CONTRIBUTERS.md','r')
f1=open('CONTRIBUTERS.csv','w')
f1.write('Name,Github,Starred repo\n')

f.readline()
f.readline()
for i in f:
    i=i.split('|')
    name=i[1].strip()
    username=i[2].split('[@')[1].split(']')[0].strip()
    starred_repo=i[3].strip()
    f1.write(name+','+username+','+starred_repo+'\n')
f.close()
f1.close()
# End of data saved in CONTRIBUTERS.md file 

import pandas as pd
df=pd.read_csv('CONTRIBUTERS.csv')

# user who starred the repo
df1=df[df['Starred repo']==1]
df1=df1.sort_values('Name')

# user who doesnot starred the repo
df2=df[df['Starred repo']==0]
df2=df2.sort_values('Name')


# merging both in one dataframe and storred in CONTRIBUTERS.csv file
df = pd.concat([df1, df2], axis=0, sort=False)
df.to_csv('CONTRIBUTERS.csv')


# start coding for saving the code in file
f=open('result.md','w')
f.write('<table>\n<tr>')
c=0
for i,j,k in zip(df['Name'],df['Github'],df['Starred repo']):
    if c==6:
        f.write('</tr>\n<tr>')
        c=0
    c+=1
    if k!=1:
        html='''<td align="center"><a href="https://github.com/{0}"><img src="https://avatars3.githubusercontent.com/{0}?size=400" width="100px;" alt=""/><br /><sub><b>{1}</b></sub></a><br /><a href="https://github.com/keshavsingh4522/hacktoberfest2020/commits?author={0}" title="Code"> :computer: </a> '''.format(j,i)
    else:
        html='''<td align="center"><a href="https://github.com/{0}"><kbd><img src="https://avatars3.githubusercontent.com/{0}?size=400" width="100px;" alt=""/></kbd><br /><sub><b>{1}</b></sub></a><br /><a href="https://github.com/keshavsingh4522/hacktoberfest2020/commits?author={0}" title="Code"> :computer: </a> '''.format(j,i)
    f.write(html)
    '''
    # if k==1:
    #     star_a="<a href='https://github.com/keshavsingh4522/hacktoberfest2020/stargazers' title='starred the repo'> :star2: </a> "        
    #     f.write(star_a+'</td>\n')
    # else:
    '''
    f.write('</td>\n')
f.write('</tr>')
f.write('</table>')
f.close()
# End coding for saving the code in file