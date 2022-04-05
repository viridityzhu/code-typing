/*
对于任意的真分数 N/M （ 0 < N < M ），均可以求出对应的小数。
如果采用链表存储各位小数，对于循环节采用循环链表表示，则所有分数均可以表示为如下链表形式。
输入： N M
输出： 整个循环节
要求： 编写一个尽可能高效的查找循环节起始点的函数： 
NODE * find( NODE * head, int * n ) 。
函数的返回值为循环节的起点（即图中的指针p），n为循环节的长度。
说明：提交程序时请同时提交将分数转换为小数的函数 
change( int n, int m, NODE * head ) 。
*/
#include <stdio.h>
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  
        {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  
///* Here is waiting for you. 
void change( int n, int m, NODE * head ) 
{
	int flag=1,al=0,j;int a[20]={0};
	NODE*p=head;
	while(flag)
	{
		n*=10;
		for(int i=1;i<10;i++)
		{//模拟竖式运算
			if(n-i*m>0&&n-i*m<m) 
			{
				for(j=0;j<al;j++) if(a[j]==i*100+n-i*m) break;
				if(j<al)
				{//数组a[]中存的是每次运算得到的商与余数的结果，这一次得出的结果以前已经出现过了，可见进入了循环
					NODE*q=head;
					for(int k=0;k<=j;k++) q=q->next;
					p->next=q;
					flag=0;
				}
				else
				{//未进入循环
					NODE*q=(NODE*)malloc(sizeof(NODE));
					q->data=i;
					p->next=q;
					p=q;
					n-=i*m;
					a[al++]=i*100+n;//本来是要将商i和余数n两个数存进数组a的，懒得用二维数组，我就用类似哈希的思路对它们处理了一下，这样并不可靠……
				}
			}
			else if(n==i*m)
			{//余数为0的情况，代表除尽了
				NODE*q=(NODE*)malloc(sizeof(NODE));
				q->data=i;
				q->next=NULL;
				p->next=q;
				p=q;
				flag=0;//退出循环
				break;
			}
		}
	}
} 
NODE * find( NODE * head, int * n ) 
{ 
	NODE*q=head,*p;
	for(int i=1;q->next!=NULL;i++)
	{
		for(int j=1;j<=i;j++) q=q->next;
		p=q;
		for(int j=1;p->next!=NULL;j++)
		{
			p=p->next;
			if(p==q)
			{
				*n=j-i+1;
				return q;
			}
		}
	}
	*n=0;
	return NULL;
} 

  