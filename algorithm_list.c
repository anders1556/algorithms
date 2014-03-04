#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct List
{
	int value;
	List * next;
};

List * Create(int length)
{
	List * head = NULL;

	srand( (unsigned) time(NULL));
	for(int i=0; i<length; ++i){
		List * node = new List;
		node->value = rand()%100;
		node->next = head;
		head = node;
	}

	return head;
}

void Print(List * head)
{
	if(head == NULL)
		return ;
	while(head != NULL)
	{
		printf("%d ",head->value);
		head = head->next;
	}
}

List * InsertHead(int value,List *head)
{
	List * node = new List;
	node->value = value;
	node->next = head;
	head = node;

	return head;
}

List * Inverse(List * head)
{
	if(head == NULL)
		return NULL;
	if(head ->next == NULL)
		return head;

	List * p = head;
	List * q = p->next;
	head = NULL;
	while(q != NULL)
	{
		p->next = head;
		head = p;
		p = q;
		q = q->next;
	}
	p->next = head;
	head = p;

	return head;
}
