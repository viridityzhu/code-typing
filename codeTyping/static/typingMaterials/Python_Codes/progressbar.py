#progressbar.py
import time
scale=50
print('begin'.center(25,'-'))
c=time.clock()
for i in range(1,scale+1):
    a='*'*i
    b='-'*(scale-i)
    c-=time.clock()
    d=i/scale*100
    print('\r{:^3.0f}%[{}->{}] {:.2f}s'.format(d,a,b,-c),end='')
    time.sleep(0.05)
print('end'.center(25,'-'))
