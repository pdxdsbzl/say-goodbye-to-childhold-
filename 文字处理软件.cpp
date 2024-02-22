#include<stdio.h>
#include<string.h>
int u,v;
char ar[100]={0};
char br[100]={0};
char cr[100]={0};
char dr[100]={0};
void one()
{
	memset(br,0,sizeof(br));
	scanf("%s",&br);
	strcat(ar,br);
	printf("%s\n",ar);
}
void two()
{
	scanf("%d%d",&u,&v);
	int w=strlen(ar);
	for(int i=0;i<w;i++)
	{
		cr[i]=ar[i];
	}
	memset(ar,0,sizeof(ar));
	for(int i=0;i<v;i++)
	{
		ar[i]=cr[i+u];
	}
	printf("%s\n",ar);
}
void three()
{
	int s;
	scanf("%d",&s);
	memset(dr,0,sizeof(dr));
	scanf("%s",&dr);
	memset(cr,0,sizeof(cr));
	int h=strlen(ar);
	for(int i=s;i<h;i++)
	{
		cr[i-s]=ar[i];
		ar[i]=0;
	}
	strcat(ar,dr);
	strcat(ar,cr);
	printf("%s\n",ar);
}
void four()
{
	memset(dr,0,sizeof(dr));
	scanf("%s",dr);
	//int f=strlen(dr);
	char *ret=strstr(ar,dr);
	printf("%d\n",ret!=NULL?(int)(ret-ar):-1);
	
}
int main()
{
	int q,p;
	scanf("%d",&q);
	scanf("%s",&ar);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&p); 
		switch(p)
		{
			case 1:one();
			break;
			case 2:two();
			break;
			case 3:three();
			break;
			case 4:four();
			break;
			default:break;
		}
	}


//one();
//two();
//three();
//four();
	return 0;
}