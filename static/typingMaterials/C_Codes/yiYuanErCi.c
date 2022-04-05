#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c; double x1,x2;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0 && b==0) printf("Input error!\n");
	else if(a==0)
	{
		x1=-c;x1/=b;
		printf("x=%.6lf\n",x1);
	}
	else
	{
		if(b==0)
			{
				if(-c/a<0)
				{
					x1=sqrt(c/a);
					printf("x1=%.6lfi\nx2=-%.6lfi\n",x1,x1);
				}
				else
				{
					x1=sqrt(-c/a);x2=-x1;
					if(x1==x2) printf("x1=x2=%.6lf\n",x1);
					else printf("x1=%.6lf\nx2=%.6lf\n",x1,x2);
				}
			}
		else
		{
			x1=-b/a;x1/=2;
			if(b*b-4*a*c==0) 
			{
				x2=x1;printf("x1=x2=%.6lf\n",x1);
			}
			else if(b*b-4*a*c>0) 
			{
				x2=sqrt(b*b-4*a*c)/(2*a);
				printf("x1=%.6lf\nx2=%.6lf\n",x1+x2,x1-x2);
			}
			else
			{	x2=sqrt(-(b*b-4*a*c))/(2*a);
				printf("x1=%.6lf+%.6lfi\nx2=%.6lf-%.6lfi\n",x1,x2,x1,x2);
			}
		}
		
	}

	return 0;
}