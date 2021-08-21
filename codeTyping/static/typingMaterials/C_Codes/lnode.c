#include<stdio.h>
int main()
{
	L = (LinkList)malloc(sizeof(LNode));p = L;
	for(i=1;i<=4;i++)
	{
		p -> next = (LinkList)malloc(sizeof(LNode));
		p = p -> next; p->data=i*2-1;
	}
	p -> next = NULL;
	for(i=4; i>=1; i--) Ins_LinkList(L, i+1, i*2);
	for(i=1; i<=3; i++) Del_LinkList(L, i);
	return 0;
}