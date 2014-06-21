#include <stdio.h>
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include "Stack.h"

Stack *stackNew(int lengthOfStack){
	Stack *stack = malloc(sizeof(Stack));
	stack->buffer = malloc(sizeof(int) * lengthOfStack);
	stack->size = 0;
	stack->length = lengthOfStack;
	
	return stack;
}

void StackDel(Stack *stackPtr){

	if(stackPtr != NULL)
	{
		free(stackPtr->buffer);
		free(stackPtr);
	}
}


int stackisFull(Stack *stackPtr)
{
	if(stackPtr->size >= stackPtr->length)
		return 1;
		
	else
		return 0;
}

void stackPush(Stack *stackPtr, int push){

	stackPtr->buffer[stackPtr->size] = push;
	stackPtr->size++;
	
	if(stackisFull(stackPtr))
	Throw(ERR_STACK_FULL);
}




int stackisEmpty(Stack *stackPtr){

	if(stackPtr->size == 0)
	  return 1;
	
	else	
		return 0;
}

int stackPop(Stack *stackPtr)
{
	int Pop;
	
	if(stackisEmpty(stackPtr))
	Throw(ERR_STACK_EMPTY);	
	
	Pop = stackPtr->buffer[stackPtr->size-1];
	stackPtr->size--;
	
	return Pop;
}