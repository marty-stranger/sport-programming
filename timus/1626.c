#include <math.h>
#include <stdio.h>
#include <string.h>

inline long long cm(int x1, int y1, int x2, int y2) {
	return x1*y2 - x2*y1;
}

inline long long sm(int x1, int y1, int x2, int y2) {
	return x1*x2 + y1*y2;
}

inline double ang(int x1, int y1, int x2, int y2) {
	return atan2(1.0*x1*y2 - x2*y1, 1.0*x1*x2 + y1*y2);
}

inline void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

inline int bar_inters(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x1 > x2)
		swap(&x1, &x2);
	if (y1 > y2)
		swap(&y1, &y2);
	if (x3 > x4)
		swap(&x3, &x4);
	if (y3 > y4)
		swap(&y3, &y4);

	return x3 <= x2 && x1 <= x4 && y3 <= y2 && y1 <= y4;
}

inline int inters(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	return bar_inters(x1, y1, x2, y2, x3, y3, x4, y4) &&
		cm(x2 - x1, y2 - y1, x3 - x1, y3 - y1) * cm(x2 - x1, y2 - y1, x4 - x1, y4 - y1) <= 0 &&
		cm(x4 - x3, y4 - y3, x1 - x3, y1 - y3) * cm(x4 - x3, y4 - y3, x2 - x3, y2 - y3) <= 0;
}

inline int left(int x1, int y1, int x2, int y2, int x3, int y3) {
	return cm(x2 - x1, y2 - y1, x3 - x1, y3 - y1) > 0;
}

#define bc 32
int n, nc, x[800], y[800], g[800][800], gc[800][800 / bc + 1], gtc[800][800 / bc + 1];

inline int inside(int i, int j) {
	int k = (i - 1 + n) % n;
	int l = (i + 1) % n;

	return cm(x[i] - x[k], y[i] - y[k], x[l] - x[i], y[l] - y[i]) > 0 ? left(x[k], y[k], x[i], y[i], x[j], y[j]) && left(x[i], y[i], x[l], y[l], x[j], y[j]) :
		left(x[k], y[k], x[i], y[i], x[j], y[j]) || left(x[i], y[i], x[l], y[l], x[j], y[j]);
}

int main() {
	int i, j, k, l, r, t, x1, y1, x2, y2, f, ii, jj, kk;
	double sa;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	sa = 0;
	for (i = 0; i < n; i++) {
		j = (i + 1) % n;
		k = (j + 1) % n;

		sa += ang(x[j] - x[i], y[j] - y[i], x[k] - x[j], y[k] - y[j]);
	}

	if (sa < 0) {
		l = 0; r = n - 1;
		while (l < r) {
			swap(&x[l], &x[r]);
			swap(&y[l], &y[r]);
			l++; r--;
		}
	}

	memset(g, 0, sizeof(g));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (j != i && left(x[i], y[i], x[j], y[j], x1, y1) &&
				left(x[i], y[i], x[j], y[j], x2, y2))
				if (i == (j + 1) % n || (i + 1) % n == j) {
					g[i][j] = 1;
				} else if (inside(i, j) && inside(j, i)) {
					f = 1;
					for (k = 0; k < n; k++) {
						l = (k + 1) % n;
						if (l != j && k != j && l != i && k != i && inters(x[i], y[i], x[j], y[j], x[k], y[k], x[l], y[l])) {
							f = 0;
							break;
						}
					}

					if (f)
						g[i][j] = 1;
				}

	memset(gc, 0, sizeof(gc));
	memset(gtc, 0, sizeof(gtc));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (g[i][j]) {
				gc[i][j / bc] |= 1 << (j % bc);
				gtc[j][i / bc] |= 1 << (i % bc);
			}
		}
	nc = n / bc;
	if (n % bc != 0)
		nc++;

	f = 1;
	for (i = 0; i < n && f; i++)
		for (j = 0; j < n && f; j++)
			if (g[i][j])
				for (k = 0; k < nc && f; k++)
					if ((gc[j][k] & gtc[i][k]) != 0) {
						ii = i;
						jj = j;
						for (l = 0; l < bc; l++)
							if (((1 << l) & gc[j][k] & gtc[i][k]) != 0) {
								kk = k * bc + l;
								break;
							}

						f = 0;
					}

	if (f)
		puts("Impossible");
	else {
		if (sa < 0) {
			ii = n - 1 - ii;
			jj = n - 1 - jj;
			kk = n - 1 - kk;
		}
		printf("%d %d %d", ii + 1, jj + 1, kk + 1);
	}




	return 0;
}
