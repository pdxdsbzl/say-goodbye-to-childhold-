#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int A,B;
	scanf("%d%d",&A,&B);
	char str[10];
	scanf("%s",&str);
	int m=strlen(str);
//	printf("%d",m);//test:contain the point .EX:0.12=4,,,3.14=4
    float sum10=0.0;
    int flag=0;
    for(int i=0;i<=m-1;i++)
    {
    	if(str[i]=='.')
    	flag=i;
	}
	if(A==16)
	{
		for(int i=0;i<=m-1;i++)
		{
			if(i<flag)
			{
				if(str[i]=='a')
	    	    sum10+=10/pow(16,i+3-m);
	    	    else if(str[i]=='b')
	    	    sum10+=11/pow(16,i+3-m);
	    	    else if(str[i]=='c')
	    	    sum10+=12/pow(16,i+3-m);
	    	    else if(str[i]=='d')
	    	    sum10+=13/pow(16,i+3-m);
	    	    else if(str[i]=='e')
	    	    sum10+=14/pow(16,i+3-m);
	    	    else if(str[i]=='f')
	    	    sum10+=15/pow(16,i+3-m);
	    	    else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
	            sum10+=(str[i]-48)/pow(16,i+3-m);
			}
			if(i==flag)
			continue;
			if(i>flag)
			{
			    if(str[i]=='a')
	        	sum10+=10/pow(16,m-i);
	        	else if(str[i]=='b')
	        	sum10+=11/pow(16,m-i);
	        	else if(str[i]=='c')
	        	sum10+=12/pow(16,m-i);
	        	else if(str[i]=='d')
	        	sum10+=13/pow(16,m-i);
	        	else if(str[i]=='e')
	        	sum10+=14/pow(16,m-i);
	        	else if(str[i]=='f')
	        	sum10+=15/pow(16,m-i);
	        	else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
	            sum10+=(str[i]-48)/pow(16,m-i);
	        }
        }
	}
	else
	{
		for(int i=0;i<=m-1;i++)
		{
			if(i<flag)
			{
	            sum10+=(str[i]-48)/pow(A,i+3-m);
			}
			if(i==flag)
			{
				continue;
			}
			if(i>flag)
			{
				sum10+=(str[i]-48)/pow(A,m-i);
			}
		}
	}
	printf("%f",sum10);//test:OK.
//to here,we have already change the C into 10 jin zhi ,and then we need to change it into B jin zhi.
//look the test.
//     float sumB=0.0;//11.14
//     float sum10foot=sum10-(int)sum10;
//     int sum10head=sum10-sum10foot;
//     int arr[10];
//	int flag2=0;
//	if(B==16)
//	{
//		for(int i=0;;i++)
//		{
//			
//			arr[i]=sum10head%16;
//			if(sum10head<16)
//			{
//				flag2=i;
//				break;
//			}
//			sum10head=sum10head-sum10head%16;
//			sum10head=sum10head/16;
//		}
//		for(int i=flag2;i>=0;i--)//ATTENTION i--!!!
//		{
//			if(arr[i]==10)
//			printf("a");
//			else if(arr[i]==11)
//			printf("b");
//			else if(arr[i]==12)
//			printf("c");
//			else if(arr[i]==13)
//			printf("d");
//			else if(arr[i]==14)
//			printf("e");
//			else if(arr[i]==15)
//			printf("f");
//			else
//			printf("%d",arr[i]);
//		}
//                 
//	}
//	else
//	{
//		for(int i=0;;i++)
//		{
//			
//			arr[i]=sum10head%B;
//			if(sum10head<B)
//			{
//				flag2=i;
//				break;
//			}
//			sum10head=sum10head-sum10head%B;
//			sum10head=sum10head/B;
//		}
//		for(int i=flag2;i>=0;i--)
//		{
//			printf("%d",arr[i]);
//		}
//	}
//	int shuzu[10];
//	int flag3=0;
//	if(sum10foot!=0.0)
//	{
//		printf(".");//to here :OK
//		if(B==16)
//		{
//			for(int i=0;i<=7;i++)//because need 8 xiao shu.
//			{
//				if(sum10foot==0.0)
//				{
//					flag3=i;
//					break;
//				}
//				if(i==7)
//				{
//					flag3=7;
//				}
//				sum10foot=sum10foot*16;
//				shuzu[i]=(int)sum10foot;
//				sum10foot=sum10foot-(int)(sum10*16);
//			}
//			for(int i=0;i<=flag3;i++)//ATTENTION i++!!
//			{
//				if(shuzu[i]==10)
//				printf("a");
//				else if(shuzu[i]==11)
//				printf("b");
//				else if(shuzu[i]==12)
//				printf("c");
//				else if(shuzu[i]==13)
//				printf("d");
//				else if(shuzu[i]==14)
//				printf("e");
//				else if(shuzu[i]==15)
//				printf("f");
//				else
//				printf("%d",shuzu[i]);
//			}
//		}
//		else
//		{
//			for(int i=0;i<=7;i++)//because need 8 xiao shu.
//			{
//				if(sum10foot==0.0)
//				{
//					flag3=i;
//					break;
//				}
//				if(i==7)
//				{
//					flag3=7;
//				}
//				sum10foot=sum10foot*B;
//				shuzu[i]=(int)sum10foot;
//				sum10foot=sum10foot-(int)(sum10*B);
//			}
//		    for(int i=0;i<=flag3;i++)//ATTENTION i++!!
//			{
//				printf("%d",shuzu[i]);
//			}
//		}		
//	
//    }
}