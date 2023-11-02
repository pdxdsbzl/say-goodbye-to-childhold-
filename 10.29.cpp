void bubble(int arr[],int sz)
{
	for(int j=1;j<=sz-1;j++)
	{
		int flag=1;
		for(int k=0;k<=sz-j;k++)
		{
			if(arr[k]>arr[k+1])
			{
			int ret=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=ret;
			flag=0;
		    }
		}
		if(1==flag)
		break;
	}
}
#include<stdio.h>
int main()
{
	int arr[10]={9,4,8,2,5,6,10,7,3,1};
	int sz=sizeof(arr)/sizeof(arr[0]);
	bubble(arr,sz);
	for(int i=0;i<=9;i++)
	{
		printf("%d",arr[i]);
		
	}
	return 0;
}