#include <iostream>
#include <fstream>
using namespace std;

const int m = 1000000000 + 9;

int bin_pow(long long a, long long p) {
	long long b = 1;
	while (p) {
		if (p & 1)
			b = (b * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}

	return b;
}

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main() {
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int n; cin >> n;

	int s = 0;
	if (n % 2 == 0)
		for (int i = 0; i < n; i++)
			s = (s + bin_pow(2, 1LL*gcd(i, n)*((n-1)/2) + gcd(i, n/2))) % m;
	else
		for (int i = 0; i < n; i++)
			s = (s + bin_pow(2, 1LL*gcd(i, n)*((n-1)/2))) % m;

	cout << 1LL*s*bin_pow(n, m-2) % m;

	return 0;
}
