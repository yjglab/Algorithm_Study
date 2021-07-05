// Algorithm Programming
// 삽입 정렬(Insertion Sort) : (필요할 때만)각 데이터를 적절한 위치에 삽입한다.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, temp;
	int arr[10] = { 1, 9, 4, 6, 11, 10, 3, 15, 2, 13 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
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

시간복잡도가 같은 선택, 버블 정렬에 비해 연산 수가 적어 다소 효율적.
*/
