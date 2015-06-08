#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode * next;
}ListNode, *PListNode;

PListNode reverse(PListNode head)//每次都返回头结点
{
	if(head == NULL || head->next == NULL)
		return head;//如果为空或者只有一个节点直接返回
	PListNode t = reverse(head->next);//这一步不能直接返回，否则在下一步执行后，就不对了
	head->next->next = head;//head->next 现在是第二个节点，逆序后变成倒数第二个节点
	head->next = NULL;
	return t;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *head = (PListNode) malloc(sizeof(ListNode));
	head->next = NULL;
	head->data = 0;

	for(int i=10; i>0; i--)
	{
		PListNode q = (PListNode)malloc(sizeof(ListNode));
		q->data = i;
		q->next = NULL;
		
		q->next=head->next;
		head->next = q;
	}
	head = reverse(head);
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	system("pause");
	return 0;
}
