/** LinkedRead.c에 더미 노드만 추가 **/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = (Node*)malloc(sizeof(Node));  // 수정된 문장. 더미 노드 추가
	Node* tail = head;  // 수정된 문장. tail도 더미 노드를 가리키도록 초기 세팅
	Node* cur = NULL;
	
	Node* newNode = NULL;

	/* 입력 */
	int readData = 0;

	while(1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1) break;

		// 노드 추가
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next - NULL;

		tail->next = newNode;  // 'tail이 가리키는 노드의 next'에 새 노드(주소값)를 저장

		tail = newNode;  // tail이 새 노드를 가리키게
	}
	printf("\n");

	/* 출력 */
	if (head == tail)
		printf("저장된 수가 존재하지 않습니다.");
	else {
		// 데이터 순차적 접근(조회)
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	/* 전체 노드 삭제 및 메모리 해제 */
	if (head == tail) return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 삭제. \n", head->data);
			free(delNode);
		}
	}

	return 0;
}