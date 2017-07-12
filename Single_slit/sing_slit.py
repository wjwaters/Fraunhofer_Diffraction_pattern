# -*- coding: utf-8 -*-
"""
Created on Wed Jun 28 07:23:51 2017

@author: Jon
"""

import matplotlib.pyplot as plt
import numpy as np
x, y = np.loadtxt("E:\\Plot_data\\sing_slit.txt",unpack=True)
#print ("bessel.txt, loadtxt")
plt.plot(x,y)

plt.xlabel('x')
plt.ylabel('I(x)')
plt.title('2D diffraction pattern from singluar slit aperture at y=0')
plt.legend()
plt.grid(True)
plt.savefig("E:\\plot_data\\sing_slit.jpg")
plt.show()