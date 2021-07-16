// Algorithm Analysis
// 플로이드-워셜 알고리즘 (Floyd-Warshall Algorithm)

#include <iostream>

using namespace std;

int n = 5;
int INF = 100;

int arr[5][5] = {
	{0, 2, 7, INF, 4},
	{INF, 0, INF, 3, 6},
	{INF, 3, 0, INF, INF},
	{-1, INF, -4, 0, INF},
	{INF, INF, INF, 5, 0},
};

void floydWarshall() {
	// 결과 그래프
	int d[5][5];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = arr[i][j];
		}
	}

	// p : 거쳐갈 정점
	for (int p = 0; p < n; p++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][p] + d[p][j] < d[i][j]) {
					d[i][j] = d[i][p] + d[p][j];
				}
			}
		}
	}

	// 결과 그래프 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", d[i][j]);
		}
		cout << endl;
	}
	
}
int main() {
	floydWarshall();
}
/* 
  0   2   1   5   4
  2   0  -1   3   6
  5   3   0   6   9
 -1  -1  -4   0   3
  4   4   1   5   0
  */