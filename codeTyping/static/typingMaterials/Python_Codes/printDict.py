#printDict.py
D={"a":"A","b":"B","c":"C"}
#1
for k,v in D.items():
    print(k+":"+v)


#2
for d in D:#or D.keys()
    print(d+":"+D[d])

#3
for d in D:
    print(d+":"+D.get(d,"False"))
