#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int count(int a, int p) {
	int c = 0;
	while (a != 0 && a % p == 0) {
		c++;
		a /= p;
	}

	return c;
}

typedef struct { int c, p; } result;

result rs[2][1000][1000];

void backtrace(int k, int i, int j) {
	int p = rs[k][i][j].p;
	if (p == 1) {
		backtrace(k, i, j-1);
		putchar('R');
	} else if (p == 2) {
		backtrace(k, i-1, j);
		putchar('D');
	}
}

int main() {
	int n; scanf("%d", &n);

	int zi = -1, zj = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a; scanf("%d", &a);

			rs[0][i][j].c = count(a, 2);
			rs[1][i][j].c = count(a, 5);

			if (a == 0)
				zi = i, zj = j;
		}

	for (int k = 0; k < 2; k++) {
		rs[k][0][0].p = 0;
		for (int j = 1; j < n; j++) {
			rs[k][0][j].c += rs[k][0][j-1].c;
			rs[k][0][j].p = 1;
		}

		for (int i = 1; i < n; i++) {
			rs[k][i][0].c += rs[k][i-1][0].c;
			rs[k][i][0].p = 2;

			for (int j = 1; j < n; j++)
				if (rs[k][i][j-1].c < rs[k][i-1][j].c) {
					rs[k][i][j].c += rs[k][i][j-1].c;
					rs[k][i][j].p += 1;
				} else {
					rs[k][i][j].c += rs[k][i-1][j].c;
					rs[k][i][j].p += 2;
				}
		}
	}

	int c2 = rs[0][n-1][n-1].c, c5 = rs[1][n-1][n-1].c;
	int m = min(c2, c5);
	if (m > 1 && zi != -1) {
		puts("1");
		for (int i = 0; i < zi; i++)
			putchar('D');
		for (int j = 0; j < zj; j++)
			putchar('R');
		for (int i = zi; i < n-1; i++)
			putchar('D');
		for (int j = zj; j < n-1; j++)
			putchar('R');
	} else {
		printf("%d\n", m);
		backtrace(c2 < c5 ? 0 : 1, n-1, n-1);
	}
	putchar('\n');

	return 0;
}
