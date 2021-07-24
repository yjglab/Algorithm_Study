// Algorithm Analysis
// 문자열 매칭 알고리즘

#include <iostream>

using namespace std;

// s1 문자열에서 s2 문자열을 찾아냄
int findString(string s1, string s2) {
	int s1Size = s1.size();
	int s2Size = s2.size();
	for (int i = 0; i <= s1Size - s2Size; i++) {
		bool isFind = true; // 발견 여부
		for (int j = 0; j < s2Size; j++) {
			if (s1[i + j] != s2[j]) { // 모두 불일치하면
				isFind = false;
				break;
			}	
		}
		if (isFind) {
			return i; // 발견된 index 출력
		}
	}
	return -1; // 실패
}
int main() {
	string s1 = "yjglab";
	string s2 = "gla";
	int result = findString(s1, s2);
	if (result == -1)
		printf("발견 실패");
	else 
		printf("%d번째 index에서 발견", result + 1);
}