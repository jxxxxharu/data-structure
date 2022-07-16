#include <stdio.h>

int BSearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;  // 1) 중앙 찍어서

		if (target == arr[mid]) return mid;  // 2) ~인지 아닌지 보고
		else {  // 3) 없으면 반 자르기
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;  // 못 찾으면 -1 리턴
}


int main(void) {
	int arr[] = { 1,3,5,7,9 };  // 이진탐색 전제조건: 정렬
	int len = sizeof(arr) / sizeof(int);
	int target, idx;
	
	target = 7;
	idx = BSearch(arr, len, target);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr[idx]);

	target = 4;
	idx = BSearch(arr, len, target);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr[idx]);
	
	return 0;
}