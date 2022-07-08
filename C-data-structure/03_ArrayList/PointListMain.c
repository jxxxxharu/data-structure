#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void) {

	/* ArrayList�� ���� �� �ʱ�ȭ */
	List list;
	Point* ppos;
	ListInit(&list);

	/* ������ ���� */
	ppos = (Point*)malloc(sizeof(Point));  // Point ����ü ���� �����Ҵ�
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

	/* ����Ʈ ������ ��� */
	printf("���� �������� ��: %d\n", LCount(&list));

	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	/* xpos=2�� ������ ���� */
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

	/* ���� �� ���� ������ ��� */
	printf("���� �������� ��: %d\n", LCount(&list));

	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	return 0;
}