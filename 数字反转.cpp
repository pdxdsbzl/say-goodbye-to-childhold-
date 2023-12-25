#include<stdio.h>
int main()
{
	long long n;
	scanf("%lld",&n);
	int flag=0;
	if(n<0)
	{
		flag=1;
		n*=-1;
	}
	long long m=n;
	int la=1;
	for(la=1;;la++)
	{
		if(m<10)
		{
			break;
		}
		m/=10;
	}
	m=n;
	int arr[la]={0};
	for(int i=0;i<la;i++)
	{
		arr[i]=m%10;
		m=m/10;
	}
	if(flag==1)
	printf("-");
	int point=0;
	for(int i=0;i<la;i++)
	{
		if(point==0&&arr[i]==0)
		continue;
		point=1;
		printf("%d",arr[i]);
	}
	return 0;
}