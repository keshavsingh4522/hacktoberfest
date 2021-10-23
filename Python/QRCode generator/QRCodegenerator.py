#FOLLOW THE STEPS BELOW TO GENERATOR YOUR QRCODE IN PYTHON BY USING Pyqrcode library 

#install the library  by ! pip install pyqrocde

#importing the library 
import pyqrcode
from pyqrcode import QRCode 

#give the url of any thing you want to generator qrcode from it .Forexample website

value=input("\nEnter your url\n")

s=value
#calling the create function from pyqrcode to create QRCode 
url=pyqrcode.create(s)

#Then exporting the url to either png,gif,or svg 

url.png("myurl.png",scale=5)

print(url)




