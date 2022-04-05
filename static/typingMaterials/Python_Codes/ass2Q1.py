from turtle import *


def drawN_aryTree(lineLen, n):

    if lineLen < 40:
        return
    if n < 2:
        n = 2
        # return
    angle = ANGLE / (n - 1)
    left(ANGLE / 2)
    for i in range(n):
        fd(lineLen / RATE)
        drawN_aryTree(lineLen / RATE, n - 1)
        bk(lineLen / RATE)
        if i == n - 1:
            break
        right(angle)
    left(ANGLE / 2)
    return


ANGLE = 120
RATE = 1.8
speed(0)
lt(90)
penup()
bk(300)
pendown()
fd(100)
drawN_aryTree(300, 5)
