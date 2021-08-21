

#include <stdio.h>

int main() {
    int m,i,j,k;
    int min(int a, int b);
    scanf("%d",&m);
    
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<m+1;j++)
            {
                
                if(i<=(m+1)/2 && j<=(m+1)/2) k=min(i,j);
                else if(i<=(m+1)/2 && j>(m+1)/2) k=min(i,m-j+1);
                else if(i>(m+1)/2 && j<=(m+1)/2) k=min(j,m-i+1);
                else k=min(m-i+1,m-j+1);
                printf("%d",k);

            }
            printf("\n");
        }
    
    
    return 0;
}
int min(int a,int b)
{
    return a>b?b:a;
}
