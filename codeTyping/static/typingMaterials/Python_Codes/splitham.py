# with open('hahaha.txt','r') as fo:
#     people=eval(input())
#     lines=len(fo.readlines())
#     count=lines//people
#     more=lines%people
#     li=[]
#     for p in range(people):
#         li.append(fo.readlines(count))
#     for i in range(len(li)):
#   #      li[i]=li[i].writelines(li[i])
#         a='hamlet00'+str(i+1)
#         with open(a,'wt') as b:
#             b.writelines(li[i])
#     last='hamlet00'+str(people)
# ##    if more !=0:
# ##        with open(last,'at') as c:
# ##            c.writelines(
#

'''
将哈姆雷特文本均分给p个人，让他们工作。
'''
import math
p=eval(input('多少人分任务？'))
with open('hamlet.txt','rt') as fo:
    text = fo.readlines()
    longs=len(text)
    long=math.ceil(longs/p)
    for i in range(p):
        with open('hamlet{:0>3}.txt'.format(i+1),'wt') as foo:
            foo.writelines(text[long*i:long*(i+1)])
