/********************************/
/*************pure c*************/
/********************************/

#include "stdafx.h"
#include "stack.h"
#include <assert.h>
#include <malloc.h>

#define kInitialAllocationSize 4

int Stack_New(stack *s, unsigned int elemSize)
{
	assert(s != NULL);
	assert(elemSize != 0);
	if (s == NULL)
	{
		return -1;
	}

	if (elemSize == 0)
	{
		return -1;
	}
	s->elemSize = elemSize;
	s->logLenght = 0;
	s->allocLength = kInitialAllocationSize;
	s->elems = malloc(kInitialAllocationSize * elemSize);
	assert(s->elems != NULL);
	if (s->elems == NULL)
	{
		return -2;
	}

	return 0;
}

int StackDispose(stack *s)
{
	assert(s != NULL);
	if (s == NULL)
	{
		return -1;
	}
	free(s->elems);

	return 0;
}


int StackEmpty(const stack *s)
{
	assert(s != NULL);
	if (s == NULL)
	{
		return -1;
	}
	if (s->logLenght == 0)
	{
		return 0;
	}
	return 1;
}

int StackPush(stack *s, const void *elemAddr)
{
	assert(s != NULL);
	assert(elemAddr != NULL);
	if (s == NULL)
	{
		return -1;
	}
	if (elemAddr == NULL)
	{
		return -1;
	}
	void *destAddr;
	if (s->logLenght == s->allocLength)
	{
		s->allocLength *= 2;
		s->elems = realloc(s->elems, s->allocLength * s->elemSize);
		assert(s->elems != NULL);
		if (s->elems == NULL)
		{
			return -2;
		}
	}

	destAddr = (char *)s->elems + s->logLenght * s->elemSize;
	memcpy(destAddr, elemAddr, s->elemSize);
	s->logLenght++;

	return 0;
}

int StackPop(stack *s, void *elemAddr)
{
	const void *sourceAddr;
	assert(StackEmpty(s));
	if (s == NULL)
	{
		return -1;
	}
	s->logLenght--;
	sourceAddr = (const char*)s->elems + s->logLenght * s->elemSize;
	memcpy(elemAddr, sourceAddr, s->elemSize);

	return 0;
}
