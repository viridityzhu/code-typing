//t1 guoqingjie
#include<stdio.h>
int main()
{
    int y,w,start,day;
    scanf("%d",&y);
    int calDays(int y,int m,int d);
    int calWeekday(int d);
    day=calDays(y,10,1);
    w=calWeekday(day);
    switch(w)
    {
        case 1:case 6:start=1;break;
        case 2:case 3:case 4: case 5:start=32-w;break;
        case 0:start=30;
    }
    if(start<3) printf("10.0%d-10.0%d\n",start,start+6 );
    else printf("09.%d-10.0%d\n", start,7-(31-start));
    return 0;
}
int calDays(int y,int m,int d)
{
    int days=0;
    for(int i=1900;i<y;i++)
        days+=((!(i%4)&&i%100)||!(i%400))?366:365;
    for(int i=1;i<m;i++)
        switch(i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: days+=31;break;
            case 4:case 6:case 9:case 11:days+=30;break;
            case 2:
                days+=((!(y%4)&&y%100)||!(y%400))?29:28;break;
        }
    days+=d;
    return days;
}
int calWeekday(int d)
{
    int weekday;
    weekday=d%7;
    return weekday;
}



//t2
#include <stdio.h>  
#include<string.h>
int main()  
{  
    char s1[105] = {0},sub[1000][105]={0};  
    gets(s1);  
    int flag=1,flag2=1;int subNum=0,maxlen=0;
    for(int j=0;s1[j];j++)
    {
        flag2=1;
        for(int i=j,m=0;s1[i]&&flag;i++)
        {
            flag=1;
            for(int k=0;sub[subNum][k];k++)
                if(sub[subNum][k]==s1[i])
                    {flag=0;break;}
            if (flag) sub[subNum][m++]=s1[i];
        }
        for(int i=0;i<subNum;i++)
        {
            if(strcmp(sub[i],sub[subNum])==0) flag2=0;
        }
        flag=1;
        if(sub[subNum][0]&&flag2&&strlen(sub[subNum])>=maxlen) 
            {
                maxlen=strlen(sub[subNum]);
                subNum++;
            }
    }
    for(int i=0;i<subNum;i++)
    {
        if(strlen(sub[i])==maxlen)
            printf("%s\n",sub[i] );
    }
    return 0;
} 
//t3
#include <stdio.h>  
#include<string.h>
int isNumber(char *a);
long int changeToNumber(char*a,int len);
long int power(int a,int n);
int main( )  
{  
    char a[1000],b[1000];
    int lena=0,lenb=0;char ch;
    gets(a);
    for(lena=0;a[lena]!='+';lena++) ;
    for(lenb=lena+1;a[lenb];lenb++) b[lenb-lena-1]=a[lenb];
    lenb-=lena+1;
    a[lena]='\0';b[lenb]='\0';
    /* why wrong??????????????????????????
    what the hell
    for(;(ch=getchar())!='+';lena++) a[lena]=ch;
        a[lena]='\0';
    for(;(ch=getchar())!='\n';lenb++) b[lenb]=ch;
        b[lenb]='\0';
        //*/
    //---------------input over--------------
    if(isNumber(a)&&isNumber(b))
    {
        long int aa,bb;
        aa=changeToNumber(a,lena);
        bb=changeToNumber(b,lenb);
        printf("%ld\n", aa+bb);
    }
    else
    {
        printf("%s\n", strcat(a,b));
    }
    return 0;
} 
int isNumber(char *a)
{
    for(int i=0;a[i];i++)
    {
        if(a[i]<48||a[i]>57) return 0;
    }
    return 1;
}
long int changeToNumber(char*a,int len)
{
    long int sum=0;
    for(int i=len-1;i>=0;i--)
        sum+=power(10,len-i-1)*(long int)(a[i]-48);
    return sum;
}
long int power(int a,int n)
{
    long int s=1;
    for(int i=1;i<=n;i++)
        s*=a;
    return s;
}



/*
串的减法
#include<stdio.h>
int main()
{
    char s[80],t[80],o[80];int lenO=0;
    gets(s);gets(t);
    for(int i=0;s[i];i++)
    {
        int flag=1;
        for(int j=0;t[j];j++)
            if(s[i]==t[j]) flag=0;
        if(flag) o[lenO++]=s[i];
    }
    o[lenO]='\0';
    printf("%s\n",o );
    return 0;
}


删除重复字符

#include<stdio.h>
int main(){
    char str[100];char letters[100];int m=0;int nop[100];int j,k=0;
    gets(str);
    for(int i=0;str[i];i++)
    {
        int flag=1;
        for( j=0;j<m;j++)
            if(str[i]==letters[j]) 
            {
                nop[k++]=i;
                flag=0;
            }
        if(flag)
            letters[m++]=str[i];
    }
    for(int i=0;str[i];i++)
    {
        int flag=1;
        for(int j=0;j<k;j++)
            if(i==nop[j]) 
                flag=0;
        if(flag)
            printf("%c",str[i] );
    }
    printf("\n" );
    return 0;
}



子串反串

void reverse(char* a,int start,int end)
{
    if(start<end) 
    {
        char t; t=*(a+start);
        a[start]=*(a+end);
        a[end]=t;
        reverse(a,start+1,end-1);
    }
    else return;
}

//*/

//T55
#include<stdio.h>
int add(int m,int n);
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("The sum from %d to %d is %d.\n",m,n,add(m,n) );
    return 0;
}
int add(int m,int n)
{
    if(m==n) return m;
    else return m+add(m+1,n);
}