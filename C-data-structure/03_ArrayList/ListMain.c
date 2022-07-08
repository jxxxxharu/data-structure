#include <stdio.h>
#include "ArrayList.h"

int main(void) {

	/* ArrayList�� ���� �� �ʱ�ȭ */
	List list;
	int data;
	ListInit(&list);

	/* ������ ���� */
	LInsert(&list, 10);
	LInsert(&list, 20);
	LInsert(&list, 30);
	LInsert(&list, 40);
	LInsert(&list, 50);

	/* ����Ʈ ������ ��� */
	printf("���� �������� ��: %d\n", LCount(&list));

	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	/* ������ 20 ���� */
	if(LFirst(&list, &data)) {
		if(data == 20)
			LRemove(&list);

		while(LNext(&list, &data)) {
			if(data == 20)
				LRemove(&list);
		}
	}

	/* ���� �� ���� ������ ��� */
	printf("���� �������� ��: %d\n", LCount(&list));

	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}