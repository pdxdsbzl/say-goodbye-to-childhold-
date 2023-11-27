#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int A,B,E;
	int C=0;
	int m=0;
	int k=0;
	char a,b,c,d,e,f;
	scanf("%d%d%d",&A,&B,&E);
	int sz=sizeof E-1;
	char arr[sz];
	for(int i=0;i<=sz-1;i++)
    {
    	arr[i]=E/pow(10,sz-1-i);
    	int t=E/pow(10,sz-1-i);
    	E=E-t*pow(10,sz-1-i);//here problem
	}
    for(int i=0;i<=sz-1;i++)
    {
    	C+=arr[i]*pow(A,sz-1-i);
	}
	printf("%d",C);
}
//    int str[100];
//    for(int i=0;;i++)
//    {
//    	str[i]=C%B;
//    	if(C<B)
//    	{
//    	    k=i;
//    		break;
//		}
//    	C=C-C%B;
//    	C=C/B;
//	}
//	for(int i=0;i<=k;i++)
//	{
//		if(arr[i]==10)
//		arr[i]=a;
//		if(arr[i]==11)
//		arr[i]=b;
//		if(arr[i]==12)
//		arr[i]=c;
//		if(arr[i]==13)
//		arr[i]=d;
//		if(arr[i]==14)
//		arr[i]=e;
//		if(arr[i]==15)
//		arr[i]=f;
//	}
//	for(int i=k;i>=0;i--)
//	{
//	printf("%d",str[i]);
//    }
//    return 0;
//}