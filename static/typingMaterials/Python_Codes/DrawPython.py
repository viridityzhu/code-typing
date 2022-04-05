#DrawPython.py
import turtle
turtle.setup(0.5,0.5,None,None)
turtle.pu()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(25)
turtle.pencolor('gold')
turtle.seth(-40)
co=['yellow','green','blue','grey']
for i in range(4):
    turtle.circle(40,80)
    turtle.circle(-40,80)
    turtle.pencolor(co[i])
turtle.circle(40,80/2)
turtle.fd(40)
turtle.circle(16,180)
turtle.fd(40*2/3)

#233333,It's a colorful python.
