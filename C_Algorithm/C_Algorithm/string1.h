//
//  string1.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2022/01/02.
//

#ifndef string1_h
#define string1_h

void searchChar(const char *str, const char spelling){
  // 문자열은 할당시 연속적인 주소값을 가지고있음               \
  ex) "abcd" 의 주소값은 0x00(a) 0x01(b) 0x02(c) 0x03(d)
  
  // 문자열의 가장 마지막은 항상 NULL을 가지고있는 특성을 이용
  while (*str) {
    if(*str == spelling){
      printf("발견!");
      return;
    }
    str++; // 다음 주소값 (다음 문자열)
  }
  printf("검색 실패");
}


void searchCharExample(void){
  char *str = "ABCDEFG";
  char spelling;
  
  printf("찾을 영어 스펠링 : ");
  scanf("%c", &spelling);
  
  searchChar(str, spelling);
}
#endif /* string1_h */
