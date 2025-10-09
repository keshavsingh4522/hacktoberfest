from bs4 import BeautifulSoup  #Importing the Beautiful Soup Library
import requests				   #Importing the requests library
import time					   #Importing the time library
import csv					   #Importing the csv module

response = requests.get('https://www.imdb.com/chart/top')
soup = BeautifulSoup(response.text, 'lxml')
srank, sname, syear, srating, slink, sdirector = list(), list(), list(), list(), list(), list()
column = soup.find_all(class_='titleColumn')
rating = soup.find_all('strong')
link = soup.find_all('a')
for i in column:
	srank.append(i.get_text().strip().split('\n')[0].rstrip('.'))
	sname.append(i.get_text().strip().split('\n')[1].lstrip())   
	syear.append(i.get_text().strip().split('\n')[2].strip('()'))
for i in rating[4:]:
	srating.append(i.get_text().strip())
for i in link[77:577:2]:
	slink.append('https://www.imdb.com' + i.get('href'))
for i in slink:
    response = requests.get(i)
    soup1 = BeautifulSoup(response.text, 'lxml')
    link1 = soup1.find_all('a')
    sdirector.append(link1[120].get_text())
with open('imdb.csv','w',encoding="utf-8", newline = '') as csvfile:
	writer = csv.writer(csvfile)
	writer.writerow(['Rank', 'Name', 'Year', 'Rating', 'Link', 'Director'])
	for a,b,c,d,e,f in zip(srank, sname, syear, srating, slink, sdirector):
		writer.writerow([a.strip(), b.strip(), c.strip(), d.strip(), e.strip(), f.strip()])
