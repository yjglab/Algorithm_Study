// Algorithm Analysis
// ���� �켱 Ž�� (Depth First Search)

#include <iostream>
#include <vector>

using namespace std;

int num = 7; // ��ü ��� ��
int visited[8]; // �湮 üũ�� �迭. [0]�� �� ���
vector<int> arr[8]; // ������ ��带 ������ �迭

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