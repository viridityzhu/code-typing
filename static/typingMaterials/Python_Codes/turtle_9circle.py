import turtle
def Drawcircle(r):
    turtle.seth(-90)
    turtle.circle(r)
turtle.setup()
turtle.pu()
turtle.fd(-200)
turtle.pd()
for i in range(11,1,-1):
    Drawcircle(20*i)
    turtle.pu()
    turtle.seth(0)
    turtle.fd(20)
    turtle.pd()
