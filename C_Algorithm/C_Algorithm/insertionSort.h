//
//  insersionSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/30.
//

#ifndef insertionSort_h
#define insertionSort_h

// 선택 정렬
void insertionSort(void){
  int size = 0;
  int *arr;
  
  printf("정수 배열 요소 개수 : ");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++) {
    printf("요소 %d : ", i + 1);
    scanf("%d", arr+i);
  }
  
  for (int i = 1; i < size; i++) {
    int currentValue = arr[i];
    for (int j = i; j > 0; j--) {
      if(arr[j - 1] < currentValue)
        break;
      if(arr[j] < arr[j - 1]){
        arr[j] = arr[j - 1];
        arr[j - 1] = currentValue;
      }
    }
  }
  printf("정렬 결과\n");
  
  for (int i = 0; i < size ; i++) {
    printf("%d\t", *(arr + i));
  }
}


#endif /* insersionSort_h */
