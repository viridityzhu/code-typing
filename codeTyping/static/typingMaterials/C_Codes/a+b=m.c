#include<stdio.h>
//输入n个数，找出其中2个数，之和等于m
int main()
{
	int a[100000];int size=0;int tmp,m;
	scanf("%d",&m);
	while(scanf("%d",&tmp)!=EOF) 
	{
		if(size==0) 
		{
			a[size++]=tmp;
			continue;
		}
		int j=size++;
		for(;j>0&&a[j-1]>tmp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
	/*
	for(int j=0;j<size;j++)
		printf("%d ",a[j] );
	//*/
	for(int i=0;i<size-1;i++)
	{
		int L=i+1,R=size-1;
		while(L<=R)
		{
			int mid=L+(R-L)/2;
			if((a[i]+a[mid])==m) 
			{
				printf("%d+%d=%d\n",a[i],a[mid],m );
				break;
			}
			else if((a[i]+a[mid])>m)
			{
				R=mid-1;
			}
			else L=mid+1;
		}
	}

	return 0;
}