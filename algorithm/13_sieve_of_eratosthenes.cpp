// Algorithm Analysis
// �����佺�׳׽��� ü (Sieve of Eratosthenes)
#include <iostream>
using namespace std;

/* �Ҽ� �Ǻ� O(N^(1/2))
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

int num = 10000; // 10000���� �Ҽ� �Ǻ�
int arr[10001];

void sieveOfEratos() {
	// 2���� num���� �ʱ�ȭ
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}
	// ��� ����
	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0) continue; // �̹� ���ŵǾ����� �ǳʶ�
		for (int j = i * 2; j <= num; j += i) { // �ڱ��ڽ� �����ϰ� ����
			arr[j] = 0; // ����
		}
	}
	for (int i = 2; i <= num; i++) {
		if (arr[i] != 0) cout << arr[i] << " ";
	}
}

int main() {
	sieveOfEratos();
}