#include<stdio.h>
int main()
{
    int dayPast(int p,int day);
    int n,peach;
    scanf("%d",&n);
    peach=dayPast(1,n);
    peach>1?printf("The monkey got %d peaches in first day.\n",peach):printf("The monkey got 1 peach in first day.\n");
    return 0;
}
int dayPast(int p,int day)
{
    if(1==day) return p;
    else {day--;return dayPast((p+day)*2, day);}
}
