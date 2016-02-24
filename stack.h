#ifndef __STACK_H__
#define __STACK_H__

typedef struct 
{
	void	*elems;
	int		elemSize;
	int		logLenght;
	int		allocLength;
}stack;

extern int Stack_New(stack *s, unsigned int elemSize);
extern int StackDispose(stack *s);
extern int StackEmpty(const stack *s);
extern int StackPush(stack *s, const void *elemAddr);
extern int StackPop(stack *s, void *elemAddr);


#endif
