/*
计算时针分针的夹角
神tm分针动的时候时针也要动啊！！！智障吧
//*/
#include<stdio.h>
#define dh 30
#define dm 6
#define circle 360
int main()
{
	int a,b,i=1; float h,m,d;
	while(i)
	{
	scanf("%d%d",&a,&b);
	if(a==222) i=0;
	h=a%12*dh+b*0.5;
	m=b*dm;
	d=h-m>0?h-m:m-h;
	printf("At %d:%02d the angle is %.1f degrees.\n",a,b,d);		
	}

	return 0;
}