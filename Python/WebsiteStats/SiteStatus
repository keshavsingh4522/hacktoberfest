import requests




def main():

    siteName = input("Kero..What website would you like to check the status of?")
    siteReq = requests.get(siteName)
    statusCode = siteReq.status_code
    if statusCode == requests.codes.ok:
        print("Website is up")
    else:
        print(statusCode, "website is down")








if __name__ == "__main__":
    main()
