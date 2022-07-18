#include <stdio.h>

/* 이진 탐색 & 최악인 경우의 연산횟수 구하기 */
int BSearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;  // 연산횟수 기록

	while (first <= last) {
		mid = (first + last) / 2;

		if (target == arr[mid]) return mid;
		else {
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
		opCount++;  // (연산횟수)++
	}

	printf("연산 횟수: %d\n", opCount);  // 탐색 실패 시, 연산횟수 출력
	return -1;
}

int main(void) {
	int arr1[500] = { 0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };
	int idx;
	
	/* 연산횟수: 순차-500, 이진-9 */
	idx = BSearch(arr1, sizeof(arr1)/sizeof(int), 1);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr1[idx]);

	/* 연산횟수: 순차-5000, 이진-13 */
	idx = BSearch(arr2, sizeof(arr2)/sizeof(int), 1);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr2[idx]);

	/* 연산횟수: 순차-50000, 이진-16 */
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 1);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr3[idx]);

	return 0;
}