# -*- coding: UTF-8 -*-
def encrypt(key, s):
    # key和s都是字符串
    key = bytearray(str(key).encode("utf-8"))
    b = bytearray(str(s).encode("utf-8"))
    n = len(b)  # 求出 b 的字节数
    c = bytearray(n * 2)
    j = 0
    lenKey = len(key)
    for i in range(0, n):
        b1 = b[i] ^ key[(i * 5) % lenKey]
        b2 = b1 ^ key[(i + 3) % lenKey]  # b1 = b2^ key
        c1 = b2 % 16
        c2 = b2 // 16  # b2 = c2*16 + c1
        c1 = c1 + 65
        c2 = c2 + 65  # c1,c2都是0~15之间的数,加上65就变成了A-P 的字符的编码
        c[j] = c1
        c[j + 1] = c2
        j = j + 2
    return c.decode("utf-8")


def decrypt(key, s):
    key = bytearray(str(key).encode("utf-8"))
    c = bytearray(str(s).encode("utf-8"))
    n = len(c)  # 计算 b 的字节数
    lenKey = len(key)
    if n % 2 != 0:
        return ""
    n = n // 2
    b = bytearray(n)
    j = 0
    for i in range(0, n):
        c1 = c[j]
        c2 = c[j + 1]
        j = j + 2
        c1 = c1 - 65
        c2 = c2 - 65
        b2 = c2 * 16 + c1
        b1 = b2 ^ key[(i + 3) % lenKey]
        b[i] = b1 ^ key[(i * 5) % lenKey]
    try:
        return b.decode("utf-8")
    except:
        return "failed"
key = '密码12m再长一点也可以吧'
s1 = encrypt(key, '中文呢哈哈哈哈哈霍霍，，，，，，，，xxx;123。')
s2 = decrypt(key, s1)
print(s1, '\n', s2)
