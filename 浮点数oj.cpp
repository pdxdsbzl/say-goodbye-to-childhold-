#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int A,B;
	scanf("%d%d",&A,&B);
	char str[10]={0};
	scanf("%s",&str);
	int m=strlen(str);
//	printf("%d\n",m);//test:contain  poiont EG:3.14=4 OK
	int flag1=0;
	double sum10=0;
	int point=0;//here is to put if a zheng shu into xiaoshu (plus .0)
	for(int i=0;i<=m-1;i++)
	{
		if(str[i]=='.')
		{
			point=1;
			break;
		}
	}
	if(point==0)
	{
		str[m]='.';
		str[m+1]=0;
		m=m+2;
	}
	
	for(int i=0;i<=m-1;i++)
	{
		if(str[i]=='.')
		{
			flag1=i;
			break;
		}
	}
	if(A==16)
	{
		for(int i=0;i<=m-1;i++)
		{
			if(i<flag1)
			{
				if(str[i]=='a')
				sum10+=10*pow(16,flag1-i-1);
				else if(str[i]=='b')
				sum10+=11*pow(16,flag1-i-1);
				else if(str[i]=='c')
				sum10+=12*pow(16,flag1-i-1);
				else if(str[i]=='d')
				sum10+=13*pow(16,flag1-i-1);
				else if(str[i]=='e')
				sum10+=14*pow(16,flag1-i-1);
				else if(str[i]=='f')
				sum10+=15*pow(16,flag1-i-1);
				else
				sum10+=(str[i]-48)*pow(16,flag1-i-1);
			}
			if(i==flag1)
			continue;
			if(i>flag1)
			{
				if(str[i]=='a')
				sum10+=10*pow(16,flag1-i);
				else if(str[i]=='b')
				sum10+=11*pow(16,flag1-i);
				else if(str[i]=='c')
				sum10+=12*pow(16,flag1-i);
				else if(str[i]=='d')
				sum10+=13*pow(16,flag1-i);
				else if(str[i]=='e')
				sum10+=14*pow(16,flag1-i);
				else if(str[i]=='f')
				sum10+=15*pow(16,flag1-i);
				else
				sum10+=(str[i]-48)*pow(16,flag1-i);
			}
		}
		
	}
	else
	{
        for(int i=0;i<=m-1;i++)
        {
        	if(i<flag1)
        	{
        		sum10+=(str[i]-48)*pow(A,flag1-i-1);
			}
			if(i==flag1)
			{
				continue;
			}
			if(i>flag1)
			{
				sum10+=(str[i]-48)*pow(A,flag1-i);
			}
		}
	}
//	printf("%f",sum10);//test. to here ,it'OK,turn it into 10jinzhi.
	//next we turn it into Bjinzhi.
	double sum10foot=sum10-(int)sum10;
	int sum10head=(int)sum10;
//	printf("\n%d\n%f",sum10head,sum10foot);//test :OK
	int flag2=0;
	char arr1[20];
	char arr2[10];
	if(B==16)
	{
		for(int i=0;;i++)
		{
			arr1[i]=sum10head%16;
			if(sum10head<16)
			{
				flag2=i;
				break;
			}
			sum10head-=arr1[i];
			sum10head=sum10head/16;
		}
		for(int i=flag2;i>=0;i--)
		{
			if(arr1[i]==10)
			printf("a");
			else if(arr1[i]==11)
			printf("b");
			else if(arr1[i]==12)
			printf("c");
			else if(arr1[i]==13)
			printf("d");
			else if(arr1[i]==14)
			printf("e");
			else if(arr1[i]==15)
			printf("f");
			else
			printf("%d",arr1[i]);
			
		}
		for(int i=0;i<=7;i++)//because it need 8 point 
		{
			sum10foot=sum10foot*16;
			arr2[i]=(int)sum10foot;
			sum10foot-=arr2[i];
		}//duo le ye bu pa ,because shu zu hou mian dou shi 0,shu chu dou shi 0.
		int point2=0;
		for(int i=0;i<=7;i++)
		{
			if(arr2[i]!=0)
			{
				point2=1;
				break;
			}
		}
		if(point2==1)//pan duan yao bu yao shu chu .xiao shu
		{
		printf(".");//DON'T forget it!!!
		for(int i=0;i<=7;i++)
		{
		int point3=0;
		for(int k=i;k<=7;k++)
		{
			if(arr2[k]!=0)
			{
				point3=1;
				break;
			}
		}
		if(point3==1)
		{
			if(arr2[i]==10)
			printf("a");
			else if(arr2[i]==11)
			printf("b");
			else if(arr2[i]==12)
			printf("c");
			else if(arr2[i]==13)
			printf("d");
			else if(arr2[i]==14)
			printf("e");
			else if(arr2[i]==15)
			printf("f");
			else
			printf("%d",arr2[i]);
		}
			
		}
		}	
	}
	else
	{
		for(int i=0;;i++)
		{
			arr1[i]=sum10head%B;
			if(sum10head<B)
			{
				flag2=i;
				break;
			}
			sum10head-=arr1[i];
			sum10head=sum10head/B;
		}
		for(int i=flag2;i>=0;i--)
		{
			printf("%d",arr1[i]);
		}
		for(int i=0;i<=7;i++)//because it need 8 point 
		{
			sum10foot=sum10foot*B;
			arr2[i]=(int)sum10foot;
			sum10foot-=arr2[i];
		}//duo le ye bu pa ,because shu zu hou mian dou shi 0,shu chu dou shi 0.
		int point2=0;
		for(int i=0;i<=7;i++)
		{
			if(arr2[i]!=0)
			{
				point2=1;
				break;
			}
		}
		if(point2==1)
		{
		printf(".");//DON'T forget it!!!
		for(int i=0;i<=7;i++)
		{
			int point3=0;
		for(int k=i;k<=7;k++)
		{
			if(arr2[k]!=0)
			{
				point3=1;
				break;
			}
		}
		if(point3==1)
		{
			printf("%d",arr2[i]);
		}
		}
		}
	}//Problem:1.bu gou jing que;2.can not zhengshu but need xiaoshu .
}