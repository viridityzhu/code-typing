# #writefile.py
# a=open('hahaha.txt','w+')
# a.writelines(['Crazyy ','a ',' dog'])
# a.seek(0)
# for line in a:
#     print(line)
#
# a.close()
#
# #right
# with open('hahaha.txt','r') as f:
#     for line in f.readlines():
#         print(line)

with open ('twentylines.txt','rt') as fo:
    a=fo.read(24)
    print(a)