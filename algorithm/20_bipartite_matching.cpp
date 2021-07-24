// Algorithm Analysis
// �̺� ��Ī �˰��� (Bipartite Matching)

#include <iostream>
#include <vector>
#define MAX 101

using namespace std;
vector<int> vtx[MAX]; // ���� vtx
int slt[MAX]; // vtx�� �����ϰ� �ִ� ����
bool done[MAX]; // ó�� ����
int n = 5; // ���� ��, ���� ��

bool dfs(int x) {
	// ����� ��� ������ ���� �� �� �ִ� �� �õ�
	for (int i = 0; i < vtx[x].size(); i++) {
		int p = vtx[x][i];
		// �̹� ó���� ������ ������� ����
		if (done[p]) continue;
		done[p] = true;
		// ����ְų� ���� ������ �� �� ������ �ִ� ���
		if (slt[p] == 0 || dfs(slt[p])) {
			slt[p] = x;
			return true;
		}
		
	}
	return false;
}

int main() {
	vtx[1].push_back(1);
	vtx[1].push_back(3);
	vtx[1].push_back(5);
	vtx[2].push_back(1);
	vtx[2].push_back(2);
	vtx[3].push_back(5);
	vtx[4].push_back(3);
	vtx[5].push_back(2);
	
	int cnt = 0; // ��Ī ��
	for (int i = 1; i <= n; i++) {
		fill(done, done + MAX, false);
		if (dfs(i)) cnt++;
	}
	printf("%��Ī %d�� ����\n", cnt);
	for (int i = 1; i < MAX; i++) {
		if (slt[i] != 0) {
			printf("%d => %d\n", slt[i], i);
		}
	}
}