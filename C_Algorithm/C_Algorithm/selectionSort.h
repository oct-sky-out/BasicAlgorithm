//
//  selectionSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/29.
//

#ifndef selectionSort_h
#define selectionSort_h

// 선택정렬 구현
void selectionSort(void){
  int size = 0;
  int* arr = 0;
  printf("정수 배열길이 :");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  for (int i = 0 ; i < size; i++) {
    printf("요소 %d:", i+1);
    scanf("%d", arr + i);
  }
  
  int smallestIndex = 0;
  for (int i = 0; i < size; i++) {
    smallestIndex = i; // 제일 작은 값을 현재값으로 설정
    for (int j = i+1; j < size; j++)
      if(*(arr + smallestIndex) > *(arr + j))
        smallestIndex = j; // 현재값보다 작은 값이 존재하면 대입후
    swap(int, *(arr+i), *(arr + smallestIndex)); // 교환
  }
  printf("정렬 결과\n");
  for (int i = 0; i < size; i++)
    printf("%d\t", *(arr + i));
}

#endif /* selectionSort_h */
