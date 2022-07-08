#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void) {

	/* ArrayList의 생성 및 초기화 */
	List list;
	Point* ppos;
	ListInit(&list);

	/* 데이터 저장 */
	ppos = (Point*)malloc(sizeof(Point));  // Point 구조체 변수 동적할당
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/* 리스트 데이터 출력 */
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	/* xpos=2인 데이터 삭제 */
	Point compPos = {2, 0};

	if(LFirst(&list, &ppos)) {
		if(PointComp(ppos, &compPos) == 1) 
			LRemove(&list);

		while(LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	/* 삭제 후 남은 데이터 출력 */
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	return 0;
}