#include<stdio.h>
float sum=0.0;
float feet=2.0;
int point=0;
float oj(float s)
{
	if(s<2.0)
	{
		printf("1");
		return 0;
	}
	if(point==0)
	{
		point++;
		sum+=2.0;
		return oj(s);
	}
	if(sum+0.98*feet>=s)
	{
		printf("%d",point+1);
		return 0;
	}
	else
	{
		point++;
		feet*=0.98;
		sum+=feet;
		return oj(s);	
	} 
}
int main()
{
	float s;
	scanf("%f",&s);
	oj(s);
	return 0;
}