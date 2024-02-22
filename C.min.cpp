#include<stdio.h>
unsigned long long ar[1000100][5]={0};
unsigned long long sum[1000100]={0};
int main()
{
	int t;
	//long long sum;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld%lld%lld",&ar[i][0],&ar[i][1],&ar[i][2],&ar[i][3],&ar[i][4]);
	}
	for(int i=0;i<t;i++)
	{
		if(ar[i][4]>=ar[i][0]-ar[i][2]+ar[i][1]-ar[i][3])
		{
			sum[i]=ar[i][2]*ar[i][3];
		}
		else if(ar[i][4]<ar[i][0]-ar[i][2]&&ar[i][4]<ar[i][1]-ar[i][3])
		{
			sum[i]=(ar[i][0]-ar[i][4])*ar[i][1]<ar[i][0]*(ar[i][1]-ar[i][4])?(ar[i][0]-ar[i][4])*ar[i][1]:(ar[i][1]-ar[i][4])*ar[i][0];
		}
		else if(ar[i][4]>=ar[i][0]-ar[i][2]&&ar[i][4]<ar[i][1]-ar[i][3])
		{
			//sum=ar[i][2]*(ar[i][1]-(ar[i][4]-))<ar[i][0]*(ar[i][1]-ar[i][4])?(ar[i][2]*(ar[i][1]-ar[i][4]+ar[i][2])):(ar[i][0]*(ar[i][1]-ar[i][4]));
			sum[i]=ar[i][2]*(ar[i][1]-(ar[i][4]-(ar[i][0]-ar[i][2])))<ar[i][0]*(ar[i][1]-ar[i][4])?ar[i][2]*(ar[i][1]-(ar[i][4]-(ar[i][0]-ar[i][2]))):ar[i][0]*(ar[i][1]-ar[i][4]);
		}
		else if(ar[i][4]<ar[i][0]-ar[i][2]&&ar[i][4]>=ar[i][1]-ar[i][3])
		{
			sum[i]=(ar[i][0]-ar[i][4])*ar[i][1]<ar[i][3]*(ar[i][0]-(ar[i][4]-ar[i][1]+ar[i][3]))?(ar[i][0]-ar[i][4])*ar[i][1]:ar[i][3]*(ar[i][0]-(ar[i][4]-ar[i][1]+ar[i][3]));
		}
		else 
		{
			sum[i]=ar[i][2]*(ar[i][1]-(ar[i][4]-(ar[i][0]-ar[i][2])))<(ar[i][0]-(ar[i][4]-(ar[i][1]-ar[i][3])))*ar[i][3]?ar[i][2]*(ar[i][1]-(ar[i][4]-(ar[i][0]-ar[i][2]))):(ar[i][0]-(ar[i][4]-(ar[i][1]-ar[i][3])))*ar[i][3];
		}
		printf("%lld\n",sum[i]);
	}
	return 0;
}