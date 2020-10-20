import quandl
import pandas as pd
import matplotlib.pyplot as plt

#Stock Price starts from 2012 and ends at 2017 stock price
start_date = pd.to_datetime("2012-01-01")
end_date = pd.to_datetime("2017-01-01")

#Getting Apple,cisco,ibm,amazon Stock Price
aapl = quandl.get("WIKI/AAPL.11",start_date=start_date,end_date=end_date)
cisco = quandl.get("WIKI/CSCO.11",start_date=start_date,end_date=end_date)
ibm = quandl.get("WIKI/AAPL.11",start_date=start_date,end_date=end_date)
amzn = quandl.get("WIKI/AMZN.11",start_date=start_date,end_date=end_date)

#Getting input from user on how much they want to allocate to the 4 stocks for diversified portfolio
inputstring = input("Enter How much You want to allocate in the 4 stocks [Apple,Cisco,IBM,Amazon] ex. .3,.4,.2,.1")
ins = list(map(float,inputstring.split(',')))

#Creating a new coloumn for Normalized Return i.e how much they have earned from the beginning
for stock in (aapl,cisco,ibm,amzn):
    stock['Normed Return']=stock['Adj. Close']/stock.iloc[0]['Adj. Close']

#Creating a new coloumn of the total allocated stocks they have
for stock,aloc in zip((aapl,cisco,ibm,amzn),ins):
    stock['Allocation']=stock['Normed Return']*aloc

#Getting input from the user on how much they want to invest in diversified portfolio
money = int(input("How Much Inital Total Money you want to invest in the diversified portfolio"))

#Creating a new coloumn for the total Pos. Or total money they have in that stock
for stock in (aapl,cisco,ibm,amzn):
    stock['Total Pos']=stock['Allocation']*money

#Creating a new dataframe with all the total pos.
everything = [aapl['Total Pos'],cisco['Total Pos'],ibm['Total Pos'],amzn['Total Pos']]
portfolio_val = pd.concat(everything,axis=1)
portfolio_val.columns=['Apple Pos.','Cisco Pos.','IBM Pos.','Amazon Pos.']
portfolio_val['Total Pos.']=portfolio_val.sum(axis=1)

#Plotting All Portfolio stock Positions
portfolio_val.plot(figsize=(10,8))
plt.title("All Portfolio Pos.")
plt.show()

#Plotting Total Portfolio stock Positions
portfolio_val['Total Pos.'].plot(figsize=(10,8))
plt.title("Total Portfolio Pos.")
plt.show()