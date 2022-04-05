#include<stdio.h>
int main()
{
	void exchange(int * q1,int * q2,int * q3);
	int a,b,c,*p1,*p2,*p3;
	printf("give me a,b and c:");
	scanf("%d%d%d",&a,&b,&c);
	p1=&a;
	p2=&b;
	p3=&c;
	exchange(p1,p2,p3);
	printf("from the biggest to the smallest:%d,%d,%d",a,b,c);
	return 0;
}
void exchange(int * q1,int * q2,int * q3)
{
	void swap(int *p1,int *p2);
	if(*q1<*q2) swap(q1,q2);
	if(*q1<*q3) swap(q1,q3);
	if(*q2<*q3) swap(q2,q3);
}
void swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}