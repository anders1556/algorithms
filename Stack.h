#ifndef _STACK_H_
#define _STACK_H_
typedef struct{
	void *elems;
	int elemSize;
	int logLength;
	int allocLength;
}stack;
void StackNew(stack* s, int elemsize);
void StackDispose(stack* s);
void StackPush(stack*s, void* elemAddr);
void StackPop(stack* s, void* elemAddr);
#endif
