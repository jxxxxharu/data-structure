#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data) {
	if(plist->numOfData >= LIST_LEN) { 
		printf("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;  // 참조 위치를 첫번째 데이터로 초기화
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;  // 순서대로 데이터를 참조할 수 있게 하기 위함
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];
	
	for(int i=rpos; i<(num-1); i++) {
		plist->arr[i] = plist->arr[i+1];  // 데이터를 앞으로 한칸씩 이동시킴
	}

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}