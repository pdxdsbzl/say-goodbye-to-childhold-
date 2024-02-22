#include<stdio.h>
#include<string.h>
char ar[10010]={0};
int main()
{
	int t=0;
	scanf("%d",&t);
	//int p=0,q=0;
	for(int i=0;i<t;i++)
	{
		int n=0;
		scanf("%d",&n);
		int p=0,q=0;
		memset(ar,0,sizeof(ar));
		scanf("%s",ar);
		for(int j=0;j<n;j++)
		{
			if(ar[j]=='D')
			{
				for(int k=j;k<n;k++)
				{
					if(ar[k]=='F')
					{
						for(int h=k;h<n;h++)
						{
							if(ar[h]=='S')
							p=1;
						}
					}
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			if(ar[j]=='d')
			{
				for(int k=j;k<n;k++)
				{
					if(ar[k]=='f')
					{
						for(int h=k;h<n;h++)
						{
							if(ar[h]=='s')
							q=1;
						}
					}
				}
			}
		}
		printf("%d %d",p,q);
		printf("\n");
	}
	return 0;
}