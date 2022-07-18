/* 리스트 라이브러리 사용해보기 */
#include <stdio.h>
#include "ArrayList.h"

int main() {

	// 1) 리스트를 생성 및 초기화 한 다음, 정수 1부터 9까지 리스트에 저장한다.
	List list;
	int data;
	ListInit(&list);

	for (int i=1; i<=9; i++) {
		LInsert(&list, i);
	}


	// 2) 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산해 출력한다.
	int sum = 0;
	if (LFirst(&list, &data)) {
		sum += data;
		while (LNext(&list, &data))
			sum += data;
	}
	printf("* SUM of list: %d\n", sum);


	// 3) 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.
	if (LFirst(&list, &data)) {
		if ((data%2 == 0) || (data%3 == 0))
			LRemove(&list);

		while (LNext(&list, &data)) {
			if ((data%2 == 0) || (data%3 == 0))
				LRemove(&list);
		}
	}


	// 4) 삭제 후 남은 데이터를 순서대로 출력한다.
	printf("* after LRemove(): ");
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}

	return 0;
}