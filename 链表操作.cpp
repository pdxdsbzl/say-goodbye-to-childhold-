#include "stdio.h"
#include "stdlib.h"

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int a[], int n)//REMEMBER delete ";"
{//HERE
struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    for (int i = 0; i < n; i++) 
	{
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = a[i];
        node->next = NULL;
        if (head == NULL) 
		{
            head = node;
        } 
		else 
		{
            prev->next = node;
        }
        prev = node;
    }
    return head;
}//HERE       OK!!!!!!!

struct ListNode *sortList(struct ListNode *head)//The (struct ListNode *head) here means the hanshu will accept one zhi xiang struct ListNode de zhi zheng zuo wei can shu. 
{//HERE
	if (head == NULL || head->next == NULL) 
	{
        return head;
    }
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *lastSorted = head, *curr = head->next;

    while (curr != NULL) 
	{
        if (lastSorted->val <= curr->val) 
		{
            lastSorted = lastSorted->next;
        } 
		else 
		{
            struct ListNode *prev = dummy;
            while (prev->next->val <= curr->val)
			{
                prev = prev->next;
            }
            
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        
        curr = lastSorted->next;
    }
    
    head = dummy->next;//because mabey the smallest will change.
    free(dummy);
    return head;
}//HERE

void output(struct ListNode *head)//
{//HERE
     while (head != NULL) 
	{
        printf("%d\n", head->val);
        head = head->next;
    }
 //   printf("\n");
}//HERE

struct ListNode *insertNode(struct ListNode *head, int n)//
{//HERE
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = n;

    if (head == NULL || n < head->val)
	{
        node->next = head;
        return node;
    }

    struct ListNode *curr = head;
    while (curr->next != NULL && curr->next->val < n) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;

    return head;
}//HERE

struct ListNode *removeNode(struct ListNode *head, int n)//
{//HERE
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy, *curr = head;

    while (curr != NULL)
	{
        if (curr->val == n) 
		{
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } 
		else 
		{
            prev = curr;
            curr = curr->next;
        }
    }

    head = dummy->next;
    free(dummy);
    return head;
}//HERE

int main() {
    int a[10000];
    int n, ins, rm;
    scanf("%d", &n);
    scanf("%d", &ins);
    scanf("%d", &rm);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    struct ListNode *list = createList(a, n);
    output(list);
    list = sortList(list);
    output(list);
    list = insertNode(list, ins);
    output(list);
    list = removeNode(list, rm);
    output(list);
    return 0;
}