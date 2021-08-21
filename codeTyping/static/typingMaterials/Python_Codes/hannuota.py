#hannuota.py
n=eval(input('give me the floor:'))
def move(n,a,b,c):
    if n==1:
        print(a,' -->  ',c)
    else:
        move(n-1,a,c,b)
        print(a,' -->  ',c)
        move(n-1,b,a,c)
move(n,'A','B','C')