#randomcode.py
import random
a=random.randrange(1,36)
m='abcdefghijklmnopqrstuvwxyz123456789'
codes=[]
code=''
for i in range(10):
    for n in range(8):
        a=random.randrange(0,35)
        code=code+m[a]
    codes.append(code)
    code=''
print(codes)
