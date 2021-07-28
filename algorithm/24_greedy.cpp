// Algorithm Analysis
// 그리디 알고리즘 (Greedy Algorithm)

#include <iostream>
using namespace std;

int main() {
	int n, result = 0;
	cin >> n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	n %= 10;

	cout << result;
}