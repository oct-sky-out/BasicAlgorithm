//
//  hanoi.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/28.
//

#ifndef hanoi_h
#define hanoi_h

void hanoi(int number, int x, int y);

void hanoiExample(void){
  int number = 0;
  scanf("%d", &number);
  hanoi(number, 1, 3);
}

void hanoi(int number, int x, int y){
  if(number > 1)
    hanoi(number - 1, x, 6 - (x+y));
  
  printf("원반 %d는 %d -> %d 로 이동\n", number, x, y);
  
  if(number > 1)
    hanoi(number - 1, 6 - (x+y), y);
}

#endif /* hanoi_h */
