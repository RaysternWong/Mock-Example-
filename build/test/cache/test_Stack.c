#include "unity.h"
#include "Stack.h"
#include "ErrorCode.h"
#include "CException.h"




Stack stack;

int buffer[sizeof(int) * (4 + 16)];





void setUp(void)

{

 stack.buffer = buffer;

 stack.length = 4;

 stack.size = 0;

}



void tearDown(void)

{

}



void test_stackNew_should_setup_the_new_stack(void)

{

 if ((((&stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)24);;};

 if ((((stack.buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack.size)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack.length)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_stackPush_given_3number_push_to_stack_should_alocate(void)

{

 stackNew(4);

 stackPush(&stack , 1);

 stackPush(&stack , 2);

 stackPush(&stack , 3);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((buffer[0])), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((buffer[1])), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((buffer[2])), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((stack.size)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack.length)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

}



void test_stackPush_given_5numbeer_push_to_stack_should_throw_exception(void)

{

 unsigned int err;

 stackNew(4);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 { stackPush(&stack , 1);

  stackPush(&stack , 2);

  stackPush(&stack , 3);

  stackPush(&stack , 4);

  stackPush(&stack , 5);

      UnityFail( ("Should throw error exception"), (_U_UINT)56);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)) {

     UnityAssertEqualNumber((_U_SINT)((ERR_STACK_FULL)), (_U_SINT)((err)), ("Expected ERR_STACK_FULL exception"), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

    }

}



void test_stackPop_given_6_should_pop_6(void)

{

 stackNew(4);

 stackPush(&stack , 6);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((stackPop(&stack))), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack.size)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

}





void test_stackPop_given_3number_but_pop_4times_should_throw_exception(void)

{

 unsigned int err;



 stackNew(4);



 stackPush(&stack , 1);

 stackPush(&stack , 2);

 stackPush(&stack , 3);





 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPop(&stack);

  stackPop(&stack);

  stackPop(&stack);

  stackPop(&stack);



  UnityFail( ("Should throw  exception"), (_U_UINT)91);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

    UnityAssertEqualNumber((_U_SINT)((ERR_STACK_EMPTY)), (_U_SINT)((err)), ("Expect ERR_STACK_EMPTY exception"), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

     }

}
