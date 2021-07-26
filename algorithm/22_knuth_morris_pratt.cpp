// Algorithm Analysis
// KMP 알고리즘 (Knuth-Morris-Pratt)

#include <iostream>
#include <vector>
using namespace std;

// 접두사와 접미사 일치하는 최대 일치 길이 테이블 구하기
vector<int> makeTable(string fs) { // fs : 검색할 문자열
	int fsSize = fs.size();
	vector<int>	table(fsSize, 0); // 0으로 초기화
	int j = 0; 
	for (int i = 1; i < fsSize; i++) {
		// 일치하지 않으면
		while (j > 0 && fs[i] != fs[j]) { 
			j = table[j - 1];
		}
		// 일치하면
		if (fs[i] == fs[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

// ws : 검색을 당하는 문자열, fs : 검색할 문자열
void KMP(string ws, string fs) { 
	vector<int> table = makeTable(fs);
	int wsSize = ws.size();
	int fsSize = fs.size();
	int j = 0;
	for (int i = 0; i < ws.size(); i++) {
		// 일치하지 않는 경우 (단, j > 0)
		while (j > 0 && ws[i] != fs[j]) {
			j = table[j - 1];
		}
		// 일치한 경우
		if (ws[i] == fs[j]) {
			if (j == fsSize - 1) { // 문자열이 완전히 일치하면
				printf("%d번째에서 발견\n", i - fsSize + 2);
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
	
	// 최대 일치 길이 테이블 결과
	vector<int> table = makeTable(fs);
	for (int i = 0; i < table.size(); i++) {
		printf("%d ", table[i]);
	}
	printf("\n");
	// KMP 수행 결과
	KMP(ws, fs);
}
/*
0 0 1 0 0 1 2 3
2번째에서 발견
12번째에서 발견
*/