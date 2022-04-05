n=input("")
m=0
if n[0]=="$" :
    m=float(n[1:])*6.78
    print('￥{:.2f}'.format(m))
elif n[0:3]=="USD":
    m=float(n[3:])*6.78
    print('RMB{:.2f}'.format(m))
elif n[0]=="￥" :
    m=float(n[1:])/6.78
    print('${:.2f}'.format(m))
elif n[0:3]=="RMB":
    m=float(n[3:])/6.78
    print('USD{:.2f}'.format(m))
