#!/usr/bin/env python
# coding: utf-8

# In[1]:


import math
import numpy as np
import matplotlib.pyplot as plt
time = np.arange(0,math.pi,0.1)
amp = np.sin(time)
plt.title("Half Sine Wave")
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.plot(time,amp)
plt.show()


# In[2]:


print(amp)
l = str(len(amp))
print("There are "+l+" bits")


# In[10]:


plt.scatter(time,amp)
plt.vlines(time,[0]*32,amp)
plt.title("Sampled Wave")


# In[3]:


quant = 4
ampl = (amp * (2**quant)).astype(int)
print(ampl)


# In[11]:


plt.plot(time,ampl)
plt.scatter(time,ampl)
plt.vlines(time,[0]*32,ampl)


# In[5]:


for i in range (32):
    b = ampl[i]
    n = bin(b)
    n = n[2:]
    length = len(n)
    if (length<5):
        s = str(n)
        e = 5 - length
        print('0'+'.'+(e-1)*'0'+s)
    else:
        print(n)

