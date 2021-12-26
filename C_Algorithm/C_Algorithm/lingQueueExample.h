//
//  lingQueueExample.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/26.
//

#ifndef lingQueueExample_h

void useLingQueueExample(void){
  IntLingQueue lingQueue;
  printf("링큐 자료구조 크기 : ");
  scanf("%d", &lingQueue.max);
  
  initializeLingQueue(&lingQueue, lingQueue.max);
  
  while(1){
    int selectNumber = 0;
    int num = 0;
    printf("--------------------------------------\n");
    printf("1. enqueue\t2. dequeue\t 3.peek\t4.clear lingQueue\n5. lingQueue capacity\t6.assigned size\t7.is lingQueue empty\t8. is lingQueue full\n9. number search in the lingQueue\t10. print lingQueue\t0. end process\n");
    printf("--------------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d", &selectNumber);
    if(selectNumber == 1){
      printf("enqueue 할 정수 : ");
      scanf("%d", &num);
      lingEnqueue(&lingQueue, num);
    }
    if(selectNumber == 2){
      lingDequeue(&lingQueue, &num);
      printf("dequeue된 data : %d\n", num);
    }
    if(selectNumber == 3){
      peekLingQueue(&lingQueue, &num);
      printf("lingQueue의 peek값 : %d\n", num);
    }
    if(selectNumber == 4){
      clearLingQueue(&lingQueue);
      printf("clear complete\n");
    }
    if(selectNumber == 5){
      printf("lingQueue의 용량 : %d\n", capacityLingQueue(&lingQueue));
    }
    if(selectNumber == 6){
      printf("lingQueue에 할당된 사이즈 : %d\n", assignedLingQueueSize(&lingQueue));
    }
    if(selectNumber == 7){
      int result = 0;
      result = isEmptyLingQueue(&lingQueue);
      printf("lingQueue이 비어있는가? : %s\n", result == -1 ? "false" : "true");
    }
    if(selectNumber == 8){
      int result = 0;
      result = isFullLingQueue(&lingQueue);
      printf("lingQueue이 꽉차있나? : %s\n", result == -1 ? "false" : "true");
    }if(selectNumber == 9){
      int searchNumber = 0;
      printf("lingQueue에서 검색할 정수 :");
      scanf("%d", &searchNumber);
      printf("%d의 검색 결과 : %s\n",searchNumber, searchLingQueue(&lingQueue, searchNumber) == 0 ? "true" : "false");
    }
    if(selectNumber == 10)
      printLingQueue(&lingQueue);
    if(selectNumber == 0){
      disorganizationLingQueue(&lingQueue);
      printf("프로세스 종료");
      return;
    }
  }
}

#define lingQueueExample_h


#endif /* lingQueueExample_h */
