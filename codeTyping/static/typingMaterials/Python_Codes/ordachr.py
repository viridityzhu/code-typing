#ordachr.py
#ord() transform str into ascii   chr() contrast
s=input()
ss=''
for i in s:
    if 97<=ord(i)<=122:
        
        m=chr(122+97-ord(i))
    elif 65<=ord(i)<=90:
        
        m=chr(65+90-ord(i))
    else:
        m=i
    ss+=m
print(ss)
