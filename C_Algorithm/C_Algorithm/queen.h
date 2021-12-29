//
//  queen.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/29.
//

#ifndef queen_h
#define queen_h

int rowPosition[8]; // 행
int leftDiagonal[15]; // 왼쪽 방향사선
int rightDiagonal[15]; // 오른쪽 방향사선
int position[8]; // 열, 퀸이 놓인 위치

void printQueenPosition(void);
void setProcessionQueen(int i);

void queenExample(void){
  setProcessionQueen(0);
}

void printQueenPosition(void){
  for (int i = 0; i < 8; i++)
    printf("%2d", position[i]);
  printf("\n");
}

void setProcessionQueen(int i){
  for (int j = 0; j < 8 ; j++) {
    position[i] = j;
    if(!rowPosition[j] && !leftDiagonal[i + j] && !rightDiagonal[(i-j) + 7]  ){
      if(i == 7)
        printQueenPosition();
      else{
        rowPosition[j] = leftDiagonal[i + j] = rightDiagonal[(i-j) + 7] = 1;
        setProcessionQueen(i+1);
        rowPosition[j] = leftDiagonal[i + j] = rightDiagonal[(i-j) + 7] = 0;
      }
    }
  }
}

#endif /* queen_h */
