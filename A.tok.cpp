#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int point=0;
		switch(a)
		{
			case 100:point+=0;break;
			case 150:point+=1;break;
			case 200:point+=2;break;
		}
		if(b>=34&&b<=40)
		point++;
		else if(b==45)
		point+=2;
		if(c>=34&&c<=40)
		point++;
		else if(c==45)
		point+=2;
		printf("%d\n",point);
	}
	return 0;
}