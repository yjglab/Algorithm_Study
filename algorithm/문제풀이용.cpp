#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
using namespace std;

class Data {
public:
	int vtx;
	int mtime;
	Data(int vtx, int mtime) {
		this->vtx = vtx;
		this->mtime = mtime;
	}
};

int n, sv, ev;
int inDegree[MAX], result[MAX], done[MAX];
vector<Data> a[MAX]; // sv -> ev : a
vector<Data> b[MAX]; // ev -> sv : b

void topologySort() {
	queue<int> q;
	q.push(sv);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Data d = Data(a[x][i].vtx, a[x][i].mtime);
			if (result[d.vtx] <= d.mtime + result[x]) {
				result[d.vtx] = d.mtime + result[x];
			}
			if (--inDegree[d.vtx] == 0) {
				q.push(d.vtx);
			}
		}
	}
	int count = 0;
	q.push(ev);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Data d2 = Data(b[y][i].vtx, b[y][i].mtime);
			if (result[y] - result[d2.vtx] == d2.mtime) {
				count++;
				if (done[d2.vtx] == 0) {
					q.push(d2.vtx);
					done[d2.vtx] = 1;
				}
			}
		}
	}
	printf("%d\n%d", result[ev], count);
}


int main() {
	int m; 
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int stt, end, tim;
		scanf_s("%d %d %d", &stt, &end, &tim);
		a[stt].push_back(Data(end, tim));
		b[end].push_back(Data(stt, tim));
		inDegree[end]++;
	}
	scanf_s("%d %d", &sv, &ev);
	topologySort();
}