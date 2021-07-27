// Algorithm Analysis
// ���-ī�� �˰��� (Rabin-Karp)

#include <iostream>

using namespace std;

// ws : �˻� ��� ���ڿ� , ps : �˻��� ���� ���ڿ�
void findString(string ws, string ps) {
	int wsSize = ws.size();
	int psSize = ps.size();

	int wsHash = 0;
	int psHash = 0;
	int power = 1; // ������

	for (int i = 0; i <= wsSize - psSize; i++) {
		if (i == 0) {
			for (int j = 0; j < psSize; j++) {
				wsHash += ws[psSize - 1 - j] * power;
				psHash += ps[psSize - 1 - j] * power;
				if (j < psSize - 1) power *= 3;
			}
		}
		else {
			wsHash = 3 * (wsHash - ws[i - 1] * power) + ws[psSize - 1 + i];
		}
		if (wsHash == psHash) {
			bool isFind = true;
			// �쿬�� �ؽð��� ��ģ ��� ���� ���ڿ� ��ġ ���� �˻�
			for (int j = 0; j < psSize; j++) {
				if (ws[i + j] != ps[j]) {
					isFind = false;
					break;
				}
			}
			if (isFind) {
				cout << wsHash << " " << psHash << endl;
				printf("%d��°���� �߰�\n", i + 1);
			}
		}
	}
}
int main() {
	string ws = "AABDCDABD";
	string ps = "ABD";
	findString(ws, ps);
}