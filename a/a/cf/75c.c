#include <stdio.h>

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main() {
	int a, b; scanf("%d%d", &a, &b);

	int c = gcd(a, b);

	int i, dn = 0, d[10000];
	for (i = 1; i*i <= c; i++)
		if (c % i == 0) {
			d[dn++] = i;
			d[dn++] = c/i;
		}

	int n; scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int l, r; scanf("%d%d", &l, &r);

		int j, dd = -1;
		for (j = 0; j < dn; j++)
			if (l <= d[j] && d[j] <= r)
				if (dd == -1 || d[j] > dd)
					dd = d[j];

		printf("%d\n", dd);
	}

	return 0;
}
