//
//  factorial.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/27.
//

#ifndef factorial_h
#define factorial_h

int factorial(int number);

void factorialExample(void){
  int number, result = 0;
  scanf("%d", &number);
  
  result = factorial(number);
  printf("%d", result);
}

int factorial(int number){
  if(number != 1)
    return number * factorial(number - 1);
  return number;
}

#endif /* factorial_h */
