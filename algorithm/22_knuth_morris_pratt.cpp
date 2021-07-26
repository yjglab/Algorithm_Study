// Algorithm Analysis
// KMP �˰��� (Knuth-Morris-Pratt)

#include <iostream>
#include <vector>
using namespace std;

// ���λ�� ���̻� ��ġ�ϴ� �ִ� ��ġ ���� ���̺� ���ϱ�
vector<int> makeTable(string fs) { // fs : �˻��� ���ڿ�
	int fsSize = fs.size();
	vector<int>	table(fsSize, 0); // 0���� �ʱ�ȭ
	int j = 0; 
	for (int i = 1; i < fsSize; i++) {
		// ��ġ���� ������
		while (j > 0 && fs[i] != fs[j]) { 
			j = table[j - 1];
		}
		// ��ġ�ϸ�
		if (fs[i] == fs[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

// ws : �˻��� ���ϴ� ���ڿ�, fs : �˻��� ���ڿ�
void KMP(string ws, string fs) { 
	vector<int> table = makeTable(fs);
	int wsSize = ws.size();
	int fsSize = fs.size();
	int j = 0;
	for (int i = 0; i < ws.size(); i++) {
		// ��ġ���� �ʴ� ��� (��, j > 0)
		while (j > 0 && ws[i] != fs[j]) {
			j = table[j - 1];
		}
		// ��ġ�� ���
		if (ws[i] == fs[j]) {
			if (j == fsSize - 1) { // ���ڿ��� ������ ��ġ�ϸ�
				printf("%d��°���� �߰�\n", i - fsSize + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	string ws = "BABADCABABCABADCABA";
	string fs = "ABADCABA";
	
	// �ִ� ��ġ ���� ���̺� ���
	vector<int> table = makeTable(fs);
	for (int i = 0; i < table.size(); i++) {
		printf("%d ", table[i]);
	}
	printf("\n");
	// KMP ���� ���
	KMP(ws, fs);
}
/*
0 0 1 0 0 1 2 3
2��°���� �߰�
12��°���� �߰�
*/