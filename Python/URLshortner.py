import pyshorteners
link=input("Enter The Link: ")
shortener=pyshorteners.Shortener()
x =shortener.tinyurl.short(link)
print(x)
