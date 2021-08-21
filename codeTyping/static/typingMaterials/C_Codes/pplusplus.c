#include <stdio.h>
int main()
{
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	int *p,*j,temp;
	p=a;j=&a[9];
	i=0;
	while(i<6)
	{
		i++;
		temp=*p;*p=*j;*j=temp;
		p++;j--;
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}