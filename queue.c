#include "stdafx.h"
#include "queue.h"
#include <assert.h>
#include <malloc.h>

int initQue(queue *q, unsigned int elemSize)
{
	assert(q != NULL);
	assert(elemSize != 0);

	if (q == NULL)
	{
		return -1;
	}
	if (elemSize == 0)
	{
		return -1;
	}

	Stack_New(&(q->deStack),elemSize);
	Stack_New(&(q->enStack),elemSize);
	q->size = 0;

	return 0;
}
int diposeQue(queue *q)
{
	assert(q != NULL);
	if (q == NULL)
	{
		return -1;
	}

	StackDispose(&(q->deStack));
	StackDispose(&(q->enStack));
	q->size = 0;

	return 0;
}
int enque(queue *q, const void *elemAddr)
{
	assert(q != NULL);
	assert(elemAddr != NULL);

	if (q == NULL)
	{
		return -1;
	}
	if (elemAddr == NULL)
	{
		return -1;
	}

	q->size++;
	StackPush(&(q->enStack), elemAddr);

	return 0;
}

int deque(queue *q, void *elemAddr)
{
	assert(q != NULL);
	assert(elemAddr != NULL);

	if (q == NULL)
	{
		return -1;
	}
	if (elemAddr == NULL)
	{
		return -1;
	}

	if (isEmpty(q) == 0)
	{
		return -2;
	}

	q->size--;

	if (StackEmpty(&(q->deStack)) != 0)
	{
		StackPop(&(q->deStack),elemAddr);
		return 0;
	}
	void *tmpElem = malloc(q->enStack.elemSize);
	if (tmpElem == NULL)
	{
		return -2;
	}

	while (StackEmpty(&(q->enStack)) != 0)
	{
		StackPop(&(q->enStack), tmpElem);
		StackPush(&(q->deStack), tmpElem);
	}

	StackPop(&(q->deStack),elemAddr);

	return 0;
}
int isEmpty(queue *q)
{
	assert(q != NULL);
	if (q == NULL)
	{
		return -1;
	}
	if (q->size != 0)
	{
		return 1;
	}
	if (StackEmpty(&(q->deStack)) != 0 && StackEmpty(&(q->enStack)) != 0)
	{
		return 1;
	}
	return 0;
}
