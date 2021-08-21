#include<stdio.h>
int putPoker(int a[],int len);
int copyPoker(int a[],int b[],int len);
int washPoker(int a[],int len);
int comparePoker(int a[],int b[],int len);
int main(){
    int n;int a[100000],b[100000];int t=1;
    scanf("%d",&n);
    putPoker(a,2*n);putPoker(b,2*n);
    washPoker(b,2*n);
    while(!comparePoker(a,b,2*n)) 
    {
        washPoker(b,2*n);
        t++;
    }
    printf("%d\n",t);
    return 0;
}

int putPoker(int a[],int len)
{
    for(int i=1;i<=len;i++) a[i]=i;
    return 0;
}
int copyPoker(int a[],int b[],int len)
{
    for(int i=1;i<=len;i++) b[i]=a[i];
    return 0;
}
int washPoker(int a[],int len)
{
    int b[100000];copyPoker(a,b,len);
    for(int i=1;i<=len;i++)
    {
        if(i<=len/2) a[i*2]=b[i];
        else a[(i-len/2)*2-1]=b[i];
    }
    return 0;
}
int comparePoker(int a[],int b[],int len)
{
    for(int i=1;i<=len;i++)
        if(a[i]!=b[i]) return 0;
    return 1;
}
/*
1 2 3 4 5 6 7 8 9 10
6 1 7 2 8 3 9 4 10 5//*/