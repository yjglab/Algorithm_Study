// Algorithm Analysis
// 가우스 조던 소거법 (Gauss-Jordan)

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
// 기본행 연산1 : 상수 k배
void EO1(matrix& mtx, int n, double k) { 
	for (auto& itr : mtx[n]) {
		itr = k * itr;
	}
	print(mtx);
}
// 기본행 연산2 : 상수 k배한 값을 다른 행에 더하기
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
// 행 사다리꼴화
void echelon(matrix& mtx) {
	// ※ 행 교환 필요한 행렬은 고려하지 않습니다.
	for (int i = 0; i < mtx.size(); i++) {
		int j = findNonZero(mtx[i]); // leading 1을 만들 항 위치 가져오기
		if (j == -1) continue;
		else { // leading 1을 만들 항의 아래쪽 항에 한 행의 상수 k배 연산
			for (int k = 0; k < mtx.size() - 1 - i; k++) {
				EO2(mtx, i, (-1) * mtx[1 + i + k][j] / mtx[i][j], 1 + i + k);
			}
		}
	}
}
// 기약 행 사다리꼴화
void reducedEchelon(matrix& mtx) {
	echelon(mtx);
	// leading 1으로 만들기
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
	cout << "행렬 사이즈(차원) 입력 >> ";
	int size;
	cin >> size;
	cout << "행렬 입력 >> ";
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

