#include<stdio.h>
#include<string.h>
char ar[10010]={0};
int br[26]={0};
int main()
{
	for(int i=0;i<4;i++)
	{
		memset(ar,0,sizeof(ar));
		gets(ar);
		int la=strlen(ar);
		for(int j=0;j<la;j++)
		{
			if(ar[j]>=65&&ar[j]<='Z')
			br[ar[j]-65]++;
		}
		
	}
	int max=0;
	for(int i=0;i<26;i++)
	{
		if(br[i]>max)
		max=br[i];
	}
//	int map[max+1][51]={0};
	for(int i=0;i<max;i++)
	{		
		for(int j=0;j<51;j++)
		{
			if(j%2==0)
			{
				if(br[j/2]+1>=max+1-i)
			printf("*");
			else
			printf(" ");
			}
			else
			printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<51;i++)
	{
		if(i%2==0)
		printf("%c",65+i/2);
		else
		printf(" ");
	}
	return 0;
}