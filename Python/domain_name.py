# write a function that can extract the host name from a URL
# Host name is the part of the URL that comes after the http:// , 
# and before the next /.

import re
def getHostName(url):
    regex = "\w+\.\w+.\w\w\w"
    host = re.findall(regex,url)
    return(host[0])
    
def main():
    url_testA = "http://www.cnn.com"
    url_testB = "https://hacktoberfest.digitalocean.com/profile"
    
    print(getHostName( url_testA))
    print(getHostName( url_testB))
   
   
main()
   
   
	
