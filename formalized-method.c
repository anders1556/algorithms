#include <stdio.h>
#include <malloc.h>
#define NIL 0


#define (x)++(y) cons(x,cons(y,nil()))

#define LIST(X) \
    struct list2 \
	{\
	   X data; \
	   struct list2 * next;\
	}
#if 0
struct list
{
	int data;
	struct list *next;
};

struct list *nil()
{
	return NIL;
}

struct list * cons(int data,struct list *next)
{
	struct list *l = malloc(sizeof(*l));
	l->data = data;
	l->next =next;
	return l;
}

void print(struct list *l)
{
	if(l==NULL)
	    return ;
	else 
	    printf("%d ",l->data);
	print(l->next);
	return ;
}
#endif


#define struct list *cons(X data,struct list *next)\
{\
	    struct list *l = (struct list *)malloc(sizeof(*l));\
	    l->data = data;\
	    l->next = next;\
    	    return l;\
}
int main()
{
    	struct list *l=
	    cons(1,cons(2,cons(3,nil())));
	struct list *i=(1)++(2)++(3);
	print(l);
	//rintf("hello,world!");
	return 0;
}
