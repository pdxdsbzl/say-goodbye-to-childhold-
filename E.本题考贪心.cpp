#include<stdio.h>
int ar[10010]={0};
int main()
{
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n=0,m=0;
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ar[j]);
		}
		for(int j=0;j<m;j++)
		{
			int p=0,q=0;
			scanf("%d%d",&p,&q);
			if(p==1||q==1)
			{
				ar[0]+=3;
			}
			else if(ar[q-1]-ar[0]>6&&ar[p-1]-ar[0]>6)
			{
				ar[q-1]++;
				ar[p-1]++;
			}
			else if(ar[q-1]>ar[p-1])
			{
				ar[p-1]+=3;
			}
			else
			{
				ar[q-1]+=3;
			}
		}
		int point=0;
		for(int j=1;j<n;j++)
		{
			if(ar[j]>ar[0])
			{
				point++;
			}
		}
		printf("%d\n",point+1);
	}
}