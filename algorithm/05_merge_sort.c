// Algorithm Analysis
// 병합 정렬 (Merge Sort) : 데이터 배열을 정확히 반으로 나누고 나중에 합쳐서 정렬.

#include <stdio.h>

int num = 8;
int sorted[8]; // 정렬된 배열은 반드시 전역으로.

void merge(int a[], int m, int mid, int n) { // m:시작점, mid:중간점, n:끝점
	int i = m;
	int j = mid + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입
	while (i <= mid && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터 삽입
	if (i > mid) {
		for (int p = j; p <= n; p++) {
			sorted[k] = a[p];
			k++;
		}
	}
	else {
		for (int p = i; p <= mid; p++) {
			sorted[k] = a[p];
			k++;
		}
	}
	// 정렬된 배열을 삽입
	for (int p = m; p <= n; p++) {
		a[p] = sorted[p];
	}
}
void mergeSort(int a[], int m, int n) {
	// 크기가 1보다 큰 경우
	if (m < n) {
		int mid = (m + n) / 2;
		mergeSort(a, m, mid);
		mergeSort(a, mid + 1, n);
		merge(a, m, mid, n);
	}
}
int main() {
	int arr[8] = { 8, 2, 6, 5, 1, 4, 2, 7 };
	mergeSort(arr, 0, num - 1);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

/*
시간 복잡도 : O(N * logN)
*/