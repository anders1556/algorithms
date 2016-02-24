#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stack.h"

typedef struct
{
	stack deStack;
	stack enStack;
	unsigned int size;
}queue;

extern int initQue(queue *q, unsigned int elemSize);
extern int diposeQue(queue *q);
extern int enque(queue *q, const void *elemAddr);
extern int deque(queue *q, void *elemAddr);
extern int isEmpty(queue *q);

#endif
