import matplotlib.pyplot as plt
import numpy as np

#This code below make an aproximation of x*cos(x) using the Runge-Kutta method

n = 100
x = np.linspace(0, 6, n)
fx = x*np.cos(x) + 1

def derivate (x_0):
  return np.cos(x_0) - x_0*np.sin(x_0)

def tangent_line_eq(x, x_0, y_0):
  return derivate(x_0)*(x - x_0) + y_0

def calculate_n_show_aprox(step):
  y_0 = 1

  for x_0 in np.arange(0, 6, step):
    input = np.linspace(x_0, x_0+step, 100)
    plt.plot(input, tangent_line_eq(input, x_0, y_0), color='yellow')
    aux = y_0
    y_0 = tangent_line_eq(x_0+step, x_0, aux)
  
  plt.plot(x, fx, color='blue', label="x*cos(x) + 1")
  plt.title('Aprox with step = '+ str(step))
  plt.legend()
  plt.show()


calculate_n_show_aprox(1)
calculate_n_show_aprox(0.5)
calculate_n_show_aprox(0.25)