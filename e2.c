#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll* next;
} ll,*linklist;

void reverse(linklist* t)
{
    ll *p=*t,*q;
    *t=NULL;
    while(p)
    {
	q=p;
	p=p->next;
	q->next=*t;
	*t=q;	
    }
}

int main(void)
{
    linklist l=NULL;
    int i;
    srand(time(NULL));
    for(i=0;i<15;i++)
    {
        ll* tmp=(ll*)malloc(sizeof(ll));
	tmp->data=rand()%100;
	tmp->next=l;
	l=tmp;
    }
    printf("逆置前:\n");
    linklist h=l;
    while(h)
    {
	printf("%d ",h->data);
	h=h->next;
    }
    reverse(&l);
    printf("\n逆置后:\n");
    h=l;
    while(h)
    {
	printf("%d ",h->data);
	h=h->next;
    }
    return 0;
}
