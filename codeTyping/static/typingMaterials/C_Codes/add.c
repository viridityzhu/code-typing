#include<stdio.h>

void transfer(int x);
int main(){
	int a,b,sum;
	scanf("%d+%d",&a,&b);
	sum=a+b;
	transfer(a);
	transfer(b);
	transfer(sum);
	printf("%d\n",sum );
}
void transfer(int x)
{
	//将十进制转换为二进制，以字符串格式print
	char out[10];int flag=0;
    int p=1,y=0,yushu;
    if(x<0)
    {
    	x*=-1;
    	flag=1;
    }
    while(1)
    {
    	//十进制转二进制
        yushu=x%2;
        x/=2;
        y+=yushu*p;
        p*=10;
        if(x<2)
        {
            y+=x*p;
            break;
        }

    }
    if(flag){
    	//如果是负数，取补码，转成字符串
    	char str[20];
    	sprintf(str, "%08d" , y*(-1));
    	out[8] = 0;
        int i;
        out[0] = '1' ;
        
        for(i = 1; i < 8; i ++)
        {
            if(str[i] == '0')
                out[i] = '1';
            else out[i] = '0';
        }
        for(i = 7; i >0; i --)
        {
            if(out[i] == '0')
            {
                out[i] = '1';
                break;
            }
            else out[i] = '0';
        }
    }
    else //否则直接转成字符串
    	sprintf(out, "%d" , y);
    //输出到命令行
    printf("%s\n",out );
}
