#include<stdio.h>
#include<string.h>
char ar[10010]={0};

int main()
{
	int flag=1;
	int bat=0;
	scanf("%s",ar);
	int la=strlen(ar);
	for(int i=0;i<la;i++)
	{
		if(ar[i]=='.')
		{
			flag=2;
			bat=i;
			break;
		}
		else if(ar[i]=='/')
		{
			flag=3;
			bat=i;
			break;
		}
		else if(ar[i]=='%')
		{
			flag=4;
			bat=i;
			break;
		}
	}

	int bunch=0;
	if(flag==1)
	{
		for(int i=la-1;i>=0;i--)
		{
			if(ar[i]!=48)
			{
				bunch=1;				
			}
			if(bunch==1)
			printf("%d",ar[i]-48);
		}
	}
	else if(flag==2)
	{
		for(int i=bat-1;i>=0;i--)
		{
			if(ar[i]!=48)
			{
				bunch=1;				
			}
			if(bunch==1)
			printf("%d",ar[i]-48);
		}
		printf(".");
		bunch=0;
		for(int i=bat+1;i<la;i++)
		{
			if(ar[i]!=48)
			bunch=i;
		}
		for(int i=la-1;i>=bunch-1;i--)
		{
//			if(ar[i]!=48)
//			{
//				bunch=1;				
//			}
			//if(bunch==1)
			printf("%d",ar[i]-48);
		}
	}
	else if(flag==3)
	{
		for(int i=bat-1;i>=0;i--)
		{
			if(ar[i]!=48)
			{
				bunch=1;				
			}
			if(bunch==1)
			printf("%d",ar[i]-48);
		}
		printf("/");
		bunch=0;
		//int jet=0;
		for(int i=la-1;i>=bunch+3;i--)
		{
			if(ar[i]!=48)
			{
				bunch=1;				
			}
			if(bunch==1)
			printf("%d",ar[i]-48);
		}
	}
	else if(flag==4)
	{
		for(int i=la-2;i>=0;i--)
		{
			if(ar[i]!=48)
			{
				bunch=1;				
			}
			if(bunch==1)
			printf("%d",ar[i]-48);
		}
		printf("%");
	}
	return 0;
}