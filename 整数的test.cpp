#include<stdio.h>
#include<string.h>
int main()
{//可见char类型的数组存的其实是ASCii码！！！！！
     char str[10];
     scanf("%s",&str);
     int m=strlen(str);
     printf("%d\n",m);
     printf("%s\n",str);
     for(int i=0;i<=9;i++)
     {
     	printf("%d  ",str[i]);
	 }
}