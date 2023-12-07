#include<stdio.h>
int main()
{
	int arr[10]={0};
	int head;
	int point=0;
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&head);
	for(int i=0;i<=9;i++)
	{
		if(arr[i]<head+30)
		point++;
	}
	printf("%d",point);
}