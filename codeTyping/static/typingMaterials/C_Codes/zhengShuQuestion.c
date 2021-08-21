#include<stdio.h>
int power(int a,int n);
int main()
{
  int n,i,w,a,counter=0;
  scanf("%d",&n);
  int max=power(10,n);
  for(i=power(10,n-1);i<max;i++)
  {
    for(w=n;w>=1;w--)
    {
      a=i/power(10,w-1);
      if(a%((n-w+1)*(n-w+1))) 
        {
          i+=power(10,w-1)-1;
          //减少运行时长的关键步骤
          //如果判断到某一位不行了，直接把那一位是那个数的所有数跳过
          break;
        }
    }
    if(w==0) counter++;
  }
  printf("%d\n",counter);
  return 0;
}
int power(int a,int n)
{
  int i,m=a;
  if (n==0) return 1;
  for(i=1;i<n;i++) m*=a;
  return m;
}
