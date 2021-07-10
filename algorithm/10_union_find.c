// Algorithm Analysis
// 합집합 찾기 (Union-Find)

#include <stdio.h>

// 속한 집합 찾기
int getSet(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getSet(set, set[x]);
}

// 두 집합 합치기
int unionSet(int set[], int a, int b) {
	a = getSet(set, a);
	b = getSet(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}

// 동일한 집합 내에 속해있는지 확인
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
	// 원소 1, 2, 3 연결 | 원소 4, 5, 6 연결
	unionSet(set, 1, 2);
	unionSet(set, 2, 3);
	unionSet(set, 4, 5);
	unionSet(set, 5, 6);
	
	// 연결성 확인
	printf("1과 4가 같은 집합 내에 있는가? : %d\n", find(set, 1, 4)); 
	printf("원소 6이 속한 집합은? : 집합 %d\n", getSet(set, 6)); 
	unionSet(set, 1, 4); // 원소 1과 4 연결
	printf("1과 4가 같은 집합 내에 있는가? : %d\n", find(set, 1, 4)); 
	printf("원소 6이 속한 집합은? : 집합 %d\n", getSet(set, 6));

	return 0;
}
