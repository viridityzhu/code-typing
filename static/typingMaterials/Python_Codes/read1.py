#read1.py
def gettext():

    text=open('../Desktop/hamlet.txt','r',encoding='utf-8').read()
    text=text.lower()
    sign='!"#$%&()*+,-./:;<=>?@[\\]^_‘{|}~'
    for ch in sign:
        text=text.replace(ch,' ')
    return text
hamlet=gettext()
words=hamlet.split()
counts={}
#ex=['the','and','to','of','a','i','you','my','in','it','that','is','not','his','this','but','with','for','your','as','be','he','me','what']

for word in words:
    counts[word]=counts.get(word,0)+1
#for word in ex:
#    del counts[word]
items=list(counts.items())
items.sort(key=lambda x:x[1],reverse=True)
for i in range(10):
    word,count=items[i]
    print('{:<10},{:>5}'.format(word,count))
    
