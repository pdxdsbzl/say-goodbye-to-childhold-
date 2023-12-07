#include<stdio.h>
#include<string.h>
struct ST
{
	int id;
	char name[10];
	float score;
};
int main()
{
	struct ST x={2023,"lihua",300.0};
	printf("%s",x.name);
	struct ST y=x;
//	strcpy(y.id,302503);
	printf("%d",y.id);
}