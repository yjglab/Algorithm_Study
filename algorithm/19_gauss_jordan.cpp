// Algorithm Analysis
// ���콺 ���� �ҰŹ� (Gauss-Jordan)

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
#define matrix vector<vector<double>>
#define row vector<double>

void print(matrix& mtx) {
	cout << "------------\n";
	for (int i = 0; i < mtx.size(); i++) {
		for (auto& itr : mtx[i]) {
			printf("%3.0lf ", itr);
		}
		cout << endl;
	}
	cout << "------------\n";
}
// �⺻�� ����1 : ��� k��
void EO1(matrix& mtx, int n, double k) { 
	for (auto& itr : mtx[n]) {
		itr = k * itr;
	}
	print(mtx);
}
// �⺻�� ����2 : ��� k���� ���� �ٸ� �࿡ ���ϱ�
void EO2(matrix& mtx, int n, double k, int j) {
	for (int i = 0; i < mtx[0].size(); i++) {
		mtx[j][i] = mtx[j][i] + k * mtx[n][i];
	}
	print(mtx);
}
int findNonZero(row& r) {
	for (int i = 0; i < r.size(); i++) {
		if (fabs(r[i]) >= 0.0000000001) return i;
		continue;
	}
	return -1;
}
// �� ��ٸ���ȭ
void echelon(matrix& mtx) {
	// �� �� ��ȯ �ʿ��� ����� ������� �ʽ��ϴ�.
	for (int i = 0; i < mtx.size(); i++) {
		int j = findNonZero(mtx[i]); // leading 1�� ���� �� ��ġ ��������
		if (j == -1) continue;
		else { // leading 1�� ���� ���� �Ʒ��� �׿� �� ���� ��� k�� ����
			for (int k = 0; k < mtx.size() - 1 - i; k++) {
				EO2(mtx, i, (-1) * mtx[1 + i + k][j] / mtx[i][j], 1 + i + k);
			}
		}
	}
}
// ��� �� ��ٸ���ȭ
void reducedEchelon(matrix& mtx) {
	echelon(mtx);
	// leading 1���� �����
	for (int i = 0; i < mtx.size(); i++) {
		int j = findNonZero(mtx[i]);
		if (j == -1) continue;
		else {
			EO1(mtx, i, 1 / mtx[i][j]);
		}
	}
	//back substitution
	for (int i = mtx.size() - 1; i >= 0; i--) {
		int j = findNonZero(mtx[i]);
		if (j == -1) continue;
		else {
			for (int k = 0; k < i; k++) {
				EO2(mtx, i, (-1) * mtx[i - 1 - k][j], i - 1 - k);
			}
		}
	}
}

int main() {
	cout << "��� ������(����) �Է� >> ";
	int size;
	cin >> size;
	cout << "��� �Է� >> ";
	matrix input;
	for (int i = 0; i < size; i++) {
		row r;
		for (int j = 0; j < size; j++) {
			double temp;
			cin >> temp;
			r.push_back(temp);
		}
		input.push_back(r);
	}
	reducedEchelon(input);
	system("pause");
}

