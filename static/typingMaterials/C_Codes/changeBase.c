#include<stdio.h>
char a[100],b[100];
int changeBase(char* a,int len,int n);
int power(int a,int n);
int maxNum(char * a,int len);
int main()
{
  int i,m,n,ji,jj,lenA,lenB,maxA,maxB,flag=1;
  char ch;
  //------------input---------
  for(lenA=1;(ch=getchar())!=' ';lenA++) 
    a[lenA]=ch;
  while((ch=getchar())==' ') ;
  b[1]=ch;
  for(lenB=2;(ch=getchar())!='\n';lenB++) 
    b[lenB]=ch;
  //----------judge---------
  maxA=maxNum(a+1,lenA);
  maxB=maxNum(b+1,lenB);
  for(ji=maxA+1;ji<=36&&flag;ji++)
  {
    m=changeBase(a+1,lenA,ji);
    for(jj=maxB+1;jj<=36;jj++)
    {
      n=changeBase(b+1,lenB,jj);
      if(m==n) {flag=0;break;}
    }
  }
  //---------print-------------
  if(!flag)
  {
    for(i=1;i<lenA;i++) 
      printf("%c",a[i]);
    printf(" (base %d) = ",ji-1);
    for(i=1;i<lenB;i++) 
      printf("%c",b[i] );
    printf(" (base %d)\n",jj);
  }
  else
  {
    for(i=1;i<lenA;i++) 
      printf("%c",a[i]);
    printf(" is not equal to ");
    for(i=1;i<lenB;i++) 
      printf("%c",b[i] );
    printf(" in any base 2..36\n" );
  }
  return 0;
}


int changeBase(char *a,int len,int n)
{
  int b=0,i,w;char m;
  for(i=1;i<len;i++)
  {
    m=*(a+len-i-1);
    if(m>47&&m<58) 
      w=(int)(m-48);
    else 
      w=(int)(m-65+10);
    b+=w*power(n,i-1);
  }
  return b;
}


int power(int a,int n)
{
  int i,m=a;
  if (n==0) return 1;
  for(i=1;i<n;i++) m*=a;
  return m;
}


int maxNum(char * a,int len)
{
  int n=0,i,w;char m;
  for(i=1;i<len;i++)
  {
    m=*(a+len-i-1);
    if(m>47&&m<58) 
      w=(int)(m-48);
    else 
      w=(int)(m-65+10);
    n=w>n?w:n;
  }
  return n;
}
