p=eval(input())
with open('hamlet.txt','rt') as fo:
    text=fo.read()
    each=len(text)//p
    for i in range(p):
        with open('hamlet{:0>3}'.format(i+1),'wt') as foo:
            foo.writelines(text[each*i:each*(i+1)])