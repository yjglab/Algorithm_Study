// Algorithm Analysis
// 다이나믹 프로그래밍 (Dynamic Programming)

#include <stdio.h>

int i[11];
int fibonacci_dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (i[x] != 0) return i[x];
	return i[x] = fibonacci_dp(x - 1) + fibonacci_dp(x - 2);
}

int main() {
	printf("%d\n", fibonacci_dp(10));

	return 0;
}
// 55