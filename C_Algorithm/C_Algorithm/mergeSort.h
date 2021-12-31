//
//  mergeSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/31.
//

#ifndef mergeSort_h
#define mergeSort_h

static int *buff;

// 병합정렬
void merge(int *arr, int left, int right){
  int center = right / 2;
  int p = 0; // 복사 배열 인덱스
  int i = 0; // 원본 배열의 인덱스
  int j = 0; // 복사배열 인덱스 2
  int k = left;
  
  if(left < right){
    merge(arr, left, center);
    merge(arr, center + 1, right);
    
    for (i = left ; i <= center; i++)
      buff[p++] = arr[i];
    while (i <= right && j < p)
      arr[k++] = buff[j] < arr[i] ? buff[j++] : arr[i++];
    while (j < p)
      arr[k++] = buff[j++];
  }
}

void mergeSort(void){
  int size = 0;
  int *arr;
  
  printf("정수 배열 요소 개수 : ");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  buff = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++) {
    printf("요소 %d : ", i + 1);
    scanf("%d", arr+i);
  }
  
  merge(arr, 0, size - 1);
  printf("정렬 결과\n");
  
  for (int i = 0; i < size ; i++) {
    printf("%d\t", *(arr + i));
  }
  
  free(buff);
  free(arr);
}

#endif /* mergeSort_h */
