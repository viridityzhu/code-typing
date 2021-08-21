#isOdd.py
def isOdd(n):
    N=n/2
    print(type(N))
    if type(N)==int:
        return 'It is a oushu'
    elif type(N)==float:
        return 'It is a jishu'
o=int(input('Tell me a num:'))

print(isOdd(o))
    
#Tell me why the 'N' is always a float???
