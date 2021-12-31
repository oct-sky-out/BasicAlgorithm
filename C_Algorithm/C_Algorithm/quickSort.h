//
//  quickSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/31.
//

#ifndef quickSort_h
#define quickSort_h

// 퀵정렬
void quick(int *arr, int left, int right){
  int pl = left;
  int pr = right - 1;
  int pivot = arr[right];

  while (1) {
    while (arr[pl] < pivot) { if(pl == right) break; pl++; }
    while (arr[pr] >= pivot) { if(pr == pl) break; pr--; }
    
    if(pl == pr){
      swap(int, arr[pl], arr[right]);
      break;
    }
    
    if(pl == right)
      break;
    
    if(pl != pr){
      swap(int, arr[pl], arr[pr]);
      continue;
    }
  }
  if(arr[left] < pivot)quick(arr, left, arr[pr] == pivot ? pr - 1 : pr);
  if(pivot < arr[right])quick(arr, pl + 1, right);
}

void quickSort(void){
  int size = 0;
  int *arr;
  
  printf("정수 배열 요소 개수 : ");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++) {
    printf("요소 %d : ", i + 1);
    scanf("%d", arr+i);
  }
  
  quick(arr , 0, size - 1);
  printf("정렬 결과\n");
  
  for (int i = 0; i < size ; i++) {
    printf("%d\t", *(arr + i));
  }
  
  free(arr);
}
#endif /* quickSort_h */
