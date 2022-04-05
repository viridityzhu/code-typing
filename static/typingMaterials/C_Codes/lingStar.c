#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m,k,i,flag=0;
    scanf("%d",&m);
    for(k=0;k<m;k++)
    {
        for(i=0;i<m-k-1;i++)
            printf(" ");
        printf("*");
        for(i=0;i<k*2-1;i++)
        {
            printf(" ");
            flag=1;
        }
        flag?printf("*\n"):printf("\n");
    }
    for(k=m-1;k>0;k--)
    {
        for(i=0;i<m-k;i++)
            printf(" ");
        printf("*");flag=0;
        for(i=k*2-3;i>0;i--)
        {
            printf(" ");
            flag=1;
        }
        flag?printf("*\n"):printf("\n");
    }

    //comments
    return 0;
}

