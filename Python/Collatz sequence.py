# -*- coding: utf-8 -*-
"""
Created on Fri Jul 30 20:59:34 2021

@author: Debshishu Ghosh
"""

import matplotlib.pyplot as plt
x = int(input('Enter The starting digit for the sequence: '))
collatz = []

collatz.append(x)
while(x!=1):
    if(x%2 == 0):
        x = x/2
        collatz.append(x)
    else:
        x = x*3 + 1
        collatz.append(x)
        
collatz.append(1)
x = list(range(len(collatz)))
print('Length of the sequence formed is: '+ str(len(collatz)))

plt.plot(x, collatz)
plt.scatter(x, collatz, s = 15)
plt.show()
        
        
    
    
