//
//  heapSort.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/01.
//

#ifndef heapSort_h
#define heapSort_h

void makeHeap(int *arr, int left, int right);

void heapSort(void){
  int size = 0;
  int* arr = 0;
  printf("정수 배열길이 :");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  for (int i = 0 ; i < size; i++) {
    printf("요소 %d:", i+1);
    scanf("%d", arr + i);
  }
  
  // 최초 heap구조로 정렬
  for (int i = (size / 2) - 1; i >= 0 ; i--)
    makeHeap(arr, i, size);
  
  // 각 최상단 노드를 최하단 노드ㄹ 최상단으로 옮긴 후 heap정렬
  for (int i = size - 1; i > 0; i--) {
    swap(int, arr[i], arr[0]); // 최상단 노드와 최하단 노드의 교환
    makeHeap(arr, 0, i - 1); // 최하단 노드 제거 후 heap정렬
  }
  
  printf("정렬 결과\n");
  for (int i = 0; i < size; i++)
    printf("%d\t", *(arr + i));
  
  free(arr);
}

//  36 line - parent < (right + 1) / 2 조건은 정리해야 할 배열의 길이가 2개일때에는 Heap정리 할 필요가 없으므로 안함. \
    40 line - childRight <= right && arr[childLeft] < arr[childRight] 조건은                         \
              우측 노드가 존재하고, 오른쪽 노드가 왼쪽 노드보다 크면 오른쪽을,                                     \
              오른쪽 노드가 아에 존재하지 않거나, 존재해도 왼쪽보다 작다면 왼쪽 노드를 child로 선정한다.
void makeHeap(int *arr, int left, int right){
  int temp = arr[left];
  int child;
  int parent;
  
  for (parent = left; parent < (right + 1) / 2 ; parent = child) {
    int childLeft = parent * 2 + 1;
    int childRight = childLeft + 1;
    
    child = (childRight <= right && arr[childLeft] < arr[childRight]) ? childRight : childLeft;
    
    if(temp >= arr[child]) break;
    if(temp < arr[child]) arr[parent] = arr[child];
  }
  arr[parent] = temp;
}

#endif /* heapSort_h */
