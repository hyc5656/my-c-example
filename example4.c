#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int is_op(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%')
        return 1;
    else return 0;
}

int main(void)
{
    seqstack* t=init_stack();
    char a[]={'3','2','4','2','2','*','+','1','3','*','-','^','*','5','-','#'};
    int i=0;
    int l=0,r=1;
    while(a[i]!='#')
    {
        if(!is_op(a[i]))
            push_s(t,a[i]-48);
        else
        {
            int b,c;
            pop_s(t,&c);
            pop_s(t,&b);
            switch(a[i])
            {
                case '+':
                    printf("%d+%d=%d\n",b,c,b+c);
                    push_s(t,b+c);
                    break;
                case '-':
                    printf("%d-%d=%d\n",b,c,b-c);
                    push_s(t,b-c);
                    break;
                case '*':
                    printf("%d*%d=%d\n",b,c,b*c);
                    push_s(t,b*c);
                    break;
                case '/':
                    printf("%d/%d=%d\n",b,c,b/c);
                    push_s(t,b/c);
                    break;
                case '^':
                    l=0;
                    r=1;
                    for(l=0;l<c;l++)
                        r*=b;
                    printf("%d^%d=%d\n",b,c,r);
                    push_s(t,r);
                    break;
            }
        }
        i++;
    }
    return 0;
}
