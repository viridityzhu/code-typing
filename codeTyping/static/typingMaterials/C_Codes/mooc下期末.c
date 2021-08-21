//t1

#include  <stdio.h> 
int main()
{
	int m,n;int flag=0;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++)
	{
		int wei[10]={0};
		int w=i;
		while(w>0)
		{
			wei[w%10]++;
			w/=10;
		}
		for(int j=0;j<10;j++)
		{
			if(wei[j]>1)
			{
				if(!flag) 
				{
					printf("%d",i );
					flag=1;
				}
				else  printf(",%d",i );
			}
		}
	}
	if(!flag) printf("No output");
	printf("\n");



	return 0;
}






//t2
#include  <stdio.h> 
int main()
{
	int line,n;
	scanf("%d%d",&line,&n);
	for(int i=1;i<=line;i++)
	{
		printf("%d",(n+i-1)%10 );
		for(int j=0;j<line-i-1;j++) printf(" ");
		if(i!=line)
			printf("%d",(n+line*2-i-1)%10 );
		printf("\n");
	}

	return 0;
}

//t3
#include  <stdio.h> 
#include<string.h>
int main()
{
	char s[100],ss[100];
	gets(s);gets(ss);
	char *qs=s,*qss=ss;
	while(*qs!='\0') qs++;
	while(*qss!='\0') qss++;
	while(qss>=ss&&qs>=s)
	{
		if(*qss!=*qs) 
		{
			printf("no\n");
			return 0;
		}
		qss--;qs--;
	}
	printf("yes\n");
	return 0;
}
