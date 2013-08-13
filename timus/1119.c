#ifndef __cplusplus
#define _XOPEN_SOURCE 600
#include <stdbool.h>
#else
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
int round(double a) {
	return (a >= 0) ? (int)(a + 0.5) : (int)(a - 0.5);
}
#endif

double min(double a, double b) { return a < b ? a : b; }

int main() {
	int m, n; scanf("%d%d", &m, &n);

	static bool b[1000][1000] = {0};
	int k; scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		b[x][y] = true;
	}

	float d[1001], dd[1001];
	d[0] = 0;
	for (int y = 1; y <= n; y++)
		d[y] = y*100;
	
	for (int x = 1; x <= m; x++) {
		dd[0] = x*100;

		for (int y = 1; y <= n; y++) {
			dd[y] = min(d[y], dd[y-1]) + 100;
			if (b[x-1][y-1])
				dd[y] = min(dd[y], d[y-1] + 100*M_SQRT2);
		}

		memcpy(d, dd, sizeof(d));
	}

	printf("%d\n", (int) round(d[n]));

	return 0;
}
