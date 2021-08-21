#include<stdio.h>
int a[51];
int main()
{
  int n,i=0,len;char ch;int flag=0,d=0,w=-1;
  for(len=0;(ch=getchar())!=' ';)
    if(ch!='.') a[len++]=ch-48;
  while(getchar()==' ') ;
  scanf("%d",&n);
  if(n==0) printf("1.00000000");
  else
  {
    if(n<0)
    {
      printf("0.");
      flag=1;
      for(;i>n+1;i--) 
      {
        printf("0");
        d++;
        if(d==8) break;
      }
    }
    for(i=0;i<len||!flag;i++)
    {
      if(d==8) break;
      w++;
      printf("%d",a[i]);
      if(flag==1) d++;
      if(w==n&&!flag) 
      {
        flag=1;
        printf(".");
      }

    }
    for(;d<8;d++) printf("0");
    
  }
  printf("\n");

  

  return 0;
}
