#chongfu.py
ls=input('Give me a list and use the comma to divide:').split(',')
def chongfu(ls):
    #str.split:use the comma to divide the str and return a list, useful.
    b=False
    m=len(ls)
    for i in range(0,m-1):
        for ii in range(i+1,m):
            if ls[i]==ls[ii]:
                b=True
        if b==True:
            break
        
    return b
print(chongfu(ls))

#range(a,b)is from a to b-1 !!!! so ugly.
