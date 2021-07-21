// Algorithm Analysis
// 위상 정렬 (Topology Sort)
// 시간 복잡도 : O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n = 7;
int inDegree[MAX]; // 진입 차수
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// 진입 차수가 0인 정점을 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// 위상 정렬이 수행되려면 정확히 n개의 정점을 방문
	for (int i = 1; i <= n; i++) {
		// n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
		if (q.empty()) {
			printf("사이클 발생");
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