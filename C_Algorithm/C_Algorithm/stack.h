//
//  stack.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/23.
//

#ifndef stack_h
#define stack_h

// stack 자료구조를 직접 구현하기.
typedef struct {
  int max;
  int pointer;
  int* stack;
} IntStack;

/** stack 초기화 */
int initializeStack(IntStack *stackStructure, int maxStackLength);
/** stack에 data push */
int push(IntStack *stackStructure, int pushData);
/** stack data pop */
int pop(IntStack *stackStructure, int *popData);
/** stack data peek stack의 가장 마지막번째 값 출력*/
int peek(IntStack *stackStructure, int *peekData);
/** stack clear */
void clearStack(IntStack *stackStructure);
/** stack capacity */
int capacity (IntStack *stackStructure);
/** assigned stack size */
int assignedSize(IntStack *stackStructure);
/** stack is empty? */
int isEmpty(IntStack *stackStructure);
/** stack is full? */
int isFull(IntStack *stackStructure);
/** search in the stack */
int search(IntStack *stackStructure, int searchNumber);
/** print stack */
void printStack(IntStack *stackStructure);
/** disorganization stack 스택 할당해체 */
void disorganizationStack(IntStack *stackStructure);

int initializeStack(IntStack *stack, int maxStackLength){
  stack -> pointer = 0;
  stack -> stack = calloc(maxStackLength, sizeof(int));
  if(stack -> stack == NULL){
    stack -> max = 0;
    return -1;
  }
  stack -> max = maxStackLength;
  return 0;
}

int push(IntStack *stackStructure, int pushData){
  if(stackStructure -> max == stackStructure -> pointer)
    return -1;
  *(stackStructure ->stack + stackStructure -> pointer) = pushData;
  stackStructure -> pointer += 1;
  return 0;
}

int pop(IntStack *stackStructure, int *popData){
  if (stackStructure->pointer <= 0)
    return -1;
  *popData = *(stackStructure -> stack + (stackStructure->pointer - 1));
  stackStructure ->pointer -= 1;
  return 0;
}

int peek(IntStack *stackStructure, int *peekData){
  if(stackStructure -> pointer <= 0)
    return -1;
  *peekData = *(stackStructure -> stack + stackStructure ->pointer - 1);
  return 0;
}

void clearStack(IntStack *stackStructure){
  stackStructure -> pointer = 0;
}

int capacity(IntStack *stackStructure){
  return stackStructure->max;
}

int assignedSize(IntStack *stackStructure){
  return stackStructure -> pointer;
}

int isEmpty(IntStack *stackStructure){
  return stackStructure -> pointer <= 0 ? 0 : -1;
}

int isFull(IntStack *stackStructure){
  return stackStructure -> pointer == stackStructure -> max ? 0 : -1;
}

int search(IntStack *stackStructure, int searchNumber){
  for (int i = 0; i < stackStructure -> pointer; i++) {
    if(searchNumber == *(stackStructure -> stack + i)){
      return 0;
    }
  }
  return -1;
}

void printStack(IntStack *stackStructure){
  for (int i = 0; i < stackStructure -> pointer; i++) {
    printf("스택 - %d : %d\n", i, *(stackStructure -> stack + i));
  }
}

void disorganizationStack(IntStack *stackStructure){
  if(stackStructure ->stack != NULL){
    free(stackStructure -> stack);
    stackStructure -> max = 0;
    stackStructure -> pointer = 0;
  }
}
#endif /* stack_h */
