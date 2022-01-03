//
//  bruteForce.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/02.
//

#ifndef bruteForce_h
#define bruteForce_h

void bruteForce(void){
  char mainString[] = "ABCADEFG";
  char string[100];
  int mainStringIndex = 0;
  int stringIndex = 0;
  
  printf("문자열을 입력하세요 : ");
  scanf("%s", string);
  
  while ((string[stringIndex] != '\0') && (mainString[mainStringIndex] != '\0')) {
    if(mainString[mainStringIndex] == string[stringIndex]){
      mainStringIndex++;
      stringIndex++;
    } else {
      mainStringIndex =( mainStringIndex - stringIndex ) + 1;
      stringIndex = 0;
    }
    if(string[stringIndex] == '\0')
      printf("%s는 %s의 문자열의 %d번째 인덱스부터 일치합니다.", string, mainString, mainStringIndex - stringIndex);
    if(mainString[mainStringIndex] == '\0')
      printf("일치하지않음.");
  }
}

#endif /* buteForce_h */
