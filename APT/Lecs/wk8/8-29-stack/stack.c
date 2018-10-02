/* Based on ADT Stack p460, "A Book on C", Kelly & Pohl */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void reset(stackType *stk)
{
	stk->count = 0;
	stk->top = NULL;
}

void push (char c, stackType *stk)
{
	stackElementType *p;

	if ((p = malloc(sizeof(stackElementType))) == NULL)
	{
		fprintf(stderr,"push failed to malloc\n");
		exit(EXIT_FAILURE);
	}
	p->data = c;
	p->next = stk->top;
	stk->top = p;
	stk->count++;
}

char pop(stackType *stk)
{
	char c;
	stackElementType *p;

	c = stk->top->data;
	p = stk->top;
	stk->top = stk->top->next;
	stk->count--;
	free(p);
	return c;
}

char top(const stackType *stk)
{
	return (stk->top->data);
}

boolean empty(const stackType *stk)
{
	return ((boolean) (stk->count == EMPTY));
}

boolean full(const stackType *stk)
{
	return ((boolean) (stk->count == FULL));
}
