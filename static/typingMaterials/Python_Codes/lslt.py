ls=eval(input())
lt=[]
for i in range(0,len(ls)):
    ji=1
    for ii in range(0,len(ls)):
        if ii==i:
            continue
        else:
            ji*=ls[ii]
    lt.append(ji)
print(lt)
