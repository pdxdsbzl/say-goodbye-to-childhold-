#include<stdio.h>
int main()
{
	int m,t,s;
	scanf("%d%d%d",&m,&t,&s);
	if(t==0)
	printf("0");
	else
//	{
//		
//	    float u=(float)s/t;
//	    int v=(int)u;
//	    if(v==u)
//	    printf("%d",m-v);
//	    else
//	    printf("%d",m-v-1);
//		return 0;
//	} 
	{
		if(s%t==0&&m-s/t>=0)
		{
			printf("%d",m-s/t);
		}
		else if(s%t==0&&m-s/t<0)
		{
			printf("0");
		}
		else if(s%t!=0&&m-s/t-1<=0)
		printf("0");
		else
		printf("%d",m-s/t-1);
	}
}
		