#include<stdio.h>
struct game
{
	char name[10];
	int time;
	struct game *next;
};
int main()
{
	struct game game1={"wzry",999,NULL};
	struct game game2={"yyyy",889,NULL};
	struct game game3={"sfry",799,NULL};
	struct game game4={"dadd",699,NULL};
	struct game game5={"xxsw",599,NULL};
	game1.next=&game2;
	game2.next=&game3;
	game3.next=&game4;
	game4.next=&game5;
	struct game *head=&game1;
	struct game *p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->time);
		p=p->next;
    }
}