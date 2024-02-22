//#include<stdio.h>
//#include<string.h>
//#include<bits/stdc++.h>
////#include<algorithm>
//using namespace std;
#include<bits/stdc++.h>
using namespace std;
char ar[10010][10010]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int br[]={0,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
char cr[10010]={0};
int dr[10];
int main()
{
	int p=0;
	for(int i=1;i<=6;i++)
	{
		scanf("%s",&cr);
		for(int j=0;j<27;j++)
		{
			if(!strcmp(ar[j],cr))
			{
				dr[p]=br[j];
				p++;
				break;
			}
		}
	}
	sort(dr,dr+p);
	int flag=0;
	for(int i=0;i<p;i++)
	{
		if(flag)
		{
			printf("%02d",dr[i]);
			
		}
		else
		{
			if(dr[i])
			{
				printf("%d",dr[i]);
			flag=1;
			}
		}
	}
	if(!flag)
	printf("0");
	return 0;
}