/* Based on ADT Stack p460, "A Book on C", Kelly & Pohl */

#ifndef _STACK_H_
#define _STACK_H_

#define EMPTY		0
#define FULL 		1000

typedef enum boolean { false, true } boolean;

struct stack_element {
	char data;
	struct stack_element *next;
};

typedef struct stack_element stackElementType;

typedef struct stack {
	int count; 	/* count of elements */
	stackElementType *top;
} stackType;

void reset(stackType *stk);
void push (char c, stackType *stk);
char pop(stackType *stk);
char top(const stackType *stk);
boolean empty(const stackType *stk);
boolean full(const stackType *stk);

#endif
