#include<stdio.h>  
int main()  
{  
  int n;int a;
  scanf("%d",&n);
  a=n;
  for(int i=0;i<n;i++)
  {
    a=n;
    for(int j=0;j<n-i-1;j++) printf(" ");
    for(int j=0;j<2*i+1;j++) 
    {
      if(j<i)
        printf("%d",a-- );
      else
        printf("%d",a++ );
    }
    printf("\n");
  }
  for(int i=n-2;i>=0;i--)
  {
    a=n;
    for(int j=0;j<n-i-1;j++) printf(" ");
    for(int j=0;j<2*i+1;j++) 
    {
      if(j<i)
        printf("%d",a-- );
      else
        printf("%d",a++ );
    }
    printf("\n");
  }
  return 0;  
} 