
#include<stdio.h>
#include<string.h>
int main(){
    char words[5][100];
    for(int i=0;i<5;i++) scanf("%s",words[i]);
    for(int i=0;i<4;i++)
        for(int j=0;j<4-i;j++)
            if(strcmp(words[j],words[j+1])>0)
            {
                //printf("exchange %s and %s\n", words[j],words[j+1]);
                char t[100];
                strcpy(t,words[j]);
                strcpy(words[j],words[j+1]);
                strcpy(words[j+1],t);
                
            }
    for(int i=4;i>=0;i--) printf("%s\n",words[i] );
    return 0;
}

/*

#include<stdio.h>
#include<string.h>
int calLen(char a[]);
//你他妈的二维数组！！！！！！！！！！！！！！！！！！！！！！！！！！！
int myCat(char a[], char b[],int len);
int main(){
    char a[100],b[100],c[100],d[100],e[100],the[500];
    char*p[5]={a,b,c,d,e};
    scanf("%s",a);scanf("%s",b);scanf("%s",c);scanf("%s",d);scanf("%s",e);
    int len[5];
    len[0]=calLen(a)+1;
    len[1]=calLen(b)+1;
    len[2]=calLen(c)+1;
    len[3]=calLen(d)+1;
    len[4]=calLen(e)+1;
    strcpy(the,"");
    myCat(the,a,0);
    myCat(the,b,len[0]);
    myCat(the,c,len[0]+len[1]);
    myCat(the,d,len[0]+len[1]+len[2]);
    myCat(the,e,len[0]+len[1]+len[2]+len[3]);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            int lenn=0;
            for(int k=0;k<j;k++) lenn+=len[k];
                //printf("\nnow is:\n%s %s %s %s %s\n",p[4],p[3],p[2],p[1],p[0] );
                //printf("compare:%s %s\n",the+lenn,the+lenn+len[j] );
            if(strcmp(the+lenn,the+lenn+len[j])>0)
            {
                //printf("----now change %s and %s\n",the+lenn,the+lenn+len[j]);
                char *t;int tt;
                t=p[j];p[j]=p[j+1];p[j+1]=t;
                strcpy(the,"");
                tt=len[j];len[j]=len[j+1];len[j+1]=tt;
                //printf("exchange len %d and len %d:%d %d\n",j,j+1,len[j],len[j+1] );
                myCat(the,p[0],0);
                myCat(the,p[1],len[0]);
                myCat(the,p[2],len[0]+len[1]);
                myCat(the,p[3],len[0]+len[1]+len[2]);
                myCat(the,p[4],len[0]+len[1]+len[2]+len[3]);
                //printf("----now the is %s and %s\n",the+lenn,the+lenn+len[j+1]);
            }
        }
    }
    printf("%s\n%s\n%s\n%s\n%s\n",p[4],p[3],p[2],p[1],p[0] );
    return 0;
}
int calLen(char a[])
{
    int i=0;
    while(a[i]) i++;
    return i;
}
int myCat(char a[],char b[],int len)
{
    int j=0;
    for(;b[j];j++,len++) a[len]=b[j];
    a[len]='\0';
    return 0;
}
//*/