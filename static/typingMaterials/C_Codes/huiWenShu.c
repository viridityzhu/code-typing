#include<stdio.h>
#include<math.h>
int main(){
    int n;int a[5];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int nf=i*i,k;int w;int flag=1;
        //printf("nf/pow(10,0):%d/%d=%d\n",nf,(int)pow(10,0),nf/(int)pow(10,0));
        for(w=0;nf/(int)pow(10,w)>0;w++);
        for(int j=nf, k=0;k<w;k++,j/=10) a[k]=j%10;
        for(int j=0, k=w-1;j<(w+1)/2&&k>=w/2;j++,k--)
        {
            if(a[j]!=a[k]) flag=0;
        }
        if(flag==1) printf("%d\n",i );
    }
    return 0;
}
/*
1    w:1   j:0    k:0
11   w:2   j:0    k:1
121  w:3   j:0 1  k:2 1
1221 w:4   j:0 1  k:3 2
//*/