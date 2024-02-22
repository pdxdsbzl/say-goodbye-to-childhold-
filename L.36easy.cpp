#include<stdio.h>
#include<math.h>
unsigned long long ar[1000010]={0};
int main()
{
	unsigned long long n;
	scanf("%lld",&n);
	for(unsigned long long i=0;i<n;i++)
	{
		scanf("%lld",&ar[i]);
	}
	unsigned long long point=0;
	for(unsigned long long i=0;i<n;i++)
	{
		for(unsigned long long j=0;j<n;j++)
		{
			if(i==j)
			continue;
			unsigned long long lj=1;
			while(1)
			{
				if(ar[j]/10==0)
				break;
				ar[j]=ar[j]/10;
				lj++;
			}
			unsigned long long sum=ar[i]*pow(10,lj)+ar[j];
		//int sum=ar[i]*10+ar[j];
			if(sum%36==0)
			point++;
			
		}
	}
	printf("%lld",point);
	return 0;
}