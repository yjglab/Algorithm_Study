#include <stdio.h>

long long int arr[1000001][2];
long long int dp(int x) {
	arr[0][0] = 1;
	arr[1][0] = 2;
	arr[2][0] = 7;
	arr[2][1] = 0;

	for (int i = 3; i <= x; i++) {
		arr[i][1] = (arr[i - 1][1] + arr[i - 3][0]) % 1000000007;
		arr[i][0] = (2 * arr[i - 1][0] + 3 * arr[i - 2][0] + 2 * arr[i][1]) % 1000000007;
	}
	return arr[x][0];
}

int main() {
	int x = 0;
	scanf_s("%d", &x);
	printf("%lld\n", dp(x));

	return 0;
}
// d[n] = 2 * d[n - 1] + 3 * d[n - 2] + 2 * d[n - x] ¡Ø x >= 3, (n - x) >= 0