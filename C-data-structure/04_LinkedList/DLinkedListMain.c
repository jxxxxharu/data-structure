#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2);

int main(void) {

	/* 연결리스트 생성 및 초기화 */
	List list;
	int data;
	ListInit(&list);

	/* 리스트 정렬 기준 등록 */
	SetSortRule(&list, WhoIsPrecede);

	/* 데이터 저장 */
	LInsert(&list, 20);
	LInsert(&list, 30);
	LInsert(&list, 50);
	LInsert(&list, 10);
	LInsert(&list, 40);

	/* 리스트 데이터 출력 */
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	/* 데이터 20 삭제 */
	if(LFirst(&list, &data)) {
		if(data == 20)
			LRemove(&list);

		while(LNext(&list, &data)) {
			if(data == 20)
				LRemove(&list);
		}
	}

	/* 삭제 후 남은 데이터 출력 */
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2) return 0;  // d1이 정렬 순서가 앞설 때 0 반환
	else return 1;  // d2가 정렬 순서가 앞설 때 1 반환
}