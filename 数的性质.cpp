#include<stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	int point=0;
	if(m%2==0)
	point++;
	if(m>4&&m<=12)
	point++;
	switch(point)
	{
		case 2:printf("1 1 0 0");
		break;
		case 1:printf("0 1 1 0");
		break;
		case 0:printf("0 0 0 1");
		break;
	}
	return 0;
}