#include<stdio.h>
#include<time.h>
#include<stdlib.h>

const int max=4500000;

int main(void)
{
    FILE *fp,*fp1;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("error\n");
        return -1;
    }
	int bit[1500000]={0},num,i;
	for(i=0;i<max;i++)
	{
		fscanf(fp,"%d ",&num);
		if(num<max)
			bit[num/32]|=1<<(num%32-1); 
	}
    if((fp1=fopen("w1.txt","w"))==NULL)
    {
        printf("error1\n");
        return -1;
    }
	for(i=0;i<1500000;i++)
	{
		for(num=0;num<32;num++)
		{
			if((bit[i]&(0x1<<num))!=0)
				fprintf(fp1,"%d ",i*32+num+1);
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
