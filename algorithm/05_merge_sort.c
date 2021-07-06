// Algorithm Analysis
// ���� ���� (Merge Sort) : ������ �迭�� ��Ȯ�� ������ ������ ���߿� ���ļ� ����.

#include <stdio.h>

int num = 8;
int sorted[8]; // ���ĵ� �迭�� �ݵ�� ��������.

void merge(int a[], int m, int mid, int n) { // m:������, mid:�߰���, n:����
	int i = m;
	int j = mid + 1;
	int k = m;
	// ���� ������� �迭�� ����
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
	// ���� ������ ����
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
	// ���ĵ� �迭�� ����
	for (int p = m; p <= n; p++) {
		a[p] = sorted[p];
	}
}
void mergeSort(int a[], int m, int n) {
	// ũ�Ⱑ 1���� ū ���
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
�ð� ���⵵ : O(N * logN)
*/