// Algorithm Analysis
// ��� ���� (Counting Sort) : ���� ���� �ִ� �����͸� ũ�⸦ �������� ī��Ʈ�Ͽ� ����

#include <stdio.h>

int main() {
	int temp;
	int count[5];
	int arr[10] = { 1, 4, 5, 2, 2, 4, 1, 3, 5, 3 };

	for (int i = 0; i < 5; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 10; i++) {
		count[arr[i] - 1]++;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}
	return 0;
}

/*
�ð� ���⵵ = O(N)
*/