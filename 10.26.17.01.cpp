#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char password[20]={0};
	for(i=1;i<=3;i++)
	{
		scanf("%s",&password);
		if(strcmp(password,"原神")==0)
		{
			printf("启动！");
			break;
		}
		else
		printf("原来...");
	}
	if(3==i)
	printf("原来你也...");
	return 0;
}