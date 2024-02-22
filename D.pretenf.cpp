#include<stdio.h>
char ar[10010][10010]={0};
int br[10010]={0};
int main()
{
	int t=0;
   scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&br[i]);
		scanf("%s",&ar[i]);
	}
	for(int i=0;i<t;i++)
	{
		int point=0;
		if(br[i]%2==0)
		{
			for(int j=0;j<br[i]/2;j++)
			{
				if(ar[i][j]==ar[i][br[i]-1-j])
				break;
				point++;
			}
			
		}
		else
		{
			for(int j=0;j<(br[i]-1)/2;j++)
			{
				if(ar[i][j]==ar[i][br[i]-1-j])
				break;
				point++;
			}
		}
		printf("%d\n",br[i]-2*point);
	}
	return 0; 
}