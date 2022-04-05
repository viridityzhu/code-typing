#piaccu.py
from random import random
from time import clock
from math import sqrt
cishu=10000
incrcl=0
clock()
for i in range(1,cishu+1):
    x,y=random(),random()
    d=sqrt(x**2+y**2)
    if d<=1:
        incrcl+=1
pi=4*(incrcl/cishu)
                
print('pi is {}, and the time is {:5.5}'.format(pi,clock()))
