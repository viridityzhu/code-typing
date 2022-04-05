# 下面的函数求参数a的符号位并以字符串类型返回，‘-’表示负数，空串表示正数

def getSign(a):


# 你需要完善getString函数
    if a<0:
        return '-'
    else:
        return ''


# 下面的函数求整数absA的b进制表示，返回字符串

def getString(absA, b):
    if b==2:
        return '{:b}'.format(absA)
    elif b==10:
        return '{:d}'.format(absA)
    elif b==8:
        return '{:o}'.format(absA)
    elif b==16:
        return '{:X}'.format(absA)




# 你需要完善getString函数



a = int(input())

b = int(input())

mark = getSign(a)

bitString = getString(abs(a), b)

print(mark + bitString)