#ifndef Stack_H
#define Stack_H

typedef struct{
	int *buffer;
	int size;
	int length;
}Stack;



Stack *stackNew(int length);
void StackDel(Stack *stackPtr);

void stackPush(Stack *stackPtr, int push);
int stackPop(Stack *stackPtr);


int stackisEmpty(Stack *stackPtr);
int stackisFull(Stack *stackPtr);

#endif // Stack_H
