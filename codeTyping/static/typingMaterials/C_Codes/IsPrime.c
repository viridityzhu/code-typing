#include<stdio.h>


//if you are looking for the "isPrime" function...


int isPrime(int n)
{
    int judge=1;
    for(int i=2;i<=n/2;i++)
        if(n%i==0) judge=0;
    return judge;
}

//*/




#define MAX_NUM 100000
char isPrime[MAX_NUM+2];

int main()
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		isPrime[i]=1;
	}
	for(int i=2;i<=MAX_NUM;i++)
	{
		if(isPrime[i]==1)
		{
			for(int j=i*2;j<=MAX_NUM;j+=i)
			{
				isPrime[j] = 0;
			}
		}
	}
	for(int i=2;i<=MAX_NUM;i++)
	{
		if (isPrime[i]==1)
			printf("%d ",i );
	}

	return 0;
}
