#include<stdio.h>
int main()
{
    char letter;
    int m,k,i,flag=0;
    scanf("%d %c",&m,&letter);
    for(k=0;k<m;k++)
    {
        for(i=0;i<m-k-1;i++)
            printf(" ");
        printf("%c",(letter+k-65)%26+65);
        for(i=0;i<k*2-1;i++)
        {
            printf(" ");
            flag=1;
        }
        flag?printf("%c\n",(letter+4*m-4-k-65)%26+65):printf("\n");
    }
    for(k=m-1;k>0;k--)
    {
        for(i=0;i<m-k;i++)
            printf(" ");
        printf("%c",(letter+m*2-1-k-65)%26+65);flag=0;
        for(i=k*2-3;i>0;i--)
        {
            printf(" ");
            flag=1;
        }
        flag?printf("%c\n",(letter+2*m-3+k-65)%26+65):printf("\n");
    }    return 0;
}


//A:65 