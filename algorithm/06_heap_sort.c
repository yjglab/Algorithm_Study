// Algorithm Analysis
// 힙 정렬 (Heap Sort) : 힙 구조를 사용하여 정렬한다

#include <stdio.h>

int size = 8;
int heap[8] = { 6, 9, 10, 4, 5, 1, 12, 3 };

int main() {
	// 트리 구조를 최대 힙 구조로 변환
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
	// 힙 크기를 줄이면서 반복적으로 힙을 구성
	for (int i = size - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int child = 1;
		do {
			child = 2 * root + 1;
			// 자식 중 더 큰 값을 찾기
			if (heap[child] < heap[child + 1] && child < i - 1) {
				child++;
			}
			// root보다 자식이 더 크면 교환
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
생성 시간 복잡도 O(log N) * 전체 데이터 수 N
= 전체 시간 복잡도 : O(N * logN)
*/