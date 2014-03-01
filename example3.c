#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 1000
typedef struct lnode
{
    int data;
    struct lnode* next;
} Lnode,*linklist;

linklist init()
{
    linklist l=NULL;
    Lnode *r;
    int data;
    scanf("%d",&data);
    while(data!=-1)
    {
        r=(Lnode*)malloc(sizeof(Lnode));
        r->next=l;
        r->data=data;
        l=r;
        scanf("%d",&data);
    }
    return l;
}

int main()
{
    linklist l=init();
    Lnode *p,*q=NULL;
    p=l;
    l=NULL;
    printf("倒置前:\n");
    while(p)
    {
        printf("%d ",p->data);
        q=p;
        p=p->next;
        q->next=l;
        l=q;
    }
    printf("倒置后:\n");
    while(l)
    {
        printf("%d ",l->data);
        l=l->next;
    }
    return 0;
}
