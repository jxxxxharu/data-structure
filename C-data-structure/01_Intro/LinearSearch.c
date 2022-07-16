#include <stdio.h>

int LSearch(int arr[], int len, int target) {
	for(int i=0; i<len; i++) {
		if (arr[i] == target) return i;
	}
	return -1;
}

int main(void) {
	int arr[] = { 3,5,2,4,9 };
	int len = sizeof(arr) / sizeof(int);
	int target, idx;
	
	target = 7;
	idx = LSearch(arr, len, target);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr[idx]);

	target = 4;
	idx = LSearch(arr, len, target);
	if (idx == -1)
		printf("Search failed..!\n");
	else
		printf("arr[%d] = %d\n", idx, arr[idx]);
	
	return 0;
}