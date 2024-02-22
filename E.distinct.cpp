#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ar[10010]={0};
char br[10010][10010]={0};
int cr[26]={0};
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&ar[i]);
		scanf("%s",br[i]);
	}	
	int tmp=0;
	for(int i=0;i<t;i++)
	{
		int sum=0;
		memset(cr,0,sizeof(cr));
		for(int j=1;j<=ar[i]-1;j++)
		{
			 tmp=0;
			for(int k=0;k<j;k++)
			{
				cr[br[i][k]-97]++;
			}
			for(int k=0;k<26;k++)
			{
				if(cr[k]!=0)
				tmp++;
			}
			memset(cr,0,sizeof(cr));
			for(int k=j;k<ar[i];k++)
			{
				cr[br[i][k]-97]++;
			}
			for(int k=0;k<26;k++)
			{
				if(cr[k]!=0)
				tmp++;
			}
			if(tmp>sum)
			sum=tmp;
		}
		printf("%d\n",sum);
	}
}