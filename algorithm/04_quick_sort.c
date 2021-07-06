// Algorithm Analysis
// �� ����(Quick Sort) : Ư�� ���� �������� ū �����Ϳ� ���� �����͸� ���� ��ȯ�� �� �迭�� �� �������� ������.

#include <stdio.h>

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) { // ������ ������
		while (i <= end && data[i] <= data[pivot]) // �ǹ� ���� ū ���� ���� ������
			i++;
		while (j > start && data[j] >= data[pivot]) // �ǹ� ���� ���� ���� ���� ������
			j--;
		if (i > j) { // �������� �ǹ��� ��ü
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else { // �������� ������
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
��� �ð����⵵
= O(N * logN)
�־� �ð����⵵
= O(N^2)
*/