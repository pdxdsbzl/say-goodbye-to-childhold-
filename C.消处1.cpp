#include<stdio.h>
#include<string.h>
int ar[1000100]={0};
int main()
{
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		memset(ar,0,sizeof(ar));
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ar[j]);
		}
		int point=0;
		int flag=0;
		int fat=0;
		for(int j=n-1;j>=0;j--)
		{
			int bun=1;
			if(j==0)
			{
				point++;
				break;
			}
			
//			for(int k=0;k<=j;k++)
//			{
//				if(ar[k]!=ar[0])
//				{
//					bun=0;
//					break;
//				}
//				
//			}
			if(fat==0)
			{
				for(int k=j;k>=0;k--)
			{
				if(ar[k]!=ar[j])
				{
					bun=0;
					break;
				}
			}
			}
			if(bun==0&&flag==1)
			{
				flag=0;
				continue;
			}
			if(bun==0&&j+1<n&&ar[j]!=ar[j+1])
			{
				point++;
				flag=1;
			}
			if(bun==1)
			{
				fat=1;
				point++;
			}
			
		}
		printf("%d\n",point);
	}
	return 0;
}