//#include<stdio.h>
//int main()
//{
//	long l,m;
//	long n=0;
//	scanf("%ld%ld",&l,&m);
//	long u[m],v[m];
//	for(int i=0;i<=m-1;i++)
//	{
//		scanf("%ld%ld",&u[i],&v[i]);
//	}
//	long min=u[0];
//	long max=v[0];
//	for(int i=1;i<=m-1;i++)
//	{
//		if(min<=u[i]&&v[i]<=max)
//		{
//			continue;
//		}
//		if(v[i]<min)
//		{
//			n-=(v[i]-u[i]+1);
//		}
//		if(u[i]<min&&min<=v[i]&&v[i]<=max)
//		{
//			min=u[i];
//		}
//		if(min<=u[i]&&u[i]<=max&&max<v[i])
//		{
//			max=v[i];
//		}
//		if(max<u[i])
//		{
//			n-=(v[i]-u[i]+1);
//		}
//	}
//	n+=l+1-(max-min+1);
//	printf("%ld",n);
//	return 0;
//}//错了！！会重复！！因为你单列的减去的可能会重复减去！！！！！
#include<stdio.h>                      
int main()                             
{                                      
 int L,M;//L道路长度M代表区域数目    
 int i,initial,end,l=0,nb=0;       
scanf("%d%d",&L,&M);                  
int road[L+1]; //代表数轴的长度上的每一个节点                       
for(i=0;i<=L;i++)                     
 road[i]=0;        //0表示节点上有树木                 
for(i=0;i<M;i++){                     
scanf("%d%d",&initial,&end);          
     for(l=initial;l<=end;l++)         
  road[l]=1;     //1表示该节点的树被砍伐了。                   
}                                     
   for(i=0;i<L+1;i++){                 
  if(road[i]==0)                     
    nb++;  //计算有树木的节点的数量                           
    }                                  
printf("%d",nb);                      
return 0;                            
}