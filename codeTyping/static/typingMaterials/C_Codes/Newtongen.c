#include<stdio.h>
int main()
{
	double e=0.001;
	double a;
	scanf("%lf",&a);
	double x=a/2,lastX=x+1+e;
	if(a>0)
	{
		while(!(x-lastX<e && lastX-x<e))
			{
				lastX=x;
				x=(x+a/x)/2;
			}
		printf("%lf\n", x);
	}
	else
		printf("Illegal.\n");
	return 0;
}