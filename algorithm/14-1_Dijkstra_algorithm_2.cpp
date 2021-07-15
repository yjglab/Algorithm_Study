// Algorithm Analysis
// 변형 데이크스트라 알고리즘 (Dijkstra Algorithm)
// 시간 복잡도 O(N*logN)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 6;
int INF = 1000000000;

vector<pair<int, int>> arr[7]; // 정점(first)로 가는 최단 경로(second)
int d[7];

void dijkstra(int start) {
	d[start] = 0; // 자기 자신에 대한 경로는 0
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0)); 

	while (!pq.empty()) {
		int cur = pq.top().first; // 현재 정점
		int dist = -pq.top().second; // 최단 경로
		pq.pop();

		if (d[cur] < dist) continue;
		for (int i = 0; i < arr[cur].size(); i++) { // pair가 만들어진 수 만큼
			int next = arr[cur][i].first; // 방문한 정점의 인접 정점
			int nextDist = dist + arr[cur][i].second; // 방문한 정점을 거쳐 인접 정점으로 가는 최단 경로
			if (nextDist < d[next]) { // 기존 경로보다 더 적다면
				d[next] = nextDist; // 새로 설정
				pq.push(make_pair(next, -nextDist)); 
			}
		}
	}
}
int main() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	arr[1].push_back(make_pair(2, 6));
	arr[1].push_back(make_pair(3, 8));
	arr[1].push_back(make_pair(6, 13));

	arr[2].push_back(make_pair(1, 6));
	arr[2].push_back(make_pair(3, 9));
	arr[2].push_back(make_pair(4, 14));

	arr[3].push_back(make_pair(1, 8));
	arr[3].push_back(make_pair(2, 9));
	arr[3].push_back(make_pair(4, 10));
	arr[3].push_back(make_pair(6, 1));

	arr[4].push_back(make_pair(2, 14));
	arr[4].push_back(make_pair(3, 10));
	arr[4].push_back(make_pair(5, 5));

	arr[5].push_back(make_pair(4, 5));
	arr[5].push_back(make_pair(6, 8));

	arr[6].push_back(make_pair(1, 13));
	arr[6].push_back(make_pair(3, 1));
	arr[6].push_back(make_pair(5, 8));

	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}
// 0 6 8 18 17 9