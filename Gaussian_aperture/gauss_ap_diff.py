# -*- coding: utf-8 -*-
"""
Created on Wed Jun 28 07:23:51 2017

@author: Jon
"""

import matplotlib.pyplot as plt
import numpy as np
x, y = np.loadtxt("E:\\Plot_data\\gauss_ap.txt",unpack=True)
#print ("bessel.txt, loadtxt")
plt.plot(x,y)

plt.xlabel('x')
plt.ylabel('I(x)')
plt.title('2D diffraction pattern from Gaussian aperture at y=0')
plt.legend()
plt.grid(True)
plt.savefig("E:\\plot_data\\gauss_ap.jpg")
plt.show()