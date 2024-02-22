#include<stdio.h>
#include<string.h>
char ar[20]={0};
char br[10000100]={0};
int main()
{
	int anwser=0;
	int point=0;
	gets(ar);
	gets(br);
//	scanf("%s\n",&ar);
//	scanf("%[^\n]",&br);

	//scanf("%[^\n]",&br);//&???????????
//	int s=strlen(ar);
//	ar[s-1]='0';

	for(int i=0;i<strlen(ar);i++)
	{
		if(ar[i]<97)
		ar[i]=ar[i]+32;
	}
	for(int i=0;i<strlen(br);i++)
	{
		if(br[i]>64&&br[i]<91)
		br[i]=br[i]+'a'-'A';
	}
//	printf("%s\n",ar);
//	printf("%s",br);

	while(1)
	{
		char *ret=strstr(br,ar);
		if(ret==NULL)
		{
			//printf("-1");
			break;
		}
		else
		{
			
			int w=(int)(ret-br);
			if(br[w+strlen(ar)]==' '&&(w==0||br[w-1]==' '))
			{
				
				//br[w]='6';
				point++;
				if(point==1)
				anwser=w;
			}
			br[w]='6';
		}
	}
	if(point==0)
	{
		printf("-1"); 
		return 0;
	}
	else
	{
		printf("%d %d",point,anwser);
		return 0;
	}
}