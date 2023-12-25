#include<stdio.h>
int main()
{
	int arr[12]={0};
	for(int i=0;i<12;i++)
	{
		scanf("%d",&arr[i]);
	}
	int sum1=0;
	int cur=0;
	int flag=1;
	for(int i=0;i<12;i++)
	{
		cur+=300;
		cur-=arr[i];
		if(cur<0)
		{
			printf("-%d",i+1);
			flag=0;
			break;
		}
		while(1)
		{
			if(cur>=100)
			{
				cur-=100;
				sum1+=100;
			}
			else
			break;
		}
//		if(i==11)
//		{
//			flag=1;
//		}
	}
	if(flag==1)
	printf("%d",cur+12*sum1/10);
	return 0;
	
}