// Algorithm Analysis
// ���� ���� (Topology Sort)
// �ð� ���⵵ : O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n = 7;
int inDegree[MAX]; // ���� ����
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// ���� ������ 0�� ������ ť�� ����
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// ���� ������ ����Ƿ��� ��Ȯ�� n���� ������ �湮
	for (int i = 1; i <= n; i++) {
		// n���� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �߻��� ��
		if (q.empty()) {
			printf("����Ŭ �߻�");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int j = a[x][i];
			if (--inDegree[j] == 0) {
				q.push(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
}
int main() {
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[2].push_back(6);
	inDegree[6]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(7);
	inDegree[7]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(4);
	inDegree[4]++;

	topologySort();
}