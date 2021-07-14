// Algorithm Analysis
// 에라토스테네스의 체 (Sieve of Eratosthenes)
#include <iostream>
using namespace std;

/* 소수 판별 O(N^(1/2))
bool isPrime(int x) {
	int rt = (int)sqrt(x);
	for (int i = 2; i <= rt; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	int x;
	cin >> x;
	cout << boolalpha << isPrime(x);
}
*/

int num = 10000; // 10000개의 소수 판별
int arr[10001];

void sieveOfEratos() {
	// 2부터 num까지 초기화
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}
	// 배수 제거
	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0) continue; // 이미 제거되었으면 건너뜀
		for (int j = i * 2; j <= num; j += i) { // 자기자신 제외하고 제거
			arr[j] = 0; // 제거
		}
	}
	for (int i = 2; i <= num; i++) {
		if (arr[i] != 0) cout << arr[i] << " ";
	}
}

int main() {
	sieveOfEratos();
}