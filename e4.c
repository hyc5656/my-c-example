#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct dnode
{
	int data;
	struct dnode* prior;
	struct dnode* next;
} dnode, *lknode;

int main(void)
{
	lknode h=NULL,t,p,k;
	int i=0;
	srand(time(NULL));
	for(i=0;i<15;i++)
	{
		dnode* tmp=(dnode *)malloc(sizeof(dnode));
		tmp->data=rand()%10;
		tmp->next=h;
		h=tmp;
	}
	t=h;
	printf("为删除重复值前数据:\n");
	for(i=0;i<15;i++)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	k=h;
	while(k!=NULL)
	{
		t=k->next;
		p=k;
		do
		{
			while((t!=NULL)&&(t->data!=k->data))
			{
				p=t;
				t=t->next;
			}
			if(t!=NULL)
			{
				p->next=t->next;
				t=p->next;
			}
		}while(t!=NULL);
		k=k->next;
	}
	printf("\n删除重复数据后:\n");
	t=h;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	t=h;
	while(t->next)
	{
		k=t->next;
		k->prior=t;
		t=k;
	}
	t->next=h;
	h->prior=t;
	printf("\n变为双向循环链表后以逆序输出:\n");
	k=h->prior;
	while(h!=k)
	{
		printf("%d ",k->data);
		k=k->prior;
	}
	printf("%d ",h->data);
	printf("\n");
	return 0;
}
