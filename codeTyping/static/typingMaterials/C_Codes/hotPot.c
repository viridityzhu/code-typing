#include<stdio.h>
int main(){
  int T,N;int hp[10000];
  scanf("%d",&T);//T:total times;
  for(int c=0;c<T;c++)//every time;
  {
    int xm=-999;//xm's happiness
    scanf("%d",&N);//N:number of dishes
    for(int m=0;m<N;m++) 
      scanf("%d",&hp[m]);//every dish's happiness

    for(int start=0;start<N;start++)
    {
      if(hp[start]<0&&hp[start]<xm) start++;
      for(int end=start;end<N;end++)
      {
        int sum=0;
        for(int l=start;l<=end;l++)
        {
          sum+=hp[l];
          //printf("%d %d\n",start,end );
          if(sum<0) l=end+1;
        }
        if(sum>xm) xm=sum;
      }
    }
    printf("%d\n", xm);
  }

return 0;
}
