#include <math.h>
#include <stdio.h>
#include <string.h>

double max(double a, double b) {
	return a > b ? a : b;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	if (n == 1) {
		puts("1");
		return 0;
	}

	int i, x[2000], y[2000];
	for (i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);

	int m = 2;
	for (i = 0; i < n; i++) {
		int ht[10000], li[2000], ln[2000], lc[2000];
		memset(ht, -1, sizeof(ht));
		int f = 0;
		
		int j;
		double dx[2000], dy[2000];
		for (j = i + 1; j < n; j++) {
			dx[j] = x[j] - x[i]; dy[j] = y[j] - y[i];

			if (dx[j] < 0 || (dx[j] == 0 && dy[j] < 0)) {
				dx[j] = -dx[j]; dy[j] = -dy[j];
			}

			double d = max(dx[j], dy[j]);
			dx[j] /= d; dy[j] /= d;

			double hd = dx[j] * 10000000 + dy[j];
			hd *= 0.6180339887;
			int h = floor(10000 * (hd - floor(hd)));

			int k;
			for (k = ht[h]; k != -1; k = ln[k]) {
				int ii = li[k];

				if (dx[ii] == dx[j] && dy[ii] == dy[j]) {
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
