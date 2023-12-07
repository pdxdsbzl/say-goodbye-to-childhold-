#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode *createlist(int a[],int n)//1.createlist ǰ��Ҫ��*��ʾ��������᷵�ص�һ��struct ListNode���͵�ָ��
{
	struct ListNode *head=NULL;
	struct ListNode *prev=NULL;
	for(int i=0;i<n;i++)
	{
		struct ListNode *node=(struct ListNode*)malloc(sizeof(struct ListNode));//2.����node��Ҫ��forѭ���ڲ��������ܶ������ռ�
		node->val=a[i];//3.node��val��next���ʱ�����->!!!��������. ��Ϊnode�ǵ�ַ(ָ��)������
		node->next=NULL;//4.the same with 3
		if(head==NULL)//5.��ַ�ж�ͬ��Ҫ��==!!!������=!!!!
		{
			head=node;
		}
		else
		{
			prev->next=node;
		}
		prev=node;
	}
	return head;
}
struct ListNode *sortlist(struct ListNode *head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next=head;
	struct ListNode *Lastsorted =head,*curr=head->next;
	while(curr!=NULL)
	{
		if(Lastsorted->val<=curr->val)
		{
			Lastsorted=Lastsorted->next;//6.������curr��������?
		}
		else
		{
			struct ListNode *prev=dummy;
			while(prev->next->val<=curr->val)
			{
				prev=prev->next;
			}
			Lastsorted->next=curr->next;//7.Do not forget it!!!!
			curr->next=prev->next;
			prev->next=curr;
		}
		curr=Lastsorted->next;
	}
	head=dummy->next;
	free(dummy);
	return head;
}
void output(struct ListNode *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->val);
		head=head->next;
	}
}
struct ListNode *insertNode(struct ListNode* head,int n)
{
	struct ListNode *node=(struct ListNode*)malloc(sizeof(struct ListNode));
	node->val=n;
	if(head==NULL||head->val>=n)
	{
		node->next=head;
		return node;
	}
	else
	{
		struct ListNode *curr=head;
		while(curr->next->val<=node->val&&curr->next!=NULL)
		{
			curr=curr->next;
		}
		node->next=curr->next;
		curr->next=node;
		return head;
	}
}
struct ListNode *removeNode(struct ListNode* head,int n)
{
	struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next=head;
	struct ListNode *prev=dummy,*curr=head;
	while(curr!=NULL)
	{
		if(curr->val==n)
		{
			prev->next=curr->next;
			free(curr);
			break;
		//	curr=prev->next;//8.��������𣿿���ɾ�ɣ�Ȼ���ټ�һ��break?  OK���Ѿ��޸��ˣ���仰ȷʵû�ã����ҿ��Լ�break!!!
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
	head=dummy->next;
	free(dummy);
	return head;
}
int main()
{
	int a[10000];
    int n, ins, rm;
    scanf("%d", &n);
    scanf("%d", &ins);
    scanf("%d", &rm);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    struct ListNode *list = createlist(a, n);
    output(list);
    list = sortlist(list);
    output(list);
    list = insertNode(list, ins);
    output(list);
    list = removeNode(list, rm);
    output(list);
    return 0;
}