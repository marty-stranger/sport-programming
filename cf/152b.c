#include <stdio.h>

int main() {
	int n, m, x, y, k;
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	x--; y--;

	int ki;
	long long c = 0;
	for (ki = 0; ki < k; ki++) {
		int dx, dy;
		scanf("%d%d", &dx, &dy);

		int l = 0, r = 1000000000;
		while (l < r) {
			long long mm = (l+r+1) / 2;
			long long xx = x + mm*dx, yy = y + mm*dy;

			if (0 <= xx && xx < n && 0 <= yy && yy < m)
				l = mm;
			else
				r = mm-1;
		}
		// printf("l = %d\n", l);

		x += l*dx; y += l*dy;
		c += l;
	}

	printf("%I64d\n", c);

	return 0;
}
