// Algorithm Analysis
// ���� ���� ��� (Strongly Connected Component)

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int v, e, id;
int d[MAX];
int sccNum; // SCC ����
int sn[MAX]; // i�� ���� SCC�� ��ȣ
vector<int> a[MAX];
bool finished[MAX]; // SCC �����Ǹ� true
stack<int> s;
vector<vector<int>> SCC;

int DFS(int c) {
	d[c] = ++id; // ������ ���� id �Ҵ�
	s.push(c); // ���ÿ� �ڽ��� ����

	int result = d[c];
	for (int next : a[c]) {
		// ���� �湮���� ���� �����̸�
		if (d[next] == 0) result = min(result, DFS(next));
		// �湮�� ������ ���� SCC�� �������� ���� �����̸�
		else if (!finished[next]) result = min(result, d[next]);
	}

	// �ڽŰ� �ڽ��� �ڽ� �������� �� �� �ִ� ���� ���� ������ �ڽ��� ��� SCC ����
	if (result == d[c]) {
		vector<int> scc;
		// ���ÿ��� �ڽ��� ���� ������ pop
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc); // SCC ����
		sccNum++;
	}
	return result;
}

int main() {
	// �׷��� ���� �Է�
	scanf_s("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int p, q;
		scanf_s("%d %d", &p, &q);
		a[p].push_back(q);
	}
	// DFS�� �����ϸ� SCC ����
	for (int i = 1; i < v; i++) {
		if (d[i] == 0) DFS(i);
	}
	printf("\nSCC ���� : %d\n", sccNum);
	// �� SCC ���
	for (auto& currSCC : SCC) {
		for (int curr : currSCC)
			printf("%d ", curr);
		printf("\n");
	}
}
/*
SCC ���� : 3
6 7
3 4 8
1 2 5
*/

/*
8 14
1 2
2 3
2 5
2 6
3 4
3 7
4 3
4 8
5 1
5 6
6 7
7 6
8 4
8 7
*/