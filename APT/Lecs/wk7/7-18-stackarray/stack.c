/* Based on ADT Stack p430, "A Book on C", Kelly & Pohl */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void reset(stackType *stk)
{
	stk->top = EMPTY;
}

void push (char c, stackType *stk)
{
	stk->top++;
	stk->s[stk->top] = c;
}

char pop(stackType *stk)
{
	return (stk->s[stk->top--]);
}

char top(const stackType *stk)
{
	return (stk->s[stk->top]);
}

boolean empty(const stackType *stk)
{
	return ((boolean) (stk->top == EMPTY));
}

boolean full(const stackType *stk)
{
	return ((boolean) (stk->top == FULL));
}
