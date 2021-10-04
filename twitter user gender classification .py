import pandas as pd
import numpy as np
import re
import string
import matplotlib.pyplot as plt
%matplotlib inline  
from collections import Counter
#Opening the dataset
filepath=r"C:\twitter-user-gender-dataset.csv"
df = pd.read_csv (filepath,encoding='latin-1')
#Reading the dataset
df
#Checking the size of the dataset
df.shape
#Getting more information about the dataset
df.info
#Displaying all the columns of the dataset
df.columns
df['gender'].value_counts()
#Eliminating the rows of the category brand and unknown
df=df.loc[df['gender'].isin(['female','male'])]

#Q1) What are the most common emotions/words used by Males and Females?

def cleaning(s):
    '''
    Definition of function for data exploration for the text amd description.
    The cleaning function cleans the text and description to form a list of suitable words 
    
    Arguments:
    s:'passing the string to be cleaned'
    
    Returns:
    s
   '''
    #Removing unnecessary words and symbols    
    s = str(s)
    s = s.lower()
    s = re.sub('\s\W',' ',s)
    s = re.sub('\W,\s',' ',s)
    s = re.sub(r'[^\w]', ' ', s)
    s = re.sub("\d+", "", s)
    s = re.sub('\s+',' ',s)
    s = re.sub('[!@#$_]', '', s)
    s = s.replace("co","")
    s = s.replace("https","")
    s = s.replace(",","")
    s = s.replace("[\w*"," ")
    return s

df['Tweets'] = [cleaning(s) for s in df['text']]
df['Description'] = [cleaning(s) for s in df['description']]

from nltk.corpus import stopwords
stop = set(stopwords.words('english'))
#Removing the stopwords
df['Tweets'] = df['Tweets'].str.lower().str.split()
df['Tweets'] = df['Tweets'].apply(lambda x : [item for item in x if item not in stop])
Male = df[df['gender'] == 'male']
Female = df[df['gender'] == 'female']
#Defining the series Male_Words and Female_Words from the new coloumn Tweets formd by cleaing the text 
Male_Words = pd.Series(' '.join(Male['Tweets'].astype(str)).lower().split(" ")).value_counts()[:20]
Female_Words = pd.Series(' '.join(Female['Tweets'].astype(str)).lower().split(" ")).value_counts()[:20]
#Printing the commonly used words by females and their count
Female_Words
#Representing the data with the help of a graph
Female_Words.plot(kind='bar',stacked=True, colormap='plasma')
#Printing the commonly used words by males and their count
Male_Words
#Representing the data with the help of a graph
Male_Words.plot(kind='bar',stacked=True, colormap='plasma')

#Q2) How significant are the colors used by the users in classifying gender?

#This function is to visualize the most used colors by each gender in their profile

def explore_color_feature(info, feature):
    '''
    Definition of function for data exploration for the colors.
    The explore_color_feature function plots the most used colors by gender as bar graphs.
    
    Arguments:
    feature : 'sidebar_color', 'link_color'
    df: dataset to be visualized.
    
    Returns:
    None
    '''

    #Creating a subset of the gender and color of the feature being visualized
    Color_subset = info.loc[:,['gender', feature]]

    #Splitting the dataset w.r.t. 'gender' 
    Color_subset_male = Color_subset[Color_subset['gender'] == 'male']
    Color_subset_female = Color_subset[Color_subset['gender'] == 'female']

    #List of all colors and number of users for each gender
    colors_list_male = list(Color_subset_male[feature].values.flatten())
    colors_list_female = list(Color_subset_female[feature].values.flatten())

    #20 Most common colors used by each gender 
    nCommon = 20
    top_colors_female = [x[0] for x in Counter(colors_list_female).most_common(nCommon)]
    top_colors_male = [x[0] for x in Counter(colors_list_male).most_common(nCommon)]

    #Number of profiles using the each color in the 30 most common colors
    top_colors_users_female = [x[1] for x in Counter(colors_list_female).most_common(nCommon)]
    top_colors_users_male = [x[1] for x in Counter(colors_list_male).most_common(nCommon)]

    #Deriving the hexadecimal value to represent each color in the graph
    top_colors_female_hex = ['#' + x + '000000' for x in top_colors_female]
    top_colors_female_hex = [x[0:7] for x in top_colors_female_hex]
    top_colors_male_hex = ['#' + x + '000000' for x in top_colors_male]
    top_colors_male_hex = [x[0:7] for x in top_colors_male_hex]

    #Range of colors for each gender
    color_range_female = list(range(len(top_colors_female)))
    color_range_male = list(range(len(top_colors_male)))

    #Color usage plot for female profiles
    fig1, ax1 = plt.subplots()

    bar_width = 0.5
    rects1 = plt.barh(color_range_female, top_colors_users_female, bar_width, label = 'Female', color = top_colors_female_hex)
    plt.yticks(color_range_female, top_colors_female_hex)
    plt.xlabel('Color')
    plt.ylabel(feature)
    plt.title('Most used colors by Females for ' + feature)
    plt.tight_layout()
    plt.show()

    #Color usage plot for male profiles
    fig2, ax2 = plt.subplots()

    bar_width = 0.5
    rects1 = plt.barh(color_range_male, top_colors_users_male, bar_width, label = 'Male', color = top_colors_male_hex)
    plt.yticks(color_range_male, top_colors_male_hex)
    plt.xlabel('Color')
    plt.ylabel(feature)
    plt.title('Most used colors by Males for ' + feature)
    plt.tight_layout()
    plt.show()
    #Data exploration for color features

#Removing weird values from color
df = df.loc[(df['sidebar_color']).str.contains('E\+') != True]
df = df.loc[(df['link_color']).str.contains('E\+') != True]

#Plot for the most used 'sidebar_colors'
explore_color_feature(df, 'sidebar_color')

#Plot for the most used 'link_colors'
explore_color_feature(df, 'link_color')

from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.preprocessing import LabelEncoder#choosing text and description as independent variables and concatinating it to form all_features
df['all_features']=df['text'].str.cat(df['description'],sep=' ')
df=df[df.all_features.notnull()]
#Spliting the data into testing and training sets
vectorizer=CountVectorizer()
x=vectorizer.fit_transform(df['all_features'])
le=LabelEncoder()
y=le.fit_transform(df['gender'])
x_train,x_test,y_train,y_test=train_test_split(x,y)

#MULTINOMIAL NAIVE BAYES

from sklearn.naive_bayes import MultinomialNB
nb=MultinomialNB()
#Fitting the training set into the model
nb.fit(x_train,y_train)
#Predicting the score
nb.score(x_test,y_test)
#Cross validating the score
score=cross_val_score(nb,x,y,cv=5)
score
#Printing the avg score
score.mean()

#LOGISTIC REGRESSION

from sklearn.linear_model import LogisticRegression
LogReg = LogisticRegression()
#Fitting the training set into the model
LogReg.fit(x_train,y_train)
#Predicting the score
LogReg.score(x_test,y_test)
#Cross validating the score
score=cross_val_score(LogReg,x,y,cv=5)
score
#Printing the avg score
score.mean()

#K NEAREST NEIGHBOR

from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier()
#Fitting the training set into the model
knn.fit(x_train, y_train)
#Predicting the score
knn.score(x_test,y_test)
#Predicting the score
knn.score(x_test,y_test)
#Printing the avg score
score.mean()
