#DrawSegDisplay.py
import datetime,turtle
def drawGap():
    turtle.pu()
    turtle.fd(5)
    turtle.pd()
def drawLine(draw):
    drawGap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    drawGap()
    turtle.right(90)
def drawDigit(d):
    drawLine(True) if d in[2,3,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in[0,1,3,4,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in[0,2,3,5,6,8,9] else drawLine(False)
    drawLine(True) if d in[0,2,6,8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if d in[0,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in[0,2,3,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in[0,1,2,3,4,5,7,8,9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)
def drawDate(date):
    turtle.color('red')
    for i in date:
        if i=='-':
            
            turtle.write('Year')
            turtle.color('green')
            turtle.fd(40)
        elif i=='+':
            turtle.write('Month')
            turtle.color('blue')
            turtle.fd(40)
        elif i=='=':
            turtle.write('Day')
        else:
            drawDigit(eval(i))
def main():
    turtle.setup(800,350,200,200)
    turtle.penup()
    turtle.fd(-300)
    turtle.pensize(5)
    
    drawDate(datetime.datetime.now().strftime('%Y-%m+%d='))
    turtle.hideturtle()
main()
