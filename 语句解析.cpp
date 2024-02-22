#include<stdio.h>
#include<string.h>
char ar[10010]={0};
int main()
{
	scanf("%s",ar);
	int la=strlen(ar);
	
	//printf("%d",la);
	
	int a,b,c;
	for(int i=0;i<la/5;i++)
	{
		
		char x,y;
		//scanf("%c:=%c;",&x,&y);
		x=ar[i*5];
		y=ar[i*5+3];
		if(x=='a')
		{
			if(y=='b')
			a=b;
			else if(y=='c')
			a=c;
			else if(y>='0'&&y<='9')
			a=y-48;
		}
		if(x=='b')
		{
			if(y=='a')
			b=a;
			else if(y=='c')
			b=c;
			else if(y>='0'&&y<='9')
			b=y-48;
		}
		if(x=='c')
		{
			if(y=='a')
			c=a;
			else if(y=='b')
			c=b;
			else if(y>='0'&&y<='9')
			c=y-48;
		}
	}
	printf("%d %d %d",a,b,c);
	return 0;
}
	