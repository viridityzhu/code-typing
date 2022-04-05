#include<stdio.h>
int main()
{
    int m,n,a[100][100],maxLine[100][2]={0},maxCol[100][2]={0};
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int j=0;j<n;j++) maxCol[j][1]=999;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]>maxLine[i][1]) 
                {maxLine[i][0]=j;maxLine[i][1]=a[i][j];}
    for(int j=0;j<n;j++)
        for(int i=0;i<m;i++)
            if(a[i][j]<maxCol[j][1]) 
                {maxCol[j][0]=i;maxCol[j][1]=a[i][j];}
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(maxLine[i][0]==j&&maxCol[j][0]==i)
            {
                printf("Point:a[%d][%d]==%d\n", i,j,a[i][j]);
                return 0;
            }
        }
    printf("No Point\n");
        //*/
    return 0;
}
