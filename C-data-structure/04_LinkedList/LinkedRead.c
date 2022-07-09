#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;  // 리스트의 머리를 가리키는 포인터 변수
	Node* tail = NULL;  // 리스트의 머리를 가리키는 포인터 변수 (no필수)
	Node* cur = NULL;  // 데이터의 순차적 조회에 사용되는 포인터 변수

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

		if (head == NULL) head = newNode;
		else tail->next = newNode;  // 'tail이 가리키는 노드의 next'에 새 노드(주소값)를 저장

		tail = newNode;  // tail이 새 노드를 가리키게.
	}
	printf("\n");

	/* 출력 */
	if (head == NULL)
		printf("저장된 수가 존재하지 않습니다.");
	else {
		// 데이터 순차적 접근(조회)
		cur = head;  // 첫 번째 노드 참조
		printf("%d ", cur->data);
		while (cur->next != NULL) { // 두번 째 이후 노드 참조
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	/* 전체 노드 삭제 및 메모리 해제 */
	if (head == NULL) return 0;
	else {
		Node* delNode = head;  // 삭제할 노드
		Node* delNextNode = head->next;  // 삭제할 노드가 가리키는 다음 노드(주소값)

		// 첫 번째 노드 삭제
		printf("%d 삭제. \n", head->data);
		free(delNode);

		// 두 번째 이후 노드 삭제
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 삭제. \n", head->data);
			free(delNode);
		}
	}

	return 0;
}