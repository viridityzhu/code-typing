#read2.py
import jieba
def gettext():
    text=open('../Desktop/红楼梦.txt','r',encoding='utf-8').read()
    sign=''' ~!^……-()_+=,.，。\/|?<>[]{}——、'"abcdefghijklmnopqrstuvwxyz0123456789'''
    for i in sign:
        text=text.replace(i,'')
    return text
hl=gettext()
words=jieba.lcut(hl)
counts={}
for word in words:
    if len(word)==1:
        continue
    else:
        counts[word]=counts.get(word,0)+1
ex=['什么','一个','那里','我们','你们','说道']
for word in ex:
    del(counts[word])
items=list(counts.items())
items.sort(key=lambda x:x[1],reverse=True)

for i in range(10):
    x,y=items[i]
    print('{:<10}{:>5}'.format(x,y))
