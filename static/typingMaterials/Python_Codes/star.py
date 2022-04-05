#star.py
from turtle import *
color('black','red')
begin_fill()
##for i in range(5):
##    forward(200)
##    right(180-36)
while True:
    forward(200)
    right(144)
    if abs(pos())<1:
        break
end_fill()
