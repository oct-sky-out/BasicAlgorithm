//
//  euclid.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/27.
//

#ifndef euclid_h
#define euclid_h

int euclid(int x, int y){
  if(y == 0)
    return x;
  return euclid(y, x % y);
}

void euclidExample(void){
  int x, y, result = 0;
  
  printf("x : ");
  scanf("%d", &x);
  printf("y : ");
  scanf("%d", &y);
  
  result = euclid(x, y);
  printf("gcd : %d\n", result);
}

void multipleEuclid(void){
  int size, result = 0;
  int* arr;
  
  printf("size : ");
  scanf("%d", &size);
  
  arr = calloc(size, sizeof(int));
  
  for (int i = 0; i < size; i++) {
    printf("arr %d : ", i);
    scanf("%d", arr + i);
  }
  
  for (int i = 1; i < size; i++) {
    if(i == 1)
      result = euclid(arr[0], arr[1]);
    else
      result = result <= arr[i]
      ? euclid(result, arr[i] % result)
      : euclid(arr[i], result % arr[i]);
  }
  
  printf("%d\n", result);
  free(arr);
}

#endif /* euclid_h */
