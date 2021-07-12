// Algorithm Analysis
// ũ�罺Į �˰��� (Kruskal Algorithm)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ���� ���� ã��
int getSet(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getSet(set, set[x]);
}

// �� ���� ��ġ��
void unionSet(int set[], int a, int b) {
	a = getSet(set, a);
	b = getSet(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}

// ������ ���� ���� �����ִ��� Ȯ��
int find(int set[], int a, int b) {
	a = getSet(set, a);
	b = getSet(set, b);
	if (a == b) return 1;
	return 0;
}

// ���� ���� Ŭ����
class Edge {
public:
	int vtx[2]; // ����� 2���� ����
	int distance; // �Ÿ�(���)
	Edge(int a, int b, int distance) {
		this->vtx[0] = a;
		this->vtx[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance; // ���� �Ÿ� �켱 ����
	}
};
int main() {
	int v = 9; // ���� �� (0~8)

	vector<Edge> data; // ���� ������ �迭
	data.push_back(Edge(0, 1, 8)); // ����0�� ����1�� ���� ���8
	data.push_back(Edge(0, 2, 12));
	data.push_back(Edge(1, 2, 13));
	data.push_back(Edge(1, 3, 25));
	data.push_back(Edge(1, 4, 9));
	data.push_back(Edge(2, 3, 14));
	data.push_back(Edge(2, 6, 21));
	data.push_back(Edge(3, 4, 20));
	data.push_back(Edge(3, 5, 8));
	data.push_back(Edge(3, 6, 12));
	data.push_back(Edge(3, 7, 12));
	data.push_back(Edge(3, 8, 16));
	data.push_back(Edge(4, 5, 19));
	data.push_back(Edge(5, 7, 11));
	data.push_back(Edge(6, 8, 11));
	data.push_back(Edge(7, 8, 9));

	// ���� ����� �������� ����
	sort(data.begin(), data.end());

	int set[9];
	for (int i = 0; i < v; i++) {
		set[i] = i;
	}
	int sum = 0; // �ּ� ���

	for (int i = 0; i < data.size(); i++) {
		// ����Ŭ�� �߻����� ������ �׷����� ����
		if (!find(set, data[i].vtx[0], data[i].vtx[1])) {
			sum += data[i].distance;
			unionSet(set, data[i].vtx[0], data[i].vtx[1]);
		}
	}
	cout << sum;
}

