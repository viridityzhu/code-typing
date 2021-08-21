print("hello! welcome to gpa calculator 2.0.#滑稽")
print("输入完成请输入成绩为0")
grade =input("请输入成绩:")
A1=0#point
A2=0#score
while grade not in ['0']  :
    G=0
    credit=eval(input("请输入学分:"))

    A1=A1+credit
    A2=eval(grade)*credit+A2
    print('now score:{} now credit:{} total score:{} total credit:{}'.format(grade,credit,A2,A1))
    grade =input("请输入成绩:")
    
GPA=A2/A1
print("您的加权平均分是{:.2f}".format(GPA))
