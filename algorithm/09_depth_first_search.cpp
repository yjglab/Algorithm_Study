// Algorithm Analysis
// 깊이 우선 탐색 (Depth First Search)

#include <iostream>
#include <vector>

using namespace std;

int num = 7; // 전체 노드 수
int visited[8]; // 방문 체크용 배열. [0]은 미 사용
vector<int> arr[8]; // 인접한 노드를 연결할 배열

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < arr[x].size(); i++) {
		int j = arr[x][i];
		dfs(j);
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

	dfs(1); 
}
// 1 2 3 6 7 4 5