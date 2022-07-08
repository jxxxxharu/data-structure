#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_

#include "Point.h"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
//typedef int LData;
typedef Point* LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN]; // ����Ʈ�� ������ �迭
	int numOfData;  // ����Ʈ�� ����� �������� ��. ���� �����Ͱ� ����� �ε����ε� Ȱ��
	int curPosition;  // ������ ������ġ
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ
void LInsert(List* plist, LData data);  // ������ �߰�

int LFirst(List* plist, LData* data);  // ù ��° ������ ����
int LNext(List* plist, LData* data);  // �� ��° ���� ������ ����

LData LRemove(List* plist);  // ������ ������ ����
int LCount(List* plist);  // ����� �������� �� ��ȯ

#endif