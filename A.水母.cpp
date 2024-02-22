#include<stdio.h>
#include<string.h>
char ar[10010]={0};
char br[10010]={0};
int main()
{
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",ar);
		scanf("%s",br);
		//gets(ar);
//		int la=strlen(ar);
//		int bat=0;
//		for(int j=0;j<la;j++)
//		{
//			if(ar[j]==' ')
//			bat=j;
//		}
		if(ar[0]==br[0]||ar[0]+32==br[0]||ar[0]==br[0]+32)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}