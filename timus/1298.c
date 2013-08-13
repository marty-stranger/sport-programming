#include <stdio.h>
#include <string.h>

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, a[8][8], x[64], y[64];

int dfs(int i, int j, int k) {
	int ii, jj, iii, jjj, l, ll, m, ml, c[8], b[8];

	x[k] = i;
	y[k] = j;

	if (k == n*n - 1)
		return 1;

	a[i][j] = k;

	for (l = 0; l < 8; l++) {
		c[l] = 0;
		ii = i + dx[l]; jj = j + dy[l];

		if (0 <= ii && ii < n && 0 <= jj && jj < n && a[ii][jj] == -1) {
			for (ll = 0; ll < 8; ll++) {
				iii = ii + dx[ll]; jjj = jj + dy[ll];
				if (0 <= iii && iii < n && 0 <= jjj && jjj < n && a[iii][jjj] == -1)
					c[l]++;
			}
		}
	}

	memset(b, 0, sizeof(b));
	for (l = 0; l < 8; l++) {
		m = 100;
		for (ll = 0; ll < 8; ll++)
			if (!b[ll] && c[ll] < m) {
				m = c[ll];
				ml = ll;
			}

		b[ml] = 1;
		ii = i + dx[ml]; jj = j + dy[ml];
		if (0 <= ii && ii < n && 0 <= jj && jj < n && a[ii][jj] == -1)
			if (dfs(ii, jj, k + 1))
				return 1;
	}

	/* for (l = 0; l < 8; l++) {
		ii = i + dx[l]; jj = j + dy[l];
		if (0 <= ii && ii < n && 0 <= jj && jj < n && a[ii][jj] == -1)
			if (dfs(ii, jj, k + 1))
				return 1;
	} */

	a[i][j] = -1;

	return 0;
}

int main() {
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = -1;
	if (dfs(0, 0, 0))
		for (i = 0; i < n*n; i++)
			printf("%c%d\n", x[i] + 'a', y[i] + 1);
	else
		puts("IMPOSSIBLE");

	return 0;
}
