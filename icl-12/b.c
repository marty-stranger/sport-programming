#include <stdio.h>

const int m = 1000000000 + 9;
typedef long long int64;

int bpow(int64 a, int64 p) {
	int64 b = 1;
	while (p) {
		if (p & 1)
			b = (b * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}

	return b;
}

int inv(int64 a) {
	return bpow(a, m-2);
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	int s = 0;
	if (n % 2 == 1) {
		int i;
		for (i = 0; i < n; i++)
			s = (s + bpow(2, 1LL*gcd(i, n)*((n-1)/2))) % m;
	} else {
		int i;
		for (i = 0; i < n; i++) {
			// printf("i = %d %d\n", i+1, gcd(i, n)*((n-1)/2));
			// printf("%d * %d + %d\n", gcd(i,n), (n-1)/2, gcd(i, n/2));
			s = (s + bpow(2, 1LL*gcd(i, n)*((n-1)/2) + gcd(i, n/2))) % m;
		}
	}

	printf("%d\n", (1LL*s*inv(n)) % m);

	return 0;
}
