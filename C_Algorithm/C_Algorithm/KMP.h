//
//  KMP.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/03.
//

#ifndef KMP_h
#define KMP_h

int* makeMatch(const char *pattern){
  int i = 1;
  int j = 0;
  int* matchArr = calloc(sizeof(pattern), sizeof(int));
  
  while (pattern[i] != '\0') {
    if(pattern[i] == pattern[j])
      matchArr[++i] = ++j;
    else if(j == 0)
      matchArr[++i] = 0;
    else
      j = matchArr[j];
  }
  return matchArr;
}

void KMP(void){
  char text[100];
  char pattern[100];
  int* matchResult;
  int i = 0;
  int j = 0;
  
  printf("텍스트 입력 : ");
  scanf("%s", text);
  printf("패턴 입력 : ");
  scanf("%s", pattern);
  
  matchResult = makeMatch(pattern);
  
  while (text[i] != '\0') {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else if (j == 0)
      i++;
    else j = matchResult[j];
    
    if(pattern[j] == '\0'){
      printf("%d 인덱스에서부터 패턴이 발견됨.", i-j);
      j = 0;
    }
      
  }
  
}

#endif /* KMP_h */
