// Algorithm Programming
// ���� ����(Selection Sort) : ���� ���� ���� �����Ͽ� ������ ������.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, min, index, temp;
	int arr[10] = { 1, 9, 4, 6, 11, 10, 3, 15, 2, 13 };
	for (i = 0; i < 10; i++) {
		min = INT_MAX;
		for (j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}

/* �ð����⵵
= 10 + 9 + 8 + ... + 1 = 10 * (10 + 1) / 2 = 55
= N * (N + 1) / 2 
= N * N
= O(N * N)
*/
