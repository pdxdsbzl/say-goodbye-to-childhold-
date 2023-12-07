#include<stdio.h>
int main()
{
	int arr[7][2];
	int tmp=0;
	for(int i=0;i<=6;i++)
	{
		scanf("%d%d",&arr[i][0],&arr[i][1]);
	}
	int str[7];
	for(int i=0;i<=6;i++)
	{
		str[i]=arr[i][0]+arr[i][1];
	}
	int flag=0;
	for(int i=0;i<=6;i++)
	{
		if(str[i]>8)
		flag=1;
	}	
	if(flag==0)
	printf("0");
	else
	{
		for(int i=0;i<=6;i++)
		{
			if(str[i]>tmp)
			tmp=str[i];
		}
		for(int i=0;i<=6;i++)
		{
			if(str[i]==tmp)
			{
				printf("%d",i+1);
				break;
			}
		}
	}
}