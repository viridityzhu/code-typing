#include<stdio.h>
int choosePutInT(int* a,int *t,int lenT);
int copyN(int*a,int*b,int len);
int main()
{
    int a[7][32]=
    {
        {},
        {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63},
        {2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31,34,35,38,39,42,43,46,47,50,51,54,55,58,59,62,63},
        {4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31,36,37,38,39,44,45,46,47,52,53,54,55,60,61,62,63},
        {8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31,40,41,42,43,44,45,46,47,56,57,58,59,60,61,62,63},
        {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63},
        {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63}
    };

    int t[32],lines[7],lenLine=0;
    char ch;
    int tempLen=32;
//lines=[,7,,,,,]
    for(lenLine=1;(ch=getchar())!='0';lenLine++)
    {
        if(ch!=' ')
            {
                lines[lenLine]=(int)ch-48; 
            }
        else lenLine--;
    }
    //printf("%d\n",lenLine );

    copyN(t,a[lines[1]],32);
    for(int i=2;i<lenLine;i++)
    {
        tempLen=choosePutInT(a[lines[i]],t,tempLen);
    }
    printf("%d\n",t[0] );
    return 0;
}
int choosePutInT(int *a,int*t,int lenT)
{
    int temp[32];int k=0;
    for(int i=0,j=0;i<32&&j<lenT;)
    {
        if(a[i]==t[j]) 
        {
            temp[k++]=t[j];i++;j++;
        }
        else if(a[i]>t[j]) j++;
        else if(a[i]<t[j]) i++;
    }
    copyN(t,temp,k);
    return k;
}
int copyN(int*a,int*b,int len)
{
    for(int i=0;i<len;i++)
        a[i]=b[i];
    return 0;
}