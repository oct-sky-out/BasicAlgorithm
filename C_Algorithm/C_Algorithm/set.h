//
//  set.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/02.
//

#ifndef set_h
#define set_h

typedef struct {
  int max;
  int num;
  int *set;
} IntSet;

// set 초기화
int InitializeSet(IntSet *intSet, int count);
// searchNumber가 set안에 들어있는지 확인
int isIncludeInSet(IntSet *intSet, int searchNumber);
// set에 요소 추가 (존재시 추가하지 않음)
void setAdd(IntSet *intSet, int addNumber);
// set의 요소 제거 (존재하지 않을 시 제거하지않음)
void setRemove(IntSet *intSet, int removeNumber);
// set의 남은 용량
int setCapacity(const IntSet *intSet);
// set의 최대 사이즈
int setSize(const IntSet *intSet);
// A set을 복사하여 B set에 붙여넣음
void assign(const IntSet *copySet, IntSet *pasteSet);
// A set B set이 같은지 확인
int setEqual(IntSet *compareSet1, const IntSet *compareSet2);
// set 내부 출력
void setPrint(const IntSet *intSet);
// set객체 해제
void disorganizationSet(IntSet *intSet);

int sortCondition(const void *n1, const void *n2){
  if(*(int*) n1 > *(int*) n2) return 1;
  if(*(int*) n1 < *(int*) n2) return -1;
  return 0;
}

// 구현
int InitializeSet(IntSet *intSet, int count){
  intSet -> set = calloc(count, sizeof(int));
  intSet -> max = count;
  intSet -> num = 0;
  
  if (intSet -> set == NULL){
    intSet -> max = 0;
    return -1;
  }
  
  return 0;
}

// searchNumber가 set안에 들어있는지 확인
int isIncludeInSet(IntSet *intSet, int searchNumber){
  for (int i = 0 ; i < intSet -> max; i++) {
    if(*(intSet -> set + i) == searchNumber)
      return i;
  }
  return -1;
}

// set에 요소 추가 (존재시 추가하지 않음)
void setAdd(IntSet *intSet, int addNumber){
  if(intSet -> max == intSet -> num)
    return;
  for (int i = 0 ; i < intSet -> num; i++) {
    if(*(intSet -> set + i) == addNumber)
      return;
  }
  *(intSet -> set + intSet -> num) = addNumber;
  intSet -> num++;
}

// set의 요소 제거 (존재하지 않을 시 제거하지않음)
void setRemove(IntSet *intSet, int removeNumber){
  if(intSet -> num == 0)
    return;
  
  int index = isIncludeInSet(intSet, removeNumber);
  if(index != -1){
    *(intSet -> set + index) = *(intSet -> set + intSet -> num - 1);
    *(intSet -> set + intSet -> num) = *(intSet -> set + intSet -> num);
    intSet -> num--;
  }
}

// set의 남은 용량
int setCapacity(const IntSet *intSet){
  return intSet -> max - intSet -> num;
}

// set의 최대 사이즈
int setSize(const IntSet *intSet){
  return intSet -> max;
}

// A set을 복사하여 B set에 붙여넣음
void assign(const IntSet *copySet, IntSet *pasteSet){
  if(copySet -> set == NULL)
    return;
  pasteSet -> set = calloc(pasteSet -> max, sizeof(int));
  pasteSet -> max = copySet -> max;
  pasteSet -> num = copySet -> num;
  for (int i = 0; i < pasteSet -> num; i++)
    *(pasteSet -> set + i) = *(copySet -> set + i);
}

// A set B set이 같은지 확인
int setEqual(IntSet *compareSet1, const IntSet *compareSet2){
  int sameFlag = -1;
  for (int i = 0; i < compareSet2 -> num; i++) {
    if(isIncludeInSet(compareSet1, *(compareSet2 -> set + i)) == -1){
      sameFlag = -1;
      break;
    }
    sameFlag = 0;
  }
  return sameFlag;
}

// set 내부 출력
void setPrint(const IntSet *intSet){
  for (int i = 0; i < intSet -> num; i++) {
    printf("%d\n", *(intSet -> set + i));
  }
}

// set객체 해제
void disorganizationSet(IntSet *intSet){
  free(intSet -> set);
  intSet -> max = intSet -> num = 0;
}
#endif /* set_h */
