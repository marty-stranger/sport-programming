// ok
#include <stdio.h>

int gcd(int a, int b) {
	int t;

	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int try(int m, int n, int l, int k) {
	int mm, nn, d;

	if (l > 200)
		return 0;

	if (m == 1)
		if (n >= l && n <= 100000) {
			printf("%d\n%d", k + 1, n);
			return 1;
		}

	if (m == 0) {
		printf("%d\n", k);
		return 1;
	}

	if (m * l >= n) {
		mm = m * l - n;
		nn = n * l;

		d = gcd(mm, nn);
		if (d != 0) {
			mm /= d;
			nn /= d;
		}

		if (try(mm, nn, l + 1, k + 1)) {
			printf(" %d", l);
			return 1;
		}
	}

	if (try(m, n, l + 1, k))
		return 1;

	return 0;
}

int main() {
	int m, n;

	scanf("%d%d", &m, &n);

	try(m, n, 1, 0);

	return 0;
}
