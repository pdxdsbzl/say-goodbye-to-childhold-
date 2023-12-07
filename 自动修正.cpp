#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100];
	scanf("%s",&str1);
	int m=strlen(str1);
	for(int i=0;i<=m-1;i++)
	{
		if(str1[i]<97||str1[i]>122)
		{
			printf("%c",str1[i]);
		}
		else
		printf("%c",str1[i]-32);
	}
}