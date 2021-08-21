#include <stdio.h>

int main()
{
    void switchs(int* a, int* b);
    int a[100];int n=0,j,i;
    for(;(a[n]=getchar())!='\n';n++) {a[n]-=48;//n=len
      //printf("%d ",a[n]);
    }
      //printf("\nn:%d\n",n);
    for(i=0;i<n-1;i++)
      for(j=0;j<n-i-1;j++)
        if(a[j]<a[j+1]) switchs(a+j,a+j+1);
    for(i=0;i<n;i++) printf("%d",a[i]);
    printf("\n");

//printf("%d ",a[i]
    return 0;
}
void switchs(int* a, int* b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}