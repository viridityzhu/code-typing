#include<stdio.h>
int cal(int*n,char*op,int len);
int main()
{
	//n0 op0 n1 op1 n2
	int n[100]; char op[100];
	scanf("%d",&n[0]);
	int i;
	for(i=0;1;i++)
	{
		char ch;
		if((ch=getchar())=='\n') break;
		else op[i]=ch;
		scanf("%d",&n[i+1]);
	}
	printf("%d\n",cal(n,op,i) );
	return 0;
}
int cal(int*n,char*op,int len)
{
	if(len==1)
	{
		switch(op[0])
		{
			case '+':{//printf("%d+%d\n", n[0],n[1]);
				return n[0]+n[1];break;}
			case '-':{//printf("%d-%d\n", n[0],n[1]);
				return n[0]-n[1];break;}
			case '*':{//printf("%d*%d\n", n[0],n[1]);
				return n[0]*n[1];break;}
			case '/':{//printf("%d/%d\n", n[0],n[1]);
				return n[0]/n[1];break;}
		}
	}

	for(int i=0;i<len;i++)
	{
		if(op[i]=='*')
		{
			//printf("%d*%d\n",n[i],n[i+1] );
			n[i]*=n[i+1];len--;
			for(int j=i+1;j<=len;j++)
			{
				n[j]=n[j+1];
				op[j-1]=op[j];
			}

			return cal(n,op,len);
		}
		else if(op[i]=='/')
		{
			//printf("%d/%d\n",n[i],n[i+1] );
			n[i]/=n[i+1];len--;
			for(int j=i+1;j<=len;j++)
			{
				n[j]=n[j+1];
				op[j-1]=op[j];
			}
			return cal(n,op,len);
		}
	}

	for(int i=0;i<len;i++)
	{
		if(op[i]=='+')
		{
			//printf("%d+%d\n",n[i],n[i+1] );
			n[i]+=n[i+1];len--;
			for(int j=i+1;j<=len;j++)
			{
				n[j]=n[j+1];
				op[j-1]=op[j];
			}
			return cal(n,op,len);
		}
		else
		{
			//printf("%d-%d\n",n[i],n[i+1] );
			n[i]-=n[i+1];len--;
			for(int j=i+1;j<=len;j++)
			{
				n[j]=n[j+1];
				op[j-1]=op[j];
			}
			return cal(n,op,len);
		}
	}
	return 0;
}