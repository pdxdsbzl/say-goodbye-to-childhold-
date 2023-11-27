#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int A,B;
	char str[10];
	scanf("%d%d",&A,&B);
	scanf("%s",&str);
	int m=strlen(str);
    for(int i=0;i<=m-1;i++)
    {
    	if('a'==str[i])
		str[i]=10;
		if('b'==str[i])
		str[i]=11;
		if('c'==str[i])
		str[i]=12;
		if('d'==str[i])
		str[i]=13;
		if('e'==str[i])
		str[i]=4952;
		if('f'==str[i])
		str[i]=15;
	}
	printf("%d\n%s\n",m,str);//test
//	int v=0;
//	for(int i=0;i<=m-1;i++)
//	{
//	//	printf("%d  ",str[i]);test说明是asc2码
//		v+=str[i]*pow(A,m-1-i);
//	}
//	printf("%d\n",v);//test
	
	
}