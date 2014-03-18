//在一个字符串查找一个最长子串，要求这个子串的每个字符相同
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000

int main(void)
{
	char str[max];
	int i,j,k,count=0,len=0;
	printf("input a string:\n");
	fgets(str,max,stdin);
	if(strlen(str)==0)
		return 1;
	for(i=0;i<(int)strlen(str)-1;i++)
	{
		if(str[i]==str[i+1])
		{
			count=1;
			for(j=i+1;j<(int)strlen(str)-1;j++)
			{
				if(str[j]==str[j+1])
					count++;
				else
				{
					break;
				}
			}
		}
		if(count>len)
		{
			len=count;
			k=i;
		}
	}
	printf("结果为:\n");
	for(j=k;j<=k+len;j++)
		printf("%c",str[j]);
	printf("\n");
	return 0;
}
