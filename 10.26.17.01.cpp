#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char password[20]={0};
	for(i=1;i<=3;i++)
	{
		scanf("%s",&password);
		if(strcmp(password,"ԭ��")==0)
		{
			printf("������");
			break;
		}
		else
		printf("ԭ��...");
	}
	if(3==i)
	printf("ԭ����Ҳ...");
	return 0;
}