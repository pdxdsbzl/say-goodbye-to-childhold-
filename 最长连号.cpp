#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}//pai xu
	int tmp=0;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n-i;j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				tmp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=tmp;
//			}
//		}
//	}
	//int flag=0;
	int point=1;
	tmp=1;
	for(int i=1;i<n;i++)
	{
//		if(arr[i]==arr[i-1])
//		{
//			//flag=1;
//			//tmp++;
//			continue;
//		}
		if(arr[i]==arr[i-1]+1)
		{
			//flag=1;
			tmp++;
			if(tmp>point)
		{
			point=tmp;
		}
			continue;
		}
		tmp=1;
	}
	printf("%d",point);
	return 0;
}