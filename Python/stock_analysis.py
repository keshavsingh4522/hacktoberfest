import yfinance as yf

companyName=input("Enter your company name: ")
company=yf.Ticker(companyName)
print("\n Details: \n")
print(company.info)
print("\n Price: \n")
print(company.price)
print("\n History: \n")
print(company.history(period="1mo"))
