#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_

#include "NameCard.h"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef NameCard* LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN]; // 리스트를 저장할 배열
	int numOfData;  // 리스트에 저장된 데이터의 수. 다음 데이터가 저장될 인덱스로도 활용
	int curPosition;  // 데이터 참조위치
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist); // 리스트 초기화
void LInsert(List* plist, LData data);  // 데이터 추가

int LFirst(List* plist, LData* data);  // 첫 번째 데이터 참조
int LNext(List* plist, LData* data);  // 두 번째 이후 데이터 참조

LData LRemove(List* plist);  // 참조한 데이터 삭제
int LCount(List* plist);  // 저장된 데이터의 수 반환

#endif