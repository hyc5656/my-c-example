#include<stdio.h>
#include<stdlib.h>

#define max 1000
typedef struct
{
    int c[max];
    int top;
} seqstack;

seqstack* init_stack()
{
      seqstack* t=(seqstack *)malloc(sizeof(seqstack));
      t->top=-1;
      return t;
}

void push_s(seqstack* t,int c)
{
    t->c[++t->top]=c;
}

void pop_s(seqstack* t,int* c)
{
    *c=t->c[t->top--];
}

void conversion(seqstack*l,long n,int r)
{
    while(n)
    {
        push_s(l,n%r);
        n=n/r;
    }
}

int main()
{
    seqstack* l=init_stack();
    long n;
    int r;
    printf("要转换的数为:\n");
    scanf("%ld",&n);
    printf("要转换为几进制数:\n");
    scanf("%d",&r);
    conversion(l,n,r);
    while(l->top>=0)
    {
        int tmp;
        pop_s(l,&tmp);
        printf("%d",tmp);
    }
    return 0;
}
