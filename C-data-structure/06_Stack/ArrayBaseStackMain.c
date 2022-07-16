#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	/* 스택 생성 및 초기화 */
	Stack stack;
	StackInit(&stack);

	/* push */
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);  // 1 2 3 4 5

	/* pop */
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));  // 5 4 3 2 1

	// LIFO (후입선출)

	return 0;
}