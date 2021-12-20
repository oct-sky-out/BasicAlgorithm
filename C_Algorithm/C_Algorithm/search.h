//
//  search.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/20.
//

#ifndef search_h
#define search_h

// 선형검색
void linearSearchForVersion(void){
  int size = 0;
  int* arr;
  int searchNumber = 0;
  
  printf("선형검색\n");
  printf("정수 배열 요소 개수 : ");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++){
    printf("요소 %d : ", i+1);
    scanf("%d", arr + i);
  }
      
  printf("검색 요소 : ");
  scanf("%d", &searchNumber);
  
  for (int i = 0; i < size; i++) {
    if(*(arr+i) == searchNumber){
      printf("성공 : %d", *(arr + i));
      free(arr);
      return;
    }
  }
  printf("실패");
  free(arr);
}

// 보초법을 이용한 선형검색
void linearSearchWhileVersion(void){
  int size = 0;
  int* arr;
  int searchNumber = 0;
  int arrayKey = 0;
  
  printf("보초법 선형검색\n");
  printf("정수 배열 요소 개수 : ");
  scanf("%d", &size);
  
  arr = calloc(size + 1, sizeof(int));
  
  for (int i = 0; i < size; i++){
    printf("요소 %d : ", i+1);
    scanf("%d", arr + i);
  }
  
  printf("검색 요소 : ");
  scanf("%d", &searchNumber);
  *(arr + size) = searchNumber;
  
  while (1) {
    if(*(arr + arrayKey) == searchNumber)
      break;
    arrayKey++;
  }
  
  arrayKey == size ?
  printf("실패") :
  printf("성공 : %d", *(arr + arrayKey));
}

// 이진검색
void binarySearch(void){
  int leftPointer = 0;
  int rightPointer = 0;
  int centerPointer = 0;
  int searchNumber = 0;
  int size = 0;
  int* arr;
  
  printf("정수 배열 요소의 개수 : ");
  scanf("%d", &size);
  arr = calloc(size, sizeof(int));
  rightPointer = size - 1;
  
  for (int i = 0; i < size; i++) {
    printf("요소 %d : ", i);
    scanf("%d", arr + i);
  }
  
  printf("배열 내의 정수 검색 요소 : ");
  scanf("%d", &searchNumber);
  
  while (1) {
    centerPointer = (rightPointer + leftPointer) / 2;
    if(*(arr + centerPointer) == searchNumber){
      printf("찾기 성공 : %d", *(arr + centerPointer));
      break;
    }
    if(leftPointer == centerPointer || rightPointer == centerPointer){
      printf("찾기 실패");
      break;
    }
    if(*(arr + centerPointer) < searchNumber)
      leftPointer = centerPointer + 1;
    if(*(arr + centerPointer) > searchNumber)
      rightPointer = centerPointer - 1;
  }
  free(arr);
}

// 이진검색 응용 (동일한 숫자가 존재하면 맨 앞의 인덱스에있는 숫자를 리턴)

int frontIndex(int *arr, int index, int searchNumber);

void binarySearch2(void){
  int leftPointer = 0;
  int rightPointer = 0;
  int centerPointer = 0;
  int searchNumber = 0;
  int frontestIndex = 0;
  int size = 0;
  int* arr;
  
  printf("정수 배열 요소의 개수 : ");
  scanf("%d", &size);
  arr = calloc(size, sizeof(int));
  rightPointer = size - 1;
  
  for (int i = 0; i < size; i++) {
    printf("요소 %d : ", i);
    scanf("%d", arr + i);
  }
  
  printf("배열 내의 정수 검색 요소 : ");
  scanf("%d", &searchNumber);
  
  while (1) {
    centerPointer = (leftPointer + rightPointer) / 2;
    if(*(arr + centerPointer) == searchNumber){
      frontestIndex = frontIndex(arr, centerPointer, searchNumber);
      printf("찾기 성공 : %d, 인덱스 : %d", *(arr +frontestIndex), frontestIndex);
      break;
    }
     
    if(leftPointer == centerPointer || rightPointer == centerPointer){
      printf("찾기 실패");
      break;
    }
    if(*(arr + centerPointer) < searchNumber)
      leftPointer = centerPointer + 1;
    if(*(arr + centerPointer) > searchNumber)
      rightPointer = centerPointer - 1;
  }
  free(arr);
}

int frontIndex(int *arr, int index, int searchNumber){
  if(*(arr + index) == searchNumber)
    return frontIndex(arr, index - 1, searchNumber);
  return index + 1;
}
#endif /* search_h */
 
