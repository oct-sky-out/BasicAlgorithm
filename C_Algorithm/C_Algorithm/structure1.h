//
//  structure1.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/18.
//

#ifndef structure1_h
#define structure1_h

// 배열
// C언어 배열은 초기화 시 상수로 선언해야한다.
void array1(void){
  int arr[5];
  
  // 배열의 메모리 할당 용량은 sizeof로 배열의 길이를 나타 낼 수 있다.
  // int 배열이 5개이므로 int 메모리 4byte, 5개 |  4 * 5 = 20;
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < sizeof(arr) / sizeof(int) ; i++) {
    printf("%d", arr[i]);
  }
}

// 동적 메모리 생성
// calloc, malloc
void callocExample(void){
  int *x;
  
  x = calloc(1, sizeof(int));
  if(x == NULL){
    printf("메모리 할당 실패!");
  }
  if(x != NULL){
    *x = 10;
    printf("*x = %d", *x);
    free(x);
  }
}

// 배열을 동적인 크기로 지정하여 생성.
void callocArray(void){
  int size = 0;
  int *arr;
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++) {
    scanf("%d", arr + i);
  }
  for (int i = 0; i < size; i++) {
    printf("%d", *(arr + i));
  }
  
  free(arr);
}


// 배열 역순 정렬
#define swap(type, x, y) \
          do{            \
            type z;      \
            z = x;       \
            x = y;       \
            y = z;       \
          } while(0);
void arraySwap(void){
  int size = 0;
  int *arr;
  printf("정수형 배열 역순정렬\n");
  printf("정수형 배열 생성 개수 : ");
  scanf("%d", &size);
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++){
    scanf("%d", arr + i);
  }
  for (int i = 0; i < size / 2; i++){
    swap(int, arr[i], arr[size - i - 1]);
  }
  
  for (int i = 0; i < size; i++)
    printf("%d", *(arr + i));

  free(arr);
}

// 배열 역순 정렬, 정렬 과정보기
void watchArraySwap(void){
  int size = 0;
  int *arr;
  
  scanf("%d", &size);
  arr = calloc(size, sizeof(int));
  
  for (int i =0; i < size; i++)
    scanf("%d", arr + i);
  for (int i = 0; i < size/2; i++) {
    for (int j =0; j < size; j++) {
      printf("%d \t", *(arr + j));
    }
    swap(int, arr[i], arr[size - i -1]);
    printf("\n");
  }
  
  for (int i = 0; i < size; i++) {
    printf("%d \t", *(arr + i));
  }
  free(arr);
}

 // 2 - 36진수 변환 알고리즘
void changeDigit(void){
  char result[1024];
  char digitChar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int baseN = 0;
  int number = 0;
  int digit = 0;
  
  printf("변환 할 진수를 입력하세요 :");
  scanf("%d", &baseN);
  
  printf("숫자를 입력하세요 :");
  scanf("%d", &number);
  
  if(number == 0){
    printf("%d", number);
  }
  if(number != 0){
    while (number) {
      result[digit++] = digitChar[number % baseN];
      number /= baseN;
    }
  }
  for (int i = digit - 1; i >= 0 ; i-- ){
    printf("%c", result[i]);
  }
}


void getPrimeUnderTheN(void){
  unsigned long counter = 0;
  int prime[1000];
  int index = 0;
  int range = 0;
  prime[index++] = 2;
  prime[index++] = 3;
  
  printf("범위 : ");
  scanf("%d", &range);
  
  if(range == 2) {
    printf("2");
    return;
  }
  if(range == 3){
    for (int i = 0; i < index; i++) {
      printf("%d\n", prime[i]);
    }
    return;
  }
  for (int number = 5; number <= range; number += 2) {
    int flag = 0;
    for (int i = 1; (void)(counter++), prime[i] * prime[i] <= number; i++) {
      counter++;
      if(number % prime[i] == 0) {
        flag = 1;
        break;
      }
    }
    if(!flag) prime[index++] = number;
  }
  for (int i = 0; i < index; i++) {
    printf("%d\n", prime[i]);
  }
  printf("count : %lu\n", counter);
}

#endif /* structure1_h */
