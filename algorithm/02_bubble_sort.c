// Algorithm Programming
// ���� ����(Bubble Sort) : ���� �ִ� ���� ���Ͽ� �� ���� ���� ������ ������.

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

/* �ð����⵵
= 10 + 9 + 8 + ... + 1 = 10 * (10 + 1) / 2 = 55
= N * (N + 1) / 2
= N * N
= O(N * N)

���� �˰��� �� ���� ������ ȿ������ ������
*/
