// Algorithm Analysis
// ������ ����ũ��Ʈ�� �˰��� (Dijkstra Algorithm)
// �ð� ���⵵ O(N^2)

#include <iostream>
using namespace std;

int n = 6;
int INF = 1000000000;

int arr[6][6] = {
	{0, 6, 8, INF, INF, 13},
	{6, 0, 9, 14, INF, INF},
	{8, 9, 0, 10, INF, 1},
	{INF, 14, 10, 0, 5, INF}, 
	{INF, INF, INF, 5, 0, 8},
	{13, INF, 1, INF, 8, 0},
};
bool visited[6]; // �湮�� ����
int d[6]; // �ִ� ���(���)

int getMinIndex() {
	int min = INF;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] < min && !visited[i]) {
			min = d[i];
			idx = i;
		}
	}
	return idx;
}
void dijkstra(int start) {
	for (int i = 0; i < n; i++) {
		d[i] = arr[start][i];
	}
	visited[start] = true;
	for (int i = 0; i < n - 2; i++) {
		int minIndex = getMinIndex(); // ������ �ִ� ��� index
		visited[minIndex] = true;
		for (int j = 0; j < 6; j++) {
			if (!visited[j]) {
				if (d[minIndex] + arr[minIndex][j] < d[j]) { // �� ���� �ִ� ��θ� �߰��ϸ�
					d[j] = d[minIndex] + arr[minIndex][j]; // ��θ� ���Ӱ� ����
				}
			}
		}
	}
}
int main() {
	dijkstra(0);
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
}
// 0 6 8 18 17 9