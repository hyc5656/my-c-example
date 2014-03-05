//用2个栈实现队列的功能
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct stack
{
	int data;
	struct stack *next;
} lstack,*linkstack;

void push_t(linkstack* t,int data)
{
	lstack* tmp=(lstack*)malloc(sizeof(lstack));
	tmp->data=data;
	tmp->next=*t;
	*t=tmp;
}

int pop(linkstack* t)
{
	if(*t==NULL)
	{
		printf("\n");
		return -1;
	}
	int d=(*t)->data;
	*t=(*t)->next;
	return d;
}

void push(linkstack* t1,linkstack* t2,int data)
{
	while(*t1!=NULL)
	{
		int d=pop(t1);
		push_t(t2,d);
	}
	push_t(t1,data);
	while(*t2!=NULL)
	{
		int d=pop(t2);
		push_t(t1,d);
	}
}

int main(void)
{
    linkstack *t1,*t2;
    t1=(linkstack*)malloc(sizeof(linkstack));
    t2=(linkstack*)malloc(sizeof(linkstack));
    int i=0;
    srand(time(NULL));
    for(i=0;i<10;i++)
    {
	    int tmp=rand()%100;
	    printf("%d ",tmp);
	    push(t1,t2,tmp);
    }
    printf("\n出队:\n");
    while((i=pop(t1))!=-1)
	    printf("%d ",i);
    printf("\n");
    return 0;
}
