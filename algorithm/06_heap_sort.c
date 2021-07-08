// Algorithm Analysis
// �� ���� (Heap Sort) : �� ������ ����Ͽ� �����Ѵ�

#include <stdio.h>

int size = 8;
int heap[8] = { 6, 9, 10, 4, 5, 1, 12, 3 };

int main() {
	// Ʈ�� ������ �ִ� �� ������ ��ȯ
	for (int i = 1; i < size; i++) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (heap[root] < heap[child]) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			child = root;
		} while (child != 0);
	}
	// �� ũ�⸦ ���̸鼭 �ݺ������� ���� ����
	for (int i = size - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int child = 1;
		do {
			child = 2 * root + 1;
			// �ڽ� �� �� ū ���� ã��
			if (heap[child] < heap[child + 1] && child < i - 1) {
				child++;
			}
			// root���� �ڽ��� �� ũ�� ��ȯ
			if (heap[root] < heap[child] && child < i) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			root = child;
		} while (child < i);
	}
	for (int i = 0; i < size; i++)
		printf("%d ", heap[i]);

	return 0;
}

/*
���� �ð� ���⵵ O(log N) * ��ü ������ �� N
= ��ü �ð� ���⵵ : O(N * logN)
*/