#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	char name[20];
	struct node* link;
}NODE;


void create(NODE*head,int k);
void insert(NODE*head,NODE*p,int k);
void node_delete(NODE*head,int k);
void output(NODE*head);
int length(NODE*head);


int main()
{
	NODE*head,*p;
	int n,chose=0,imn;
	p=(NODE*)malloc(sizeof(NODE));
	p->link=NULL;
	head=p;
	
	printf("head is created!!!\nNow how many nodes do you want?\n");
	scanf("%d",&n);
	printf("\nNow type the %d nodes below:\n",n );
	create(head,n);
	printf("\nlinklist is created!!!!!\nWhat do you want to do then?\n");
	do
	{
		printf("\n--------------------\n1: insert a node\n2: delete a node\n3. output the linklist\n4. calculate the length\n5. exit\n--------------------\nPlease enter the number:\n");
		scanf("%d",&chose);
		switch(chose)
		{
			case 1:
				NODE* temp;
				temp=(NODE*)malloc(sizeof(NODE));
				printf("\nWhere do you like to insert?\n");
				scanf("%d",&imn);
				printf("\nType the name of this node them:\n");
				scanf("%s",temp->name);
				insert(head,temp,imn);
				printf("\n\"%s\" is inserted successfully!\n\nWhat do you want to do then?\n", temp->name);
				break;
			case 2:
				printf("\nWhich node do you like to delete?\n");
				scanf("%d",&imn);
				node_delete(head,imn);
				printf("\nthe %dth node is deleted successfully!\nWhat do you want to do then?\n", imn);
				break;
			case 3:
				printf("\nAll the nodes are:\n");
				output(head);
				printf("\nWhat do you want to do then?\n");
				break;
			case 4:
				printf("\nthe length is %d\n\nWhat do you want to do then?\n",length(head) );
		}
	}while(chose!=5);
	return 0;
}


void create(NODE*head,int k)
{
	NODE*p,*q=head;
	for(;k>0;k--)
	{
		p=(NODE*)malloc(sizeof(NODE));
		scanf("%s",p->name);
		p->link=q->link;
		q->link=p;
		q=p;
	}
	return;
}
void insert(NODE*head,NODE*p,int k)
{
	NODE*q=head;
	for(int i=0;i<k-1;i++) q=q->link;
	p->link=q->link;
	q->link=p;
	return;
}
void node_delete(NODE*head,int k)
{
	NODE*q=head;
	for(int i=0;i<k-1;i++) q=q->link;
	NODE*p=q->link;
	q->link=p->link;
	free(p);
	return;
}
void output(NODE*head)
{
	head=head->link;
	do
	{
		printf("%s\n",head->name );
		head=head->link;
	}while(head!=NULL);
	return;
}
int length(NODE*head)
{
	int len;
	for(len=0;head->link!=NULL;len++)
	{
		head=head->link;
	}
	return len;
}