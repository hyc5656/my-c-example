//插入或查找函数，不带数组长度
#include<stdio.h>
#include<stdlib.h>

#define max 300

int insertorsearch(int* sortedarray,int data)
{
	int i=0,j=0,k;
	int *p=sortedarray;
	while(*p)
	{
		j++;
		p++;
	}
	while(sortedarray[i]<=data&&i<j)
	{
		if(sortedarray[i]==data)
			return i;
		i++;
	}
	if(i<j)
	{
		for(k=j-1;k>=i;k--)
			sortedarray[k]=sortedarray[k];
		sortedarray[i]=data;
		return i;
	}
	else
	{
		sortedarray[i]=data;
		return i;
	}
}

int main(void)
{
	int array[max]={1,3,5,7,8,9};
	int k=insertorsearch(array,6);
	printf("%d\n",k);
	k=insertorsearch(array,3);
	printf("%d\n",k);
	return 0;
}
