//tmd ����һ�ڿΣ������ҵ���
#include<stdio.h>
int main()
{
	int arr[10]={11,12,13,14,15,16,17,18,19,20};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int left=0;
	int right=sz-1;
	int k;
	scanf("%d",&k);
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]<k)
		left=mid+1;
		else if(arr[mid]==k)
	{
		printf("you find it and the xia biao of k is%d",mid);
		break;
	}
		else if(arr[mid]>k)
		right=mid-1;
	}
	if(left>right)
	printf("k is not in the arr!!! you are really a big fool!!!!");
	return 0;
}