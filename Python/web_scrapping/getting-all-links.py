"""
 Install and include the beautiful soup library with the name bs4 in the same folder as this code in order for it to run.
"""


from urllib.request import urlopen
from bs4 import BeautifulSoup
import ssl

ctx=ssl.create_default_context ()
ctx.check_hostname=False
ctx.verify_mode=ssl.CERT_NONE

url=input('Enter URL:  ')
print("Retrieving:",url)

html=urlopen(url,context=ctx).read()
soup=BeautifulSoup(html,"html.parser")
tags=soup('a')
for tag in tags:
    print(tag.get('href',None))
