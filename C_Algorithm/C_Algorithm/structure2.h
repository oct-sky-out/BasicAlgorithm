//
//  structure2.h
//  C_Algorithm
//
//  Created by Oct_Sky_Out on 2021/12/18.
//

#ifndef structure2_h
#define structure2_h

int isLeaf(int year);

void dayOfYear(void){
  int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31}
  };
  int y, m, d;
  
  printf("연 : ");
  scanf("%d", &y);
  printf("월 : ");
  scanf("%d", &m);
  printf("일 : ");
  scanf("%d", &d);
  
  int days = 0;
  for (int i = 0; i < m - 1; i++) {
    days += mdays[isLeaf(y)][i];
  }
  printf("%d년으로부터 %d일경과", y, d + days);
}

int isLeaf(int year){
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// 구조체를 이용한 여러가지 날짜 제어
typedef struct {
  int year;
  int month;
  int day;
} Date;

Date afterDate(Date date , int afterDay){
  int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31}
  };
  
  int remainDay = afterDay + date.day;
  
  while (remainDay > 0) {
    if(remainDay >= 365){
      date.year += 1;
      remainDay -= 366;
    }
    
    if(remainDay - mdays[isLeaf(date.year)][date.month - 1] > 0){
      date.month+=1;
      if(date.month == 13){
        date.year += 1;
        date.month = 1;
      }
      remainDay -= mdays[isLeaf(date.year)][date.month - 1];
      
    }
    if(remainDay - mdays[isLeaf(date.year)][date.month - 1] < 0){
      date.day = remainDay + 1;
      remainDay -= mdays[isLeaf(date.year)][date.month - 1];
    }
    
    if(remainDay - mdays[isLeaf(date.year)][date.month - 1] == 0){
      date.day = 1;
      date.month += 1;
      remainDay = 0;
    }
  }
  return date;
}

void dateAfter(void){
  Date date = {2021, 3, 18};
  date = afterDate(date, 100);
  
  printf("%d년, %d월 %d일\n", date.year, date.month, date.day);
}




#endif /* structure2_h */
