// Algorithm Analysis
// 퀵 정렬(Quick Sort) : 특정 값을 기준으로 큰 데이터와 작은 데이터를 서로 교환한 후 배열을 두 집합으로 나눈다.

#include <stdio.h>

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) { // 엇갈릴 때까지
		while (i <= end && data[i] <= data[pivot]) // 피벗 보다 큰 값을 만날 때까지
			i++;
		while (j > start && data[j] >= data[pivot]) // 피벗 보다 작은 값을 만날 때까지
			j--;
		if (i > j) { // 엇갈리면 피벗과 교체
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else { // 엇갈리지 않으면
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	int arr[10] = { 4, 9, 1, 6, 11, 10, 3, 15, 2, 13 };
	quickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}

/* 
평균 시간복잡도
= O(N * logN)
최악 시간복잡도
= O(N^2)
*/