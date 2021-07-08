// Algorithm Analysis
// 계수 정렬 (Counting Sort) : 범위 내에 있는 데이터를 크기를 기준으로 카운트하여 정렬

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
시간 복잡도 = O(N)
*/