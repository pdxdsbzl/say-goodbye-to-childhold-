#include<stdio.h>
unsigned long long ar[1000010][2]={0};
int main()
{
	unsigned long long n=0,m=0,k=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(unsigned long long i=0;i<k;i++)
	{
		scanf("%lld%lld",&ar[i][0],&ar[i][1]);
	}
	double man=0.0;
	for(unsigned long long i=1;i<=n;i++)
	{
		double sum1=0.0;
		unsigned long long flag1=0;
		for(unsigned long long j=0;j<k;j++)
		{
			unsigned long long bat=0;
			if(ar[j][0]==i)
			{
				flag1=1;
				unsigned long long flag2=0;
				for(unsigned long long u=0;u<k;u++)
				{
					
					if(ar[u][1]==ar[j][1])
					{
						bat++;
						flag2=1;
					}
					else 
					{
						if(flag2==1)
						flag2=2;
					}
					if(flag2==2)
					break;
				}
			}
			else
			{
				if(flag1==1)
				flag1=2;
			}
			if(flag1==2)
			break;
			if(bat!=0)
			{
				double bunch=bat*1.0;
				sum1+=1.0/bunch;
			}
		}
		if(sum1>1.0)
		sum1=1.0;
		man+=sum1;
	}
	double male=0.0;
	for(unsigned long long i=1;i<=m;i++)
	{
		double sum1=0.0;
		unsigned long long flag1=0;
		for(unsigned long long j=0;j<k;j++)
		{
			unsigned long long bat=0;
			if(ar[j][1]==i)
			{
				flag1=1;
				unsigned long long flag2=0;
				for(unsigned long long u=0;u<k;u++)
				{
					
					if(ar[u][0]==ar[j][0])
					{
						bat++;
						flag2=1;
					}
					else 
					{
						if(flag2==1)
						flag2=2;
					}
					if(flag2==2)
					break;
				}
			}
			else
			{
				if(flag1==1)
				flag1=2;
			}
			if(flag1==2)
			break;
			if(bat!=0)
			{
				double bunch=bat*1.0;
				sum1+=1.0/bunch;
			}
		}
		if(sum1>1.0)
		sum1=1.0;
		male+=sum1;
	}
			
	printf("float\n");
	printf("%lf %lf",man,male);
	return 0;
}