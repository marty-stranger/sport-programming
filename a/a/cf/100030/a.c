#include <stdbool.h>
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long k; scanf("%I64d", &k);

	if (k == 1) {
		puts("1\n1");
		return 0;
	}

	int pn = 0, p[20000];
	p[pn++] = 2;
	for (int i = 3; i <= 100000; i += 2) {
		bool f = true;
		for (int j = 0; j < pn && p[j]*p[j] <= i; j++)
			if (i % p[j] == 0) {
				f = false;
				break;
			}

		if (f) {
			p[pn++] = i;
			// printf("p = %d\n", i);
		}
	}

	int bn = 0;
	long long b[20000];
	for (int i = 0; i < pn; i++)
		if (k % p[i] == 0) {
			b[bn] = 1;
			while (k % p[i] == 0) {
				b[bn] *= p[i];
				k /= p[i];
			}
			bn++;
		}

	if (k != 1) {
		puts("No solution");
		return 0;
	}

	long long n = 0;
	for (int i = 0; i < bn; i++)
		n += b[i];

	if (n > 100000) {
		puts("No solution");
		return 0;
	}

	printf("%d\n", (int)n);
	int l = 1;
	for (int i = 0; i < bn; i++) {
		for (int j = 1; j < b[i]; j++)
			printf("%d ", l+j);
		printf("%d ", l);
		l += b[i];
	}
	putchar('\n');

	return 0;
}
