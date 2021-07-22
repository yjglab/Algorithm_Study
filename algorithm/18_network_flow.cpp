// Algorithm Analysis
// 네트워크 플로우 (Network Flow)

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6;
int result;
int cap[MAX][MAX]; // 용량
int flow[MAX][MAX]; // 현재 유량
int vtd[MAX]; // 현재 정점 방문 여부

vector<int> a[MAX];

// 최대 유량 계산
void maxFlow(int s, int e) {
	while (1) {
		fill(vtd, vtd + MAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int j = a[x][i]; // 인접 정점 가져옴
				// 방문하지 않은 정점 중 용량이 남은 경우
				if (cap[x][j] - flow[x][j] > 0 && vtd[j] == -1) { // 흐를 수 있는 경우 && 방문하지 않은 경우
					q.push(j);
					vtd[j] = x; // 경로를 기억함
					if (j == e) break; // 도착지에 도달한 경우
				}
			}
		}
		// 모든 경로를 다 찾은 경우
		if (vtd[e] == -1) break;
		int f = INF;
		// 거꾸로 최소 유량 탐색
		for (int i = e; i != s; i = vtd[i]) {
			f = min(f, cap[vtd[i]][i] - flow[vtd[i]][i]);
		}
		// 최소 유량만큼 추가
		for (int i = e; i != s; i = vtd[i]) {
			flow[vtd[i]][i] += f;
			flow[i][vtd[i]] -= f;
		}
		result += f;
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);
	cap[1][2] = 14;

	a[1].push_back(4);
	a[4].push_back(1);
	cap[1][4] = 12;

	a[2].push_back(3);
	a[3].push_back(2);
	cap[2][3] = 5;

	a[2].push_back(4);
	a[4].push_back(2);
	cap[2][4] = 4;

	a[2].push_back(5);
	a[5].push_back(2);
	cap[2][5] = 6;

	a[2].push_back(6);
	a[6].push_back(2);
	cap[2][6] = 10;

	a[3].push_back(6);
	a[6].push_back(3);
	cap[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	cap[4][5] = 11;

	a[5].push_back(3);
	a[3].push_back(5);
	cap[5][3] = 4;

	a[5].push_back(6);
	a[6].push_back(5);
	cap[5][6] = 7;

	maxFlow(1, 6);
	printf("%d", result);
}