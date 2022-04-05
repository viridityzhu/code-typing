from turtle import *
setup()
face=[90,0,-90,180]
n=200
while True:
    for i in range(0,4):
        seth(face[i])
        fd(n)
        n-=3
    if n<=0:
        break


