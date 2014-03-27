//产生1000w个不重复的数据量
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

const int size=10000000L;
int num[10000000];

int main(void)
{
	int i,j,n,tmp;
	FILE* fp;
	if((fp=fopen("data.txt","w"))==NULL)
	{
		printf("无法打开文件!\n");
		return -1;
	}
	for(i=0;i<size;i++)
		num[i]=i+1;
	srand(time(NULL));
	for(n=0;n<size;n++)
	{
		i=rand()%10000000;
		j=rand()%10000000;
		tmp=num[i];
		num[i]=num[j];
		num[j]=tmp;
	}
	for(n=0;n<size;n++)
		fprintf(fp,"%d ",num[n]);
	fclose(fp);
	return 0;
}
