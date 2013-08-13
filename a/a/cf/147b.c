#include <stdio.h>
#include <string.h>

int n;

int max(int a, int b) {
	return a > b ? a : b;
}

void one(int a[300][300]) {
	int u, v;

	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++)
			a[u][v] = u == v ? 0 : -1000000000;
}

int mul(int a[300][300], int b[300][300], int c[300][300]) {
	int u, v, w;

	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++) {
			a[u][v] = -1000000000;
			for (w = 0; w < n; w++)
				a[u][v] = max(a[u][v], b[u][w] + c[w][v]);
		}
}

int main() {
	int m;
	scanf("%d%d", &n, &m);

	int i, u, v, a[300][300];

	one(a);

	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		u--; v--;
		scanf("%d%d", &a[u][v], &a[v][u]);
	}

	int b[10][300][300];

	one(b[0]);
	memcpy(b[1], a, sizeof(a));
	for (i = 2; i <= 9; i++)
		mul(b[i], b[i-1], b[i-1]);

	int c[300][300];
	one(c);

	int r = 0;
	for (i = 9; i >= 1; i--) {
		int d[300][300];
		mul(d, c, b[i]);

		for (u = 0; u < n; u++)
			if (d[u][u] > 0)
				break;

		if (u == n) {
			memcpy(c, d, sizeof(c));
			r |= 1 << (i - 1);
		}
	}
	
	if (r + 1 <= n)
		printf("%d\n", r + 1);
	else
		puts("0");
	
	return 0;
}
