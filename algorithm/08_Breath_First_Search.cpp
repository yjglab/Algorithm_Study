// Algorithm Analysis
// 너비 우선 탐색 (Breath First Search)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int num = 7; // 전체 노드 수
int visited[7]; // 방문 체크용 배열
vector<int> arr[8]; // 인접한 노드를 연결할 배열

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < arr[x].size(); i++) {
			int j = arr[x][i];
			if (!visited[j]) {
				q.push(j);
				visited[j] = true;
			}
		}

	}
}
int main() {
	arr[1].push_back(2);
	arr[2].push_back(1);

	arr[1].push_back(3);
	arr[3].push_back(1);

	arr[2].push_back(3);
	arr[3].push_back(2);

	arr[2].push_back(4);
	arr[4].push_back(2);

	arr[2].push_back(5);
	arr[5].push_back(2);

	arr[3].push_back(6);
	arr[6].push_back(3);

	arr[3].push_back(7);
	arr[7].push_back(3);

	arr[4].push_back(5);
	arr[5].push_back(4);

	arr[6].push_back(7);
	arr[7].push_back(6);

	bfs(1);
}