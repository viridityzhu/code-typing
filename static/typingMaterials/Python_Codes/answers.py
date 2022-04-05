#判断快乐数字
def happy(n):
    if n == 1:
        print(True)
    elif 1 < n < 10:
        print(False)
    else:
        m = 0
        for i in str(n):
            m += eval(i) ** 2

        happy(m)


n = eval(input())
happy(n)

#阶乘求和
n=eval(input())
if not isinstance(n,int):
    print("输入有误，请输入正整数")
elif n<=0:
    print("输入有误，请输入正整数")
else:
    m=0

    for i in range(1,n+1):
        mm = 1
        for ii in range(1,i+1):
            mm*=ii
        m+=mm
    print(m)

#百分之转换为五分制
try:
    n = eval(input())
    if n>100 or n<0:
        print('输入数据有误！')
        m=0
    elif n>=90:
        print("输入成绩属于A级别。")
        m=1
    elif n>=80:
        print("输入成绩属于B级别。")
        m=1
    elif n>=70:
        print("输入成绩属于C级别。")
        m=1
    elif n>=60:
        print("输入成绩属于D级别。")
        m=1
    else:
        print("输入成绩属于E级别。")
        m=0
except:
    print('输入数据有误！')
else:
    if m==1:
        print('祝贺你通过考试！')
finally:
    print('好好学习，天天向上！')


#斐波那契
ls=[]
def fib(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fib(n-1)+fib(n-2)

n=eval(input())
m=0
while True:
    if fib(m)<=n:
        ls.append(fib(m))
        m+=1
    else:
        break
s=0
for i in ls:
    s+=i
avg=int(s/len(ls))
for ii in ls:
    j=ls.index(ii)
    ls[j]=str(ii)
print(', '.join(ls)+', {}, {}'.format(s,avg))


#人（h,k）排序
from operator import itemgetter
n=list(eval(input()))
n.sort(key=itemgetter(1))
n.sort(key=itemgetter(0),reverse=True)

m = []
for i in n:
    m.insert(i[1], i)
print(m)


#括号生成
def peidui(left,right,one):
    global ls
    if left==0 and right==0:
        ls.append(one)
        return
    if left>0:
        peidui(left-1,right,one+'(')
    if right>left:
        peidui(left,right-1,one+')')
ls=[]
n=eval(input())
peidui(n,n,'')
print(ls)

#三次登录
t=0
while t<3:
    t+=1
    u=input()
    p=input()
    if u=='Kate' and p=='666666':
        print('登录成功！')
        break
    elif t==3:
        print('3次用户名或者密码均有误！退出程序。')



#测验4
#凯撒密码
n=input()
s=''
for i in n:
    if i.islower():
        s+=chr((ord(i)-96+3)%26+96)
    elif i.isupper():
        s+=chr((ord(i)-64+3)%26+64)
    else:
        s+=i
print(s)



#水仙花数
ls = []
for i in range(100, 1000):
    a = i // 100
    b = (i - a * 100) // 10
    c = i - a * 100 - b * 10

    if a ** 3 + b ** 3 + c ** 3 == i:
        ls.append(str(i))
print(','.join(ls))

#说句心里话
a=input()
b=input()
print('{}，我想对你说，{}'.format(a,b))

#字符串垂直输出
a=input()
print('\n'.join(a))


#哈姆雷特词频统计
def gettext():
    text = open('hamlet.txt', 'r', encoding='utf-8').read()
    text = text.lower()
    sign = '!"#$%&()*+,-./:;<=>?@[\\]^_‘{|}~'
    for ch in sign:
        text = text.replace(ch, ' ')
    return text
hamlet = gettext()
words = hamlet.split()
counts = {}
for word in words:
    counts[word] = counts.get(word, 0) + 1
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
for i in range(10):
    word, count = items[i]
    print('{:<10},{:>5}'.format(word, count))
