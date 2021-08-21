#themost.py
li=list(eval(input('')))
se=set(li)
counts={}
for i in range(0,len(se)):
    counts[li[i]]=li.count(li[i])
items=list(counts.items())
items.sort(key=lambda x:x[1],reverse=True)
#print(items) 
print(items[0][0])
