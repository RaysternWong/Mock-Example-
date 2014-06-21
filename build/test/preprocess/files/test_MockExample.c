#include "unity.h"
#include "mock_Stack.h"
#include "MockExample.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_reverseString_exploration(void)

{

 char *result;





 Stack stackInstance;

 int staticStackbuffer[10];

 stackInstance.buffer = staticStackbuffer;

 stackInstance.length = 512;

 stackInstance.size = 0;

 printf("stackInstance: %p\n", &stackInstance);





 stackNew_CMockExpectAndReturn(26, 512, &stackInstance);

 stackPush_CMockExpect(27, &stackInstance, 'b');

 stackPush_CMockExpect(28, &stackInstance, 'a');

 stackPush_CMockExpect(29, &stackInstance, 'n');

 stackPush_CMockExpect(30, &stackInstance, 'a');

 stackPush_CMockExpect(31, &stackInstance, 'n');

 stackPush_CMockExpect(32, &stackInstance, 'a');



 stackisEmpty_CMockExpectAndReturn(34, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(35, &stackInstance, 'a');

 stackisEmpty_CMockExpectAndReturn(36, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(37, &stackInstance, 'n');

 stackisEmpty_CMockExpectAndReturn(38, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(39, &stackInstance, 'a');

 stackisEmpty_CMockExpectAndReturn(40, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(41, &stackInstance, 'n');

 stackisEmpty_CMockExpectAndReturn(42, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(43, &stackInstance, 'a');

 stackisEmpty_CMockExpectAndReturn(44, &stackInstance, 0);

 stackPop_CMockExpectAndReturn(45, &stackInstance, 'b');

 stackisEmpty_CMockExpectAndReturn(46, &stackInstance, 1);





 result = reverseString("banana");



 UnityAssertEqualString((const char*)("ananab"), (const char*)(result), (((void *)0)), (_U_UINT)51);

}
