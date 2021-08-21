from turtle import *
color('red','green')
begin_fill()#这是开始填充颜色
while True:#这是while循环，条件是True就意味着永远循环下去……
    forward(200)#这是画笔往前方移200
    left(170)#画笔往左转向170度
    if abs(pos())<1:#abs是取绝对值，pos是获取画笔当前的坐标
        break#强制跳出while循环
end_fill()#结束填充颜色
done()
