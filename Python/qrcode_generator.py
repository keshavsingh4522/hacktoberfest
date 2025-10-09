import qrcode
def convert(url):
    if url.startswith('http://'):
        return 'http://' + url[len('http://www.'):]
    if url.startswith('www.'):
        return 'https://' + url[len('www.'):]
    if not url.startswith('https://'):
        return 'https://www.' + url+".com"
    return url 
url=input("Enter a website name/url: ")
print(convert(url))
img=qrcode.make(url)
img.save("Qrcode.png","PNG")  
print("Qrcode generated")
