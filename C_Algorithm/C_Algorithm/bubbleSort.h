//
//  bubbleSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/29.
//

#ifndef bubbleSort_h
#define bubbleSort_h

// 버블정렬 구현
#define bubbleSwap(type, x, y) \
        do {              \
          type z = x;      \
          x = y;           \
          y = z;           \
        } while(0)
void bubbleSort(void){
  int size = 0;
  int* arr;
  printf("정수 배열의 길이:");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) {
    printf("요소 %d:", i+1);
    scanf("%d", arr+i);
  }
  
  for (int i = 0; i < size; i++)
    for (int j = i+1; j < size ; j++)
      if(*(arr+i) > *(arr+(j)))
        bubbleSwap(int, *(arr+i), *(arr+(j)));
  
  printf("버블정렬 결과\n");
  for (int i  = 0; i < size; i++)
    printf("%d\t", *(arr+i));
}

#endif /* bubbleSort_h */
