import pandas as pd
import quandl, math, datetime, pickle
import numpy as np
from sklearn import preprocessing, svm, model_selection
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt 
from matplotlib import style

style.use('ggplot')

df = quandl.get('WIKI/GOOGL', api_key = 'CY5Qf9SQBhWzxfb1EGYN') 


df = df[['Adj. Open','Adj. High','Adj. Low','Adj. Close','Adj. Volume']]

df['HL_Percnt'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100
df['Percnt_Chnge'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Close'] * 100

df = df[['Adj. Close', 'HL_Percnt', 'Percnt_Chnge', 'Adj. Volume']]

df.fillna(-9999, inplace=True)

forcast_col = 'Adj. Close'

forcast_out = int(math.ceil(0.01 * len(df)))
print(forcast_out, "Days In Future")

df['label'] = df[forcast_col].shift(-forcast_out)

df.dropna(inplace=True)

x = np.array(df.drop(['label'], 1))
y = np.array(df['label'])
x = preprocessing.scale(x)

X_lately = x[-forcast_out:]
x = x[:-forcast_out]

xTrain, xTest, yTrain, yTest = model_selection.train_test_split(x, y, test_size = 0.8)

classifier = LinearRegression()

with open('pickle Files\GooglStock.pikle', 'wb') as clsPikle:
    pickle.dump(classifier, clsPikle)

pickle_in = open('GooglStock.pikle', 'rb')
classifier = pickle.load(pickle_in)

classifier.fit(xTrain, yTrain)
accuracy = classifier.score(xTrain, yTrain)
print('Accuracy is : ', accuracy)

forcastSet = classifier.predict(X_lately)

print(forcastSet)

df['forcast'] = np.nan

lastDay = df.iloc[-1].name
lastUnix = lastDay.timestamp()
oneDay = 86400
nextUnix = lastUnix + oneDay

for forcastValue in forcastSet:
    nextDate = datetime.datetime.timestamp(nextUnix)
    df.loc[nextDate] = [np.nan for _ in range(len(df.columns)-1)] + [forcastValue]

df['Adj Close'].plot()
df['forcast'].plot()
plt.legend(loc = 4)
plt.xlabel('Date')
plt.ylabel('Price')
plt.show()