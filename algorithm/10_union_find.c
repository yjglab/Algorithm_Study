// Algorithm Analysis
// ������ ã�� (Union-Find)

#include <stdio.h>

// ���� ���� ã��
int getSet(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getSet(set, set[x]);
}

// �� ���� ��ġ��
int unionSet(int set[], int a, int b) {
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

int main() {
	int set[7];
	for (int i = 1; i <= 6; i++) {
		set[i] = i;
	}
	// ���� 1, 2, 3 ���� | ���� 4, 5, 6 ����
	unionSet(set, 1, 2);
	unionSet(set, 2, 3);
	unionSet(set, 4, 5);
	unionSet(set, 5, 6);
	
	// ���Ἲ Ȯ��
	printf("1�� 4�� ���� ���� ���� �ִ°�? : %d\n", find(set, 1, 4)); 
	printf("���� 6�� ���� ������? : ���� %d\n", getSet(set, 6)); 
	unionSet(set, 1, 4); // ���� 1�� 4 ����
	printf("1�� 4�� ���� ���� ���� �ִ°�? : %d\n", find(set, 1, 4)); 
	printf("���� 6�� ���� ������? : ���� %d\n", getSet(set, 6));

	return 0;
}
