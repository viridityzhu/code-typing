#birthbl.py
from random import*
pbirth={}
yes=0
no=0
for c in range(randint(0,20000)):
    for i in range(23):
        pbirth[i]=randint(1,366)
    pbirthset=set(pbirth.values())
    if len(pbirth)!=len(pbirthset):
        yes+=1
    else:
        no+=1

print(yes/(yes+no))
