# Toll Gate System using 

[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](#)


### Table of Contents  
[1 -  Features of this Application ](#head1)  

[2 - How to Install](#head2)

[3 - User Guidelines](#head3) 

[4 - Java as Technology for this Software](#head4)  

[5 - Development](#head5)  

[6 - Folders and Description details ](#head6)  
  



<a name="head1"/></a>
## 1 - Features of this Application 


![alt text](https://github.com/raizengxd/TollGateJava/blob/master/Image_file.PNG)


1. It has step by step label in order for user to guide them in using it 
2. It has information section to know their Class Vehicles and their Data as well 
3. It has color buttons in order to know what they will press

*NOTE: Human eye treats the Green as active or success, while color yellow is for medium or reset while color red is warning the UI developer intend this color category for the users who has eye defect wherein it is hard for them to read texts*


<a name="head2"></a>
## 2 - How to install 
Just download the jar file and you can use it :>

<a href="https://github.com/raizengxd/TollGateJava/blob/master/Toll%20Gate%20System.jar">DOWNLOAD HERE</a>

*make sure that you have Java Machine in your device *

<a name="head3"/></a>

## 3 - User Guidelines
1. Users add their name first 
2. Second they will choose what is the classification of their vehicle
3. User can choose the location that they want

*If the user has innapporiate action the system or the program will warning them* 





<a name="head4"/></a>
## 4 - Java as Technology for this Software 


 
### 4.1 - GUI 

We integrate GUI (Graphical User Interface) to make it accesible and easy to use for the user of this software with the study of research in UI and UX we come up with the easy to use buttons, lessen the hassle of reading information plus the integration of user friendly experience 

### 4.2 Memory 
Through the help of the Java Collection HashMap we come up with the fast memory and speed. The data are optimized and easy to use. The Data are access through their keys and not indexes. The memory and speed of this software is fast and reliable through the power of HashMap 


### 4.3 Easy to edit 
Java is a beginner friendly programming language that everyone can code it too. So that's why this is a open source software that can help to improve it to make it more user friendly and fast
 
 
<a name="head5"/></a> 
## 5 - DEVELOPMENT 
### 5.1 - HashMap
HashMap is a Map based collection class that is used for storing Key & value pairs, it is denoted as HashMap<Key, Value> or HashMap<K, V>. This class makes no guarantees as to the order of the map. It is similar to the Hashtable class except that it is unsynchronized and permits nulls(null values and null key).

```

import java.util.HashMap;

HashMap hash = new HashMap();
hash.put("MIN-BWK",165.0);
```
### 5.2 Java Swing 
Swing is a GUI widget toolkit for Java. It is part of Oracle's Java Foundation Classes – an API for providing a graphical user interface for Java programs. Swing was developed to provide a more sophisticated set of GUI components than the earlier Abstract Window Toolkit

### 5.3 Python Integration for hashes 

Using XLRD to read the excel file 

Instead of using array we use hashes to make it fast and optimized 

**PROBLEM**: It is time consuming to type all those data one by one so we come up to generate it with excel to python plus write it with 

```
hash.put("MIN-BWK",165.0);

```

```
import xlrd


f = open("C:\\Users\\MY-PC\\Desktop\\TollGateJava\\tbl_Class3.txt", "w")
wb = xlrd.open_workbook('D:\\New folder\\Book1.xlsx')
sh = wb.sheet_by_index(2) 
x=len(sh.col_values(0))-1
y = len(sh.row_values(0))-1
for i in range(x):
    lenx= len(list(filter(None,sh.row_values(i+1) )))
    for j in range(lenx-1):
        start = sh.cell(i+1,0).value
        destination = sh.cell(0,j+1).value
        value_Price = sh.row_values(i+1)
        
        f.write("hash.put("+"\""+start+"-"+destination+"\""+','+str(value_Price[j+1])+");\n")
f.close()

```

## 6 - Folders and Description

### 6.1 Source code 
<a href = "https://github.com/raizengxd/TollGateJava/tree/master/Source%20Code/JavaApplication3"> All Java Files  </a>


<a href="https://github.com/raizengxd/TollGateJava/tree/master/Source%20Code/JavaApplication3/src/javaapplication3" > Java Main Files for editing </a>

### 6.2 Python Generated App 
<a href ="https://github.com/raizengxd/TollGateJava/tree/master/Excel%20to%20Python%20Hash%20Writer"> Python Files </a>


*It contains Excel files, Text output and the Python generator*

### 6.3 Java Excess Files for Old Reference 

This contain the files that have been created but they are meant only for references 


