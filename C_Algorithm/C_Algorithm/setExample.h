//
//  setExample.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/02.
//

#ifndef setExample_h
#define setExample_h

void setExample(void){
  IntSet intSet;
  IntSet intSet2;
  
  printf("set의 요소 개수 : ");
  scanf("%d", &intSet.max);
  InitializeSet(&intSet, intSet.max);
  InitializeSet(&intSet2, intSet.max);
  
  while(1){
    int selectNumber = 0;
    int num = 0;
    printf("--------------------------------------\n");
    printf("1. add\t2. remove\t 3.include\t4.capacity set\n5. max length of set\n6.assign\t7.is equal\t8. print \n0. end process\n");
    printf("--------------------------------------\n");
    printf("메뉴 선택 : ");
    scanf("%d", &selectNumber);
    if(selectNumber == 1){
      printf("add 할 정수 : ");
      scanf("%d", &num);
      setAdd(&intSet, num);
    }
    if(selectNumber == 2){
      printf("remove 할 정수 : ");
      scanf("%d", &num);
      setRemove(&intSet, num);
      printf("remove된 data : %d\n", num);
    }
    if(selectNumber == 3){
      printf("set에 들어있는지 확인 할 정수 : ");
      scanf("%d", &num);
      if(isIncludeInSet(&intSet, num) != -1)
        printf("확인!");
      if(isIncludeInSet(&intSet, num) == -1)
        printf("%d는 없습니다.", num);
    }
    if(selectNumber == 4){
      printf("남은 용량 : %d", setCapacity(&intSet));
    }
    if(selectNumber == 5){
      printf("set에 할당된 사이즈 : %d\n", setSize(&intSet));
    }
    if(selectNumber == 6){
      assign(&intSet, &intSet2);
      for (int i = 0; i < intSet2.num; i++) {
        printf("set1 : %d\n", intSet.set[i]);
        printf("set2 : %d\n", intSet2.set[i]);
      }
    }
    if(selectNumber == 7){
      int result = 0;
      result = setEqual(&intSet, &intSet2);
      printf("set1과 set2는 같은가? : %s\n", result == -1 ? "false" : "true");
    }
    if(selectNumber == 8)
      setPrint(&intSet);
    if(selectNumber == 0){
      disorganizationSet(&intSet);
      disorganizationSet(&intSet2);
      printf("프로세스 종료");
      return;
    }
  }
}


#endif /* setExample_h */
