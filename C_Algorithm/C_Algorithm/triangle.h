//
//  triangle.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/17.
//

#ifndef triangle_h
#define triangle_h

void triangleRightBottom(int n) {
  int number = n;
  
  for (int i = n; i > 0 ; i--) {
    for (int j=0; j < n; j++) {
      if(j >= number - 1){
        putchar('*');
      }
      if(j < number - 1){
        putchar(' ');
      }
    }
    putchar('\n');
    number--;
  }
}

void triangleLeftTop(int n){
  int number = n-1;
  for (int i = 0; i < n; i++) {
    for (int j = number; j >= 0; j--) {
      putchar('*');
    }
    putchar('\n');
    number--;
  }
}


void triangleRightTop(int n){
  int spaceIndex = -1;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n ; j++) {
      if(j <= spaceIndex){
        putchar(' ');
      }
      if(j > spaceIndex){
        putchar('*');
      }
    }
    putchar('\n');
    spaceIndex++;
  }
  
}

void starPyramid(int n){
  int spaceIndex = n - 1;
  
  for (int i = 1; i <= n ; i++) {
    int star = (i - 1) * 2 + 1;
    for(int j = 0 ; j < star + spaceIndex; j++){
      if(j < spaceIndex){
        putchar(' ');
      }
      if(j >= spaceIndex){
        printf("*");
      }
    }
    putchar('\n');
    spaceIndex--;
  }
}

void reverseStarPyramid(int n){
  int spaceIndex = 0;
  
  
  for (int i = n; i > 0; i--) {
    int count = (i - 1) * 2 + 1;
    for (int j = 0; j < spaceIndex + count; j++) {   
      if(j < spaceIndex){
        printf(" ");
      }
      if(j >= spaceIndex){
        printf("%d",spaceIndex + 1);
      }
    }
    putchar('\n');
    spaceIndex++;
  }
}
#endif /* Header_h */
