#include<stdio.h>
int run(int m)
{
	if((m%4==0&&m%100!=0)||(m%400==0))
	return 1;
	else
	return 0;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int point=0;
	int arr[1000];
	int k=0;
	for(int i=a;i<=b;i++)
	{
		if(run(i)==1)
		{
			point++;
			arr[k]=i;
			k++;
		}
	}
	printf("%d\n",k);
	for(int i=0;i<=k-1;i++)
	{
		printf("%d ",arr[i]);
	}
}