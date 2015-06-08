#include "stack.h"
#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
void StackNew(stack*s, int elemSize)
{
	assert(elemSize > 0);
	s->elemSize = elemSize;
	s->logLength = 0;
	s->allocLength = 4;
	s->elems = malloc(4 * elemSize);
	assert(s->elems != NULL);
}

void StackDipose(stack* s)
{
	free(s->elems);
}

static void StackGrow(stack* s)
{
	s->allocLength *= 2;
	s->elems = realloc(s->elems, s->allocLength * s->elemSize);
	assert(s->elems != NULL);
}

void StackPush(stack* s, void* elemAddr)
{
	if(s->logLength == s->allocLength)
		StackGrow(s);
	void* target = (char*)s->elems + s->logLength * s->elemSize;
	memcpy(target, elemAddr, s->elemSize);
	s->logLength ++;
}

void StackPop(stack* s, void* elemAddr)
{
	void* source = (char*)s->elems + (s->logLength - 1) * s->elemSize;
	memcpy(elemAddr, source, s->elemSize);
	s->logLength --;
}



int main(int argc, char* argv[])
{
	return 0;
}
