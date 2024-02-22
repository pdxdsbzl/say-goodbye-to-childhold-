#include<stdio.h>
#include<math.h>
#include<string.h>
long long ar[2][2000000001]={0};
int main()
{
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int left=0,right=0;
		int le=0,ri=0;
		int n=0;
		scanf("%d",&n);
		memset(ar,0,sizeof(ar));
		int point=4;
		for(int j=0;j<n;j++)
		{
			int p=0,q=0;
			scanf("%d%d",&p,&q);
			ar[p][1000000000+1+q]=1;
			if(q<0)
			{
				le=1;
				if(left==0)
				{
					if(p==1)
			{			
				
				if(ar[p+1][(long long)pow(10,9)+1+q]==1||ar[p+1][(long long)pow(10,9)+1+q+1]==1||ar[p+1][(long long)pow(10,9)+1+q-1]==1)
				{
					point-=2;
					left=1;					
				}
		    }			
			else if(p==2)
			{
				if(ar[p-1][(long long)pow(10,9)+1+q]==1||ar[p-1][(long long)pow(10,9)+1+q+1]==1||ar[p-1][(long long)pow(10,9)+1+q-1]==1)
				{
					point-=2;
					left=1;	
				}
			}
				}
			}
			if(q>0)
			{
				ri=1;
				if(right==0)
				{
					if(p==1)
			{			
				
				if(ar[p+1][(long long)pow(10,9)+1+q]==1||ar[p+1][(long long)pow(10,9)+1+q+1]==1||ar[p+1][(long long)pow(10,9)+1+q-1]==1)
				{
					point-=2;
					right=1;					
				}
		    }			
			else if(p==2)
			{
				if(ar[p-1][(long long)pow(10,9)+1+q]==1||ar[p-1][(long long)pow(10,9)+1+q+1]==1||ar[p-1][(long long)pow(10,9)+1+q-1]==1)
				{
					point-=2;
					right=1;	
				}
			}
				}
			}
		
		
		}
		if(left==1&&right==1)
		{
			printf("0\n");
		}
		else if(left==1&&right==0)		
		{
			printf("%d\n",point-ri);
		}
		else if(left==0&&right==1)
		{
			printf("%d\n",point-le);
		}
		else
		printf("%d\n",point-le-ri);
	}
return 0;
}