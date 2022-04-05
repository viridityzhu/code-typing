#include<stdio.h>
int main()
{
    int n,m;
    int min(int a,int b,int c);
    scanf("%d",&n);
    for(int i=1;i<=n*2-1;i++)
    {
        if(i<=n)
        {
            for(int j=1;j<=n-i;j++)
                printf("  ");
            for(int j=1;j<=2*i-1;j++)
            {
                m=n-min(i-1,j-1,2*i-1-j);
                printf("%-2d",m);
            }
        }
        else
        {
            for(int j=1;j<=i-n;j++) printf("  ");
            for(int j=1;j<=4*n-2*i-1;j++)
            {
                m=n-min(2*n-1-i,j-1,4*n-2*i-1-j);
                printf("%-2d",m);
            }
        }
        printf("\n");
    }
    return 0;
}
int min(int a,int b,int c)
{
    if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
    else if(c<=a&&c<=b) return c;
    else return 0;
}