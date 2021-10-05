import pandas as pd 
import numpy as np 
import functools


dataframe = pd.read_excel("recru.xlsx",engine="openpyxl", dtype=str)
dataframe.dropna(subset = ["Grade"], inplace=True)

def filtre(data)-> bool :
    keywords = ["master","ing","ingénieurie","ingénieur","ingenieur","idl","iseoc","idisc","engineer","engineering"]
    for key in keywords:
        if key in data.lower():
            return True 
    return False 


l = list(filter(filtre,dataframe['Grade'].values))
new_sheet = pd.DataFrame(columns=[x for x in dataframe.columns.values])

for index,row in dataframe.iterrows():
    if row['Grade'] in l:
        r = {}
        r = dict(zip(new_sheet.columns.values,row))
        new_sheet = new_sheet.append(r,ignore_index=True)

new_sheet.to_excel("clean.xlsx")  
