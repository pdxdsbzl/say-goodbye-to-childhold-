#include<stdio.h>
int main()
{
	int arr1[3];
	char str[4];
	scanf("%d%c%d%c%d%c%c",&arr1[0],&str[0],&arr1[1],&str[1],&arr1[2],&str[2],&str[3]);
	if(str[3]=='X')
	{
		str[3]=10+48;//!!!!ATTENTION here !!!!!!!!!!+48!!!because it's ASC2!!!!!look the content under it!!!!!
	}
	int arr2[10];
	arr2[0]=arr1[0];
	arr2[1]=arr1[1]/100;
	arr2[2]=(arr1[1]-arr2[1]*100)/10;
	arr2[3]=arr1[1]-arr2[1]*100-arr2[2]*10;
	arr2[4]=arr1[2]/10000;
	arr2[5]=(arr1[2]-arr2[4]*10000)/1000;
	arr2[6]=(arr1[2]-arr2[4]*10000-arr2[5]*1000)/100;
	arr2[7]=(arr1[2]-arr2[4]*10000-arr2[5]*1000-arr2[6]*100)/10;
	arr2[8]=(arr1[2]-arr2[4]*10000-arr2[5]*1000-arr2[6]*100-arr2[7]*10);
	arr2[9]=(int)str[3];
	int tail=(arr2[0]*1+arr2[1]*2+arr2[2]*3+arr2[3]*4+arr2[4]*5+arr2[5]*6+arr2[6]*7+arr2[7]*8+arr2[8]*9)%11;
//	printf("%d",arr2[9]);//WOC!!!!!!!!WOC!!!!!!!!!!NBNBNB!!!from here ,we can know that it still exist as ASC2 ma!!!!!!!!though we force it from char into int!!!!!!
	if(arr2[9]-48==tail)
	{
		printf("Right");
	}
	else
	{
		if(tail!=10)
		printf("%d-%d%d%d-%d%d%d%d%d-%d",arr2[0],arr2[1],arr2[2],arr2[3],arr2[4],arr2[5],arr2[6],arr2[7],arr2[8],tail);
		else
		printf("%d-%d%d%d-%d%d%d%d%d-X",arr2[0],arr2[1],arr2[2],arr2[3],arr2[4],arr2[5],arr2[6],arr2[7],arr2[8]);
	}
	
}