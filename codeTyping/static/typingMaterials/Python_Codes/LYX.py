#LYX.py
from turtle import *
setup(0.8,0.5,None,None)
def heng(s):
    pd()
    seth(0)
    fd(s)
    pu()
def shu(s):
    pd()
    seth(-90)
    fd(s)
    pu()
def dian(s):
    pd()
    seth(-45)
    fd(s)
    pu()
def pie(s):
    pd()
    seth(-120)
    fd(s)
    pu()
#yu
pu()
fd(-400)
seth(90)
fd(200)
heng(200)
fd(-200)
seth(-90)
fd(30)
shu(70)
fd(-70)
heng(200)
shu(70)
seth(180)
fd(100)
seth(90)
fd(100)
shu(100)
fd(-50)
seth(180)
fd(62)
def doubledian():
    dian(30)
    seth(180)
    fd(21.22)
    seth(-90)
    fd(9)
    dian(30)
doubledian()
seth(0)
fd(78)
seth(90)
fd(51.44)
doubledian()
#tian
seth(180)
fd(159.22)
seth(-90)
fd(30)
shu(80)
fd(-80)
heng(200)
shu(80)
fd(-40)
seth(180)
fd(200)
heng(200)
fd(-100)
seth(90)
fd(40)
shu(80)
seth(180)
fd(100)
heng(200)

fd(80)
seth(90)
fd(190)
#yu
heng(200)
fd(-200)
seth(-90)
fd(30*1.8)
shu(70*1.8)
fd(-70*1.8)
heng(200)
shu(70*1.8)
seth(180)
fd(100)
seth(90)
fd(100*1.8)
shu(100*1.8)
fd(-50*1.8)
seth(180)
fd(62)
def doubledian2():
    dian(30*1.8)
    seth(180)
    fd(21.22*1.8)
    seth(-90)
    fd(9*1.8)
    dian(30*1.8)
doubledian2()
seth(0)
fd(54)
seth(90)
fd(51.44*1.8)
doubledian2()

seth(0)
fd(140)
seth(90)
fd(120)
pie(60)
seth(0)
fd(50)
seth(90)
fd(50)
shu(100)
heng(170)
pd()
seth(90)
fd(50)
pu()
fd(80)
seth(180)
fd(110)
dian(30*1.8)
seth(0)
fd(120)
dian(30*1.8)