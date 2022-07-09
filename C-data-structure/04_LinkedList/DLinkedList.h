#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;  // 더미 노드를 가리키는 포인터 변수
	Node* cur;  // 데이터 참조 위치. 참조(순차 조회)나 삭제 시 활용
	Node* before;  // 삭제 시 사용할 포인터 변수 (LinkedRead.c 예제의 dN&dNN과 같은 맥락으로 필요한 멤버)
	int numOfData;
	int (*comp)(LData d1, LData d2);  // 정렬 기준 설정을 위한 멤버 (함수 포인터)
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* data);
int LNext(List* plist, LData* data);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif