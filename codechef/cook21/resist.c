#include <stdio.h>

int main() {
	int tn; scanf("%d", &tn);

	for (int i = 0; i < tn; i++) {
		int n, m; scanf("%d%d", &n, &m);

		long long p = 1, q = 1;
		for (int i = 2; i <= n; i++) {
			long long pp = (q+p) % m, qq = (2*q + p) % m;
			p = pp; q = qq;
		}

		printf("%d/%d\n", (int)p, (int)q);
	}

	return 0;
}
