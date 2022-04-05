class Tree():
    def __init__(self,p):
        self.stand=1
        self.position=p

l,m=input().split()
ls=[]
for i in range(int(m)):
    a=input().split()
    ls.append(a)
#ls=[['a','b'],[]]


trees=int(l)+1
road=[]
for t in range(0,int(l)+1):
    road.append(Tree(t))

for tree in road:
    for area in ls:
        if int(area[0])<=tree.position<=int(area[1]):
                tree.stand= 0 #砍了树
    if tree.stand==0:
        trees-=1
print(trees)