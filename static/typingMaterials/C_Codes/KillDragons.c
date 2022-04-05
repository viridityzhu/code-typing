#include<stdio.h>
int SortThem(int a[],int len);
int KillHeads(int* dragonHeads,int dragonHeadNum,int* worriorHeights,int worriorNum);
int main()
{
    int dragonHeadNum,
        worriorNum,
        dragonHeads[100],
        worriorHeights[100];
    int cost;
    scanf("%d%d",&dragonHeadNum,&worriorNum);
    for(int i=0;i<dragonHeadNum;i++)
        scanf("%d",&dragonHeads[i]);
    for(int i=0;i<worriorNum;i++)
        scanf("%d",&worriorHeights[i]);
    //----------input over---------------
    SortThem(dragonHeads,dragonHeadNum);
    SortThem(worriorHeights,worriorNum);
    cost=KillHeads(dragonHeads,dragonHeadNum,worriorHeights,worriorNum);
    //----------fight over---------------
    if(cost>0) printf("%d\n",cost );
    else printf("bit is doomed!\n");
    return 0;
}
int SortThem(int a[],int len)
{
    for(int i=0;i<len-1;i++)
        for (int j = 0; j < len-i-1; ++j)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    return 0;
}
int KillHeads(int *dragonHeads,int dragonHeadNum,int* worriorHeights,int worriorNum)
{
    printf("开始砍龙！！\n");
    int cost=0,i,j;
    for(i=0,j=0;i<dragonHeadNum&&j<worriorNum;)
    {
        printf("现在是第%d个人砍第%d个龙头\n",j,i);
        if(dragonHeads[i]<=worriorHeights[j])
        {
            printf("勇士身高%d>=龙头直径%d，可以砍\n", worriorHeights[j],dragonHeads[i]);
            cost+=worriorHeights[j];
            i++;j++;
        }
        else {j++;printf("勇士身高%d<龙头直径%d，失败，换一个人试试\n", worriorHeights[j],dragonHeads[i]);}
    }
    printf("最后砍了%d个头\n", i);
    if(i<dragonHeadNum) cost=-1;
    return cost;
}