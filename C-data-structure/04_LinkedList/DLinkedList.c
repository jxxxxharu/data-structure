#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));  // 앞에 head다음 더미 노드(Dummy Node) 초기 세팅
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;  // 새 노드가 '원래 첫 번째였던 노드'를 가리키도록
	plist->head->next = newNode;  // 더미 노드가 새 노드를 가리키도록
	(plist->numOfData)++;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;  // pred는 처음에 더미 노드를 가리킴
	newNode->data = data;

	// 새 노드가 들어갈 위치까지 다음 노드로 하나씩 이동
	while ((pred->next != NULL) && (plist->comp(data, pred->next->data) != 0)) {
		pred = pred->next;
	}
	
	// pred -> nextNode 가 되게 연결(삽입)
	newNode->next = pred->next;  // 새 노드의 오른쪽 연결
	pred->next = newNode;  // 새 노드의 왼쪽 연결

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)  // 정렬 기준이 없으면, 
		FInsert(plist, data);  // 머리에 노드 추가
	else
		SInsert(plist, data);  // 정렬 기준에 따라 노드 추가
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = rpos->next;  // 소멸 대상을 리스트에서 제거
	plist->cur = plist->before;  // cur이 가리키는 곳도 한 칸 앞으로 다시 세팅

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}