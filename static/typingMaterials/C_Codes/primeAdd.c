#include<stdio.h>
int main()
{
    int n,i,j,flag=1;
    int isPrime(int n);
    scanf("%d",&n);
    for(i=2;i<n&&flag;i++)
        for(j=i;j<n&&flag;j++)
        {
            if(isPrime(i)&&isPrime(j))
                if(i+j==n)
                {
                    printf("%d=%d+%d\n",n,i,j);
                    flag=0;
                }
        }
    return 0;
}
int isPrime(int n)
{
    int judge=1;
    for(int i=2;i<=n/2;i++)
        if(n%i==0) judge=0;
    return judge;
}
