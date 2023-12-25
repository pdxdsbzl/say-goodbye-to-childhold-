#include<stdio.h>
#include<string.h>
char s1[505],s2[505];
int a[505],b[505],c[505];
int max(int m,int n)
{
	return m>n?m:n;
}
int main()
{
	int la,lb,lc;
	scanf("%s",s1);
	scanf("%s",s2);
	la=strlen(s1);
	lb=strlen(s2);
	for(int i=0;i<la;i++)
	a[la-i]=s1[i]-'0';//attention!!!! here -'0' to change char to int;it also dao xu;
	for(int i=0;i<lb;i++)
	b[lb-i]=s2[i]-'0';//-'0' is - the asc2 of '0';so it is int;
	lc=max(la,lb)+1;
	for(int i=1;i<=lc;i++)//because is dao xu,so we can from 1 to lc;
	{
		c[i]+=a[i]+b[i];
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[lc]==0&&lc>1)
	lc--;
	for(int i=lc;i>0;i--)
	printf("%d",c[i]);
	return 0;
}