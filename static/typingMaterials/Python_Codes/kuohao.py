# kuohao.py
p=input("")
kh=[]
for i in p:
    if i=='(' or i==')':
        kh.append(i)
el=l=len(kh)
if l==0:
    print("配对成功")
else:
    #print(kh,l)
    while True:
        for ii in range(0,l-1):
            if kh[ii]=='(' and kh[ii+1]==')':
                del kh[ii+1]
                del kh[ii]
                #print(kh)
                el=l
                l-=2
                break
        if el==l:
            yy=False
            break
        elif l==0:
            yy=True
            break
        el=l
    if yy==True:
        print("配对成功")
    else:
        print("配对不成功")
    
                
            
    

        
    
