#include <stdio.h>
#include "ArrayList.h"

int main(void) {

	/* ArrayList의 생성 및 초기화 */
	List list;
	int data;
	ListInit(&list);

	/* 데이터 저장 */
	LInsert(&list, 10);
	LInsert(&list, 20);
	LInsert(&list, 30);
	LInsert(&list, 40);
	LInsert(&list, 50);

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