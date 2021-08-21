#include<stdio.h>
int main()
{
  int a,n,i,f,j;
  scanf("%d%d",&n,&a);
  f=a;
  //first line:
  for(i=1;i<=3*n-2;i++) 
    {
      if(i<=(3*n-2)/2)
      {
        printf("%d ",a);
        a=(a!=9)?(a+1):0;
      }
      else if(i==(3*n)/2)
      {
        if(n%2==0) a=(a!=0)?(a-1):9;
          printf("%d",a);
      }
      else
      {
        a=(a!=0)?(a-1):9;
        printf(" %d",a);
      }
    }
  printf("\n");
  //middle lines
  for(i=2;i<n;i++)
  {
    for(j=1;j<=3*n-1-i;j++) 
      if(j==i)
        {
          f=(f!=9)?(f+1):0;
          printf("%d ",f);
        }
      else if(j==3*n-1-i)
      {
        printf("%d",f);
      }
      else printf("  ");
    printf("\n");
  }
  //last line
    for(j=1;j<n;j++) printf("  ");
    a=(f!=9)?(f+1):0;
    for(j=1;j<=n&&n!=1;j++)
    {
      if(j<=n/2)
      {
        printf("%d ",a);
        a=(a!=9)?(a+1):0;
      }
      else if(j==n/2+1)
      {
        if(n%2==0) a=(a!=0)?(a-1):9;
          printf("%d",a);
      }
      else
      {
        a=(a!=0)?(a-1):9;
        printf(" %d",a);
      }
    }
    if(n!=1) printf("\n");


  return 0;
}
