#include <stdio.h>

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int l = 1, r = n;

	while (l < r) {
		int m = (l+r)/2;

		int a = m, s = 0;
		while (a != 0) {
			s += a;
			a /= k;
		}
		// printf("l = %d r = %d s = %d\n", l, r, s);

		if (s >= n)
			r = m;
		else
			l = m+1;
	}

	printf("%d\n", l);

	return 0;
}
