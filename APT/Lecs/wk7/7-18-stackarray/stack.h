/* Based on ADT Stack p430, "A Book on C", Kelly & Pohl */
#ifndef _STACK_H_
#define _STACK_H_

#define MAX_LEN		1000
#define EMPTY		-1
#define FULL		(MAX_LEN - 1)

typedef enum boolean { false, true } boolean;

typedef struct stack {
	char s[MAX_LEN];
	int top;
} stackType;

void reset(stackType *stk);
void push (char c, stackType *stk);
char pop(stackType *stk);
char top(const stackType *stk);
boolean empty(const stackType *stk);
boolean full(const stackType *stk);

#endif
