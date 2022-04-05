#strrank.py
psg=input('Give me a passage: ')
psgset=set(psg)

count={}
for i in psgset:
    count[i]=psg.count(i)
countlist=list(count.items())
countlist.sort(key=lambda x:x[1],reverse=True)
for i in range(0,len(countlist)):
    print('{:<5}{:>10}'.format(countlist[i][0],countlist[i][1]))
