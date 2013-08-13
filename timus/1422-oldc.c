#include <math.h>
#include <stdio.h>
#include <string.h>

double max(double a, double b) {
	return a > b ? a : b;
}

int main() {
	int n, m, i, j, f, h, ii, k, x[2000], y[2000], z[2000], ht[10000], li[2000], ln[2000], lc[2000];
	double d, hd, dx[2000], dy[2000], dz[2000];

	scanf("%d", &n);

	if (n == 1) {
		puts("1");
		return 0;
	}

	for (i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &z[i]);

	m = 2;
	for (i = 0; i < n; i++) {
		memset(ht, -1, sizeof(ht)); f = 0;
		
		for (j = i + 1; j < n; j++) {
			dx[j] = x[j] - x[i]; dy[j] = y[j] - y[i]; dz[j] = z[j] - z[i];

			if (dx[j] < 0 || (dx[j] == 0 && dy[j] < 0) || (dx[j] == 0 && dy[j] == 0 && dz[j] < 0)) {
				dx[j] = -dx[j]; dy[j] = -dy[j]; dz[j] = -dz[j];
			}

			d = max(dx[j], max(dy[j], dz[j]));
			dx[j] /= d; dy[j] /= d; dz[j] /= d;

			hd = (dx[j] * 10000000 + dy[j]) * 10000000 + dz[j];
			hd *= 0.6180339887;
			h = floor(10000 * (hd - floor(hd)));

			hd = (dx[j] * 10000000 + dy[j]) * 10000000 + dz[j];
			hd *= 0.6180339887;
			h = floor(10000 * (hd - floor(hd)));

			for (k = ht[h]; k != -1; k = ln[k]) {
				ii = li[k];

				if (dx[ii] == dx[j] && dy[ii] == dy[j] && dz[ii] == dz[j]) {
					lc[k]++;
					if (lc[k] + 1 > m)
						m = lc[k] + 1;
					break;
				}
			}

			if (k == -1) {
				li[f] = j; lc[f] = 1; ln[f] = ht[h]; ht[h] = f; f++;
			}
		}
	}

	printf("%d\n", m);

	return 0;
}
