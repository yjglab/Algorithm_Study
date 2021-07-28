
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;
vector<int> cow[MAX];
int house[MAX];
bool done[MAX];
int n, m, s;

bool dfs(int x) {
	for (int i = 0; i < cow[x].size(); i++) {
		int t = cow[x][i];
		if (done[t]) continue;
		done[t] = true;
		if (house[t] == 0 || dfs(house[t])) {
			house[t] = x;
			return true;
		}
	}
	return false;
}
int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &s);
		for (int j = 1; j <= s; j++) {
			int t;
			scanf_s("%d", &t);
			cow[i].push_back(t);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fill(done, done + MAX, false);
		if (dfs(i)) cnt++;
	}
	printf("%d\n", cnt);
	
}