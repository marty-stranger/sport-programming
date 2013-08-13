#include <stdio.h>

int main() {
	int n, i, j, k, t, c, cc, x1[600], y1[600], x2[600], y2[600];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x1[i] > x2[i]) {
			t = x1[i]; x1[i] = x2[i]; x2[i] = t;
		}
		if (y1[i] > y2[i]) {
			t = y1[i]; y1[i] = y2[i]; y2[i] = t;
		}
	}

	c = 0;
	for (i = 0; i < n; i++) if (x1[i] == x2[i])
		for (j = i + 1; j < n; j++) if (x1[j] == x2[j]) {
			cc = 0;
			for (k = 0; k < n; k++) if (y1[k] == y2[k])
				if (y1[i] <= y1[k] && y1[k] <= y2[i] &&
					x1[k] <= x1[i] && x1[i] <= x2[k] &&
					y1[j] <= y1[k] && y1[k] <= y2[j] &&
					x1[k] <= x1[j] && x1[j] <= x2[k])
					cc++;

			c += cc * (cc-1) / 2;
		}

	printf("%d\n", c);

	return 0;
}
