// Algorithm Analysis
// ���ڿ� ��Ī �˰���

#include <iostream>

using namespace std;

// s1 ���ڿ����� s2 ���ڿ��� ã�Ƴ�
int findString(string s1, string s2) {
	int s1Size = s1.size();
	int s2Size = s2.size();
	for (int i = 0; i <= s1Size - s2Size; i++) {
		bool isFind = true; // �߰� ����
		for (int j = 0; j < s2Size; j++) {
			if (s1[i + j] != s2[j]) { // ��� ����ġ�ϸ�
				isFind = false;
				break;
			}	
		}
		if (isFind) {
			return i; // �߰ߵ� index ���
		}
	}
	return -1; // ����
}
int main() {
	string s1 = "yjglab";
	string s2 = "gla";
	int result = findString(s1, s2);
	if (result == -1)
		printf("�߰� ����");
	else 
		printf("%d��° index���� �߰�", result + 1);
}