#chongfubeta.py
ls=input('Give me a list and use the comma to divide:').split(',')
def chongfu(ls):
    #str.split:use the comma to divide the str and return a list, useful.
    b=False
    m=len(ls)
    lss=set(ls)
    n=len(lss)
    if m!=n:
        b=True
        
    return b
print(chongfu(ls))

#range(a,b)is from a to b-1 !!!! so ugly.
