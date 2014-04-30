/*
 * list_head.c
 *
 *  Created on: 2014年4月30日
 *      Author: houbo
 */

#include<stdio.h>

struct list_head{
	struct list_head *next, *prev;
};

struct person{
	int age;
	int weight;
	struct list_head *list;
};

struct animal{
	int age;
	int weight;
	struct list_head *list;
};

#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
#define INIT_LIST_HEAD(ptr) do{\
		(ptr)->next = (ptr);(ptr)->prev =(ptr);\
}while(0)

static inline void __list_add();
static inline void list_add();
static inline void list_add_tail();

/*
 * __list_add -  Insert a new entry between two known consecutive entries.
 *
 * @new:
 * @prev:
 * @next:
 * This is only for internal list manipulation where we konw the prev/next
 * entries already!
 *
 * */

static void __list_add(struct list_head * new,
				struct list_head * prev, struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
* list_add - add a new entry
* @new:
new entry to be added
* @head:
list head to add it after
*
* Insert a new entry after the specified head.
* This is good for implementing stacks.
*/
static void list_add(struct list_head * new, struct list_head *head)
{
	__list_add(new,head,head->next);
}
/**
* list_add_tail - add a new entry
* @new:
new entry to be added
* @head:
list head to add it before
*
* Insert a new entry before the specified head.
* This is useful for implementing queues.
*/
static void list_add_tail(struct list_head* new ,struct list_head *head)
{
	__list_add(new,head->prev,head);
}
/**
* __list_del -
* @prev:
* @next:
*
* Delete a list entry by making the prev/next entries point to each other.
*
* This is only for internal list manipulation where we know the prev/next
* entries already!
*/
static void __list_del(struct list_head* prev,
		struct list_head* next)
{
	next->prev = prev;
	prev->next = next;
}

/**
* list_del - deletes entry from list.
* @entry: the element to delete from the list.
** Note: list_empty on entry does not return true after this, the entry is in
* an undefined state.
*/
static void list_del(struct list_head *entry)
{
		__list_del(entry->prev, entry->next);
}

/**
* list_del_init - deletes entry from list and reinitialize it.
* @entry: the element to delete from the list.
*/

static void list_del_init(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	INIT_LIST_HEAD(entry);
}

/**
* list_empty - tests whether a list is empty
* @head:
the list to test.
*/

static int list_empty(struct list_head *head)
{
	return head->next == head;
}

/**
* list_entry - get the struct for this entry
* @ptr:
the &struct list_head pointer.
* @type:
the type of the struct this is embedded in.
* @member: the name of the list_struct within the struct.
*/

#define list_entry(ptr,type,member)\
	((type*) ((char *)(ptr)-(unsigned long)(&((type*)0)->member)))

/**
* list_for_each - iterate over a list
* @pos:
the &struct list_head to use as a loop counter.
* @head:
the head for your list.
*/
#define list_for_each(pos,head)\
	for(pos=(head)->next; pos!=(head); pos=pos->next)

/**
* list_for_each_safe
-
iterate over a list safe against removal of list entry
* @pos:
the &struct list_head to use as a loop counter.
* @n:
another &struct list_head to use as temporary storage
* @head:
the head for your list.
*/
#define list_for_each_safe(pos,n,head)\
	for(pos = (head)->next, n=pos->next; pos!=(head);\
		pos=n, n=pos->next)

int main(int argc, char* argv[])
{
	struct person *tmp;
	struct list_head *pos, *n;
	int age_i ,weight_j;
	struct person person_head;
	INIT_LIST_HEAD(&person_head.list);

	for(age_i=10, weight_j=35; age_i<40; age_i +=5,weight_j +=5)
	{
		tmp=(struct person*) malloc(sizeof(struct person));
		tmp->age = age_i;
		tmp->weight = weight_j;
		list_add(&(tmp->list), &(person_head.list));
	}

	printf("\n");
	printf("=================print the list======================\n");
	list_for_each(pos, &person_head.list)
	{
		tmp = list_entry(pos, struct person, list);
		printf("age:%d, weight: %d\n", tmp->age, tmp->weight);
		printf("\n");
	}

	printf("==================print list after delete a node which age is 20===================\n");
	list_for_each_safe(pos, n, &person_head.list)
	{
		tmp = list_entry(pos, struct person, list);
		if(tmp->age == 20)
		{
			list_del_init(pos);
			free(tmp);
		}
	}
	list_for_each(pos, &person_head.list)
	{
	tmp = list_entry(pos, struct person, list);
	printf("age:%d, weight: %d \n", tmp->age, tmp->weight);
	}

	list_for_each_safe(pos, n, &person_head.list)
	{
	tmp = list_entry(pos, struct person, list);
	list_del_init(pos);
	free(tmp);
	}
	return 0;
}
