#include<stdio.h>
#include<string.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	char str1[50];
	scanf("%s",str1);
//	printf("%c",str1[0]);//test
    int m=strlen(str1);
//    printf("%d",m);//test:OK
	for(int i=0;i<=m-1;i++)
	{
		if(str1[i]<123-n)
		{
			printf("%c",str1[i]+n);
		}
		else
		printf("%c",97+(n-(123-str1[i])));
	}
}