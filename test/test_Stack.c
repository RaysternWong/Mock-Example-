#include "unity.h"
#include "ErrorCode.h"
#include "CException.h"
#include "Stack.h"

#define STACK_LENGTH 4
Stack stack;
int buffer[sizeof(int) * (STACK_LENGTH + 16)];


void setUp(void)
{
	stack.buffer = buffer;
	stack.length = STACK_LENGTH;
	stack.size = 0;
}

void tearDown(void)
{
}

void test_stackNew_should_setup_the_new_stack(void)
{	
	TEST_ASSERT_NOT_NULL(&stack);
	TEST_ASSERT_NOT_NULL(stack.buffer);
	TEST_ASSERT_EQUAL(0 , stack.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH , stack.length);
}

void test_stackPush_given_3number_push_to_stack_should_alocate(void)
{
	stackNew(STACK_LENGTH);
	stackPush(&stack , 1);
	stackPush(&stack , 2);
	stackPush(&stack , 3);
	
	
	TEST_ASSERT_EQUAL(1, buffer[0]);
	TEST_ASSERT_EQUAL(2, buffer[1]);
	TEST_ASSERT_EQUAL(3, buffer[2]);
	TEST_ASSERT_EQUAL(3, stack.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH, stack.length);
}

void test_stackPush_given_5numbeer_push_to_stack_should_throw_exception(void)
{
	CEXCEPTION_T err;
	stackNew(STACK_LENGTH);

	Try
	{	stackPush(&stack , 1);
		stackPush(&stack , 2);
		stackPush(&stack , 3);
		stackPush(&stack , 4);
		stackPush(&stack , 5);
     	TEST_FAIL_MESSAGE("Should throw error exception");
	}
	Catch(err)	{
					TEST_ASSERT_EQUAL_MESSAGE( ERR_STACK_FULL , err , "Expected ERR_STACK_FULL exception");
				}
}

void test_stackPop_given_6_should_pop_6(void)
{	
	stackNew(STACK_LENGTH);
	stackPush(&stack , 6);
	
	TEST_ASSERT_EQUAL(6 , stackPop(&stack));
	TEST_ASSERT_EQUAL(0 , stack.size);
}


void test_stackPop_given_3number_but_pop_4times_should_throw_exception(void)
{	
	CEXCEPTION_T err;
	
	stackNew(STACK_LENGTH);
	
	stackPush(&stack , 1);
	stackPush(&stack , 2);
	stackPush(&stack , 3);
		
	
	Try
	{
		stackPop(&stack);
		stackPop(&stack);
		stackPop(&stack);
		stackPop(&stack);
		
		TEST_FAIL_MESSAGE("Should throw  exception");
	}
	Catch(err){
				TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_EMPTY , err , "Expect ERR_STACK_EMPTY exception");
			  }
}