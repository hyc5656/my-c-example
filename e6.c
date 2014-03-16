#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define max 128
typedef struct d
{
	int data;
	int flag;
} Data;

int main(void)
{
	int i=0,j=0,k;
	Data d[max];
	srand(time(NULL));
	for(i=0;i<8;i++)
	{
		d[i].data=rand()%50;
		d[i].flag=0;
		printf("%d ",d[i].data);
	}
	printf("\n每数到4输出一个数直到数组数完:\n");
	i=0;
	while(1)
	{
		if(i==3)
		{
			if(d[j].flag==0)
			{
				printf("%d ",d[j].data);
				d[j].flag=1;
				i=0;
				j=(j+1)%8;
				continue;
			}
			else
			{
				int f=0;
				for(k=0;k<8;k++)
					if(d[k].flag==0)
						f=1;
				if(f==0)
					break;
				else
				{
					j=(j+1)%8;
					continue;
				}
			}
		}
		int f=0;
		for(k=0;k<8;k++)
			if(d[k].flag==0)
				f=1;
		if(f==0)
			break;
		else
		{
			if(d[j].flag==0)
				i++;
		}
		j=(j+1)%8;
	}
	return 0;
}
