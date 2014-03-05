//冒泡排序的实现
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define max 1000
void bubble(int* a,int n);

int main()
{
    int a[max];
    int n,i;
    srand(time(NULL));
    fflush(stdout);
    printf("请输入随机生成的数组的大小:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
    printf("随机生成的%d个数为:",n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n冒泡排序后:");
    bubble(a,n);
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
    getchar();
    return 0;
}

void bubble(int* a,int n)
{
    int i,j,swap=1;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                swap=0;
            }
        }
        if(swap==1)
            return;
    }
}
