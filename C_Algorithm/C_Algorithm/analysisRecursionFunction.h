//
//  analysisRecursionFunction.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/28.
//

#ifndef analysisRecursionFunction_h
#define analysisRecursionFunction_h

void recursionFunction(int n){
  if(n > 0){
    recursionFunction(n - 1);
    printf("%d\n", n);
    recursionFunction(n - 2);
  }
}

void recursionFunctionExample(void){
  // 재귀함수를 분석하는 법
  // 1. 상향식 분석 -> 재귀함수에 처음 들어가는 조건의 수를 넣은 후 분석
  // 2. 하향식 분석 -> 재귀함수를 처음 완료하는 케이스의 수를 넣은 후 증가시켜 분석
  recursionFunction(6);
  // 4의 결과 (상향, 하향)-> 1 - 2 - 3 - 4 - 1 - 2
  // 5의 결과 (상향)-> 1 - 2 - 3 - 1 - 4 - 1 - 2 - 5 - 1 - 2 - 3 - 1
  // 6의 결과 (하향) ->
  //  1 - 2 - 3 - 1 - 4 - 1 - 2 - 5 - 1 - 2 - 3 - 1 - 6 - 1 - 2 - 3 - 1 - 4 - 1 - 2
}


#endif /* analysisRecursionFunction_h */
