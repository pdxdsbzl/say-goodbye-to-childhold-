#include<stdio.h>
struct linknode
{
	int data;
	struct linknode *next;
};
int main()
{
	struct linknode node1{10,NULL};
	struct linknode node2{20,NULL};
	struct linknode node3{30,NULL};
	struct linknode node4{40,NULL};
	struct linknode node5{50,NULL};
	struct linknode node6{60,NULL};
	node1.next=&node2;
	node2.next=&node3;
	node3.next=&node4;
	node4.next=&node5;
	node5.next=&node6;
	struct linknode *m=&node1;//辅助指针变量!!!
	while(m!=NULL)
	{
		printf("%d\n",m->data);
		m=m->next;
	}
	
}