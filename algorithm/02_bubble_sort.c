// Algorithm Programming
// 버블 정렬(Bubble Sort) : 옆에 있는 값과 비교하여 더 작은 값을 앞으로 보낸다.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, temp;
	int arr[10] = { 1, 9, 4, 6, 11, 10, 3, 15, 2, 13 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}

/* 시간복잡도
= 10 + 9 + 8 + ... + 1 = 10 * (10 + 1) / 2 = 55
= N * (N + 1) / 2
= N * N
= O(N * N)

정렬 알고리즘 중 가장 느리고 효율성이 떨어짐
*/
