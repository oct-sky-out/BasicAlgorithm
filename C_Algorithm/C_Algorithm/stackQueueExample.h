//
//  stackQueueExample.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/23.
//

#ifndef stackQueueExample_h

void useStackExample1(void){
  IntStack stack;
  printf("스택 자료구조 크기 : ");
  scanf("%d", &stack.max);
  
  initializeStack(&stack, stack.max);
  
  while(1){
    int selectNumber = 0;
    int num = 0;
    printf("--------------------------------------\n");
    printf("1. push\t2. pop\t 3.peek\t4.clear stack\n5. stack capacity\t6.assigned size\t7.is stack empty\t8. is stack full\n9. number search in the stack\t10. print stack\t0. end process\n");
    printf("--------------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d", &selectNumber);
    if(selectNumber == 1){
      printf("push 할 정수 : ");
      scanf("%d", &num);
      push(&stack, num);
    }
    if(selectNumber == 2){
      pop(&stack, &num);
      printf("pop된 data : %d\n", num);
    }
    if(selectNumber == 3){
      peek(&stack, &num);
      printf("stack의 peek값 : %d\n", num);
    }
    if(selectNumber == 4){
      clearStack(&stack);
      printf("clear complete\n");
    }
    if(selectNumber == 5){
      printf("stack의 용량 : %d\n", capacity(&stack));
    }
    if(selectNumber == 6){
      printf("stack에 할당된 사이즈 : %d\n", assignedSize(&stack));
    }
    if(selectNumber == 7){
      int result = 0;
      result = isEmpty(&stack);
      printf("stack이 비어있는가? : %s\n", result == -1 ? "false" : "true");
    }
    if(selectNumber == 8){
      int result = 0;
      result = isFull(&stack);
      printf("stack이 꽉차있나? : %s\n", result == -1 ? "false" : "true");
    }if(selectNumber == 9){
      int searchNumber = 0;
      printf("stack에서 검색할 정수 :");
      scanf("%d", &searchNumber);
      printf("%d의 검색 결과 : %s\n",searchNumber,search(&stack, searchNumber) == 0 ? "true" : "false");
    }
    if(selectNumber == 10)
      printStack(&stack);
    if(selectNumber == 0){
      disorganizationStack(&stack);
      printf("프로세스 종료");
      return;
    }
  }
}

void useQueueExample(void){
  IntQueue queue;
  printf("큐 자료구조 크기 : ");
  scanf("%d", &queue.max);
  
  initializeQueue(&queue, queue.max);
  
  while(1){
    int selectNumber = 0;
    int num = 0;
    printf("--------------------------------------\n");
    printf("1. enqueue\t2. dequeue\t 3.peek\t4.clear queue\n5. queue capacity\t6.assigned size\t7.is queue empty\t8. is queue full\n9. number search in the queue\t10. print queue\t0. end process\n");
    printf("--------------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d", &selectNumber);
    if(selectNumber == 1){
      printf("enqueue 할 정수 : ");
      scanf("%d", &num);
      enqueue(&queue, num);
    }
    if(selectNumber == 2){
      dequeue(&queue, &num);
      printf("dequeue된 data : %d\n", num);
    }
    if(selectNumber == 3){
      peekQueue(&queue, &num);
      printf("queue의 peek값 : %d\n", num);
    }
    if(selectNumber == 4){
      clearQueue(&queue);
      printf("clear complete\n");
    }
    if(selectNumber == 5){
      printf("queue의 용량 : %d\n", capacityQueue(&queue));
    }
    if(selectNumber == 6){
      printf("queue에 할당된 사이즈 : %d\n", assignedQueueSize(&queue));
    }
    if(selectNumber == 7){
      int result = 0;
      result = isEmptyQueue(&queue);
      printf("queue가 비어있는가? : %s\n", result == -1 ? "false" : "true");
    }
    if(selectNumber == 8){
      int result = 0;
      result = isFullQueue(&queue);
      printf("queue가 꽉차있나? : %s\n", result == -1 ? "false" : "true");
    }if(selectNumber == 9){
      int searchNumber = 0;
      printf("queue에서 검색할 정수 :");
      scanf("%d", &searchNumber);
      printf("%d의 검색 결과 : %s\n",searchNumber, searchQueue(&queue, searchNumber) == 0 ? "true" : "false");
    }
    if(selectNumber == 10)
      printQueue(&queue);
    if(selectNumber == 0){
      disorganizationQueue(&queue);
      printf("프로세스 종료");
      return;
    }
  }
}


#define stackQueueExample_h


#endif /* stackQueueExample_h */
