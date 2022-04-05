a, b, c, d = eval(input()), eval(input()), eval(input()), eval(input())
ls=[a,b,c,d]
lt=[]
def perm(begin):#全排列  递归思想：把每个元素放在最前面，然后对后面的元素进行全排列
    if begin>=4:
        lt.append(ls[:])
    else:
        i=begin
        for num in range(begin,4):
            ls[num],ls[i]=ls[i],ls[num]
            perm(begin+1)
            ls[num], ls[i] = ls[i], ls[num]
perm(0)
print(lt)