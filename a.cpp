#include<stdio.h>
int main()
{
	int a,b;
	int arr[100];
	int m=0;
	for(int i=0;;i++)
	{
		if(a==0&&b==0)
		break;
		scanf("%d%d",&a,&b);
		arr[i]=a+b;
		m++;
	}
	for(int i=0;i<=m-2;i++)
	{
		printf("%d\n",arr[i]);
	}
}