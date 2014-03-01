#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 1000
typedef struct
{
    int data[max];
    int last;
} seqlist;

seqlist* seq_init()
{
    seqlist* l=(seqlist*)malloc(sizeof(seqlist));
    l->last=-1;
    return l;
}

void seq_append(seqlist* l)
{
    srand(time(NULL));
    l->data[++l->last]=rand()%150;
}

void part(seqlist* l)
{
    int tmp=l->data[0],i,j;
    for(i=1;i<=l->last;i++)
    {
        if(l->data[i]<tmp)
        {
            int tmp1=l->data[i];
            for(j=i-1;j>=0;j--)
                l->data[j+1]=l->data[j];
            l->data[0]=tmp1;
        }
    }
}

int main()
{
    seqlist* l;
    int i;
    l=seq_init();
    srand(time(NULL));
    for(i=0;i<50;i++)
        l->data[++l->last]=rand()%150;
    printf("排列前:\n");
    for(i=0;i<=l->last;i++)
        printf("%d ",l->data[i]);
    printf("\n排列后:");
    part(l);
    for(i=0;i<=l->last;i++)
        printf("%d ",l->data[i]);
    getchar();
    return 0;
}

