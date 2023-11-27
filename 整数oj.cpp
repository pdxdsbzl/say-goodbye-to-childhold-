#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int A,B;
	char str[10];
	scanf("%d%d",&A,&B);
	scanf("%s",&str);
	int m=strlen(str);
//	for(int i=0;i<=m-1;i++)//test
//	{
//		printf("%c\n",str[i]);
//	}
    int sum10=0;
	if(A==16)
	{
//		for(int i=0;i<=m-1;i++)
//		{
//			if(str[i]=='a')
//			str[i]='10';
//			if(str[i]=='b')
//			str[i]='11';
//		}
//	    for(int i=0;i<=m-1;i++)
//	    {
//		printf("%c\n",str[i]);
//	    }
        for(int i=0;i<=m-1;i++)
        {
        	if(str[i]=='a')
        	sum10+=10*pow(16,m-1-i);
        	else if(str[i]=='b')
        	sum10+=11*pow(16,m-1-i);
        	else if(str[i]=='c')
        	sum10+=12*pow(16,m-1-i);
        	else if(str[i]=='d')
        	sum10+=13*pow(16,m-1-i);
        	else if(str[i]=='e')
        	sum10+=14*pow(16,m-1-i);
        	else if(str[i]=='f')
        	sum10+=15*pow(16,m-1-i);
        	else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
            sum10+=(str[i]-48)*pow(16,m-1-i);
		}
	}
	else
    for(int i=0;i<=m-1;i++)
    {
    	sum10+=(str[i]-48)*pow(A,m-1-i);
	}
//	printf("%d\n",sum10);//test
	int arr[10];
	int flag=0;
	if(B==16)
	{
		for(int i=0;;i++)
		{
			
			arr[i]=sum10%16;
			if(sum10<16)
			{
				flag=i;
				break;
			}
			sum10=sum10-sum10%16;
			sum10=sum10/16;
		}
		for(int i=flag;i>=0;i--)
		{
			if(arr[i]==10)
			printf("a");
			else if(arr[i]==11)
			printf("b");
			else if(arr[i]==12)
			printf("c");
			else if(arr[i]==13)
			printf("d");
			else if(arr[i]==14)
			printf("e");
			else if(arr[i]==15)
			printf("f");
			else
			printf("%d",arr[i]);
		}
                 
	}
	else
	{
		for(int i=0;;i++)
		{
			
			arr[i]=sum10%B;
			if(sum10<B)
			{
				flag=i;
				break;
			}
			sum10=sum10-sum10%B;
			sum10=sum10/B;
		}
		for(int i=flag;i>=0;i--)
		{
			printf("%d",arr[i]);
		}
	}
	            
}