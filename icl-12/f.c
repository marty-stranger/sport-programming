#include <stdio.h>
#include <string.h>

int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};

int sp[1500*1500], ss[1500*1500];

void init() {
	int i;
	for (i = 0; i < 1500*1500; i++)
		sp[i] = i, ss[i] = 1;
}

int find(int i) {
	if (sp[i] != i)
		sp[i] = find(sp[i]);
	return sp[i];
}

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

void unite(int i, int j) {
	i = find(i); j = find(j);

	if (i != j) {
		if (ss[i] < ss[j])
			swap(&ss[i], &ss[j]);
		sp[j] = i;
		ss[i] += ss[j];
	}
}

int qi[1500*1500], qj[1500*1500], d[1502][1502], c[1502][1502];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n; scanf("%d%d\n", &m, &n);

	char a[1502][1503]; memset(a, ' ', sizeof(a));
	int i;
	for (i = 1; i <= m; i++)
		gets(&a[i][1]);

	int j, qs = 0, qe = 0, x1 = 0, y1, x2, y2;
	memset(d, -1, sizeof(d));
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++) {
			if (a[i][j] == 'X') {
				int di;
				for (di = 0; di < 4; di++) {
					int ii = i + dx[di], jj = j + dy[di];
					if (a[ii][jj] == '.' || a[ii][jj] == 'L')
						break;
				}

				if (di != 4) {
					d[i][j] = 1;
					qi[qe] = i; qj[qe] = j; qe++;
				}
			}

			if (a[i][j] == 'L')
				if (x1 == 0)
					x1 = i, y1 = j;
				else
					x2 = i, y2 = j;
		}
	
	memset(c, 0, sizeof(c));
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			c[i][j] = n*(i-1) + j - 1;

	init();

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (a[i][j] == '.' || a[i][j] == 'L') {
				int di;
				for (di = 0; di < 4; di++) {
					int ii = i + dx[di], jj = j + dy[di];
					if (a[ii][jj] == '.' || a[ii][jj] == 'L')
						unite(c[i][j], c[ii][jj]);
				}
			}

	while (qs != qe) {
		int i = qi[qs], j = qj[qs]; qs++;

		a[i][j] = '.';

		int di;
		for (di = 0; di < 4; di++) {
			int ii = i + dx[di], jj = j + dy[di];
			if (a[ii][jj] == '.' || a[ii][jj] == 'L')
				unite(c[i][j], c[ii][jj]);
		}

		if (find(c[x1][y1]) == find(c[x2][y2])) {
			printf("%d\n", d[i][j]);
			return 0;
		}

		for (di = 0; di < 4; di++) {
			int ii = i + dx[di], jj = j + dy[di];
			if (a[ii][jj] == 'X' && d[ii][jj] == -1) {
				d[ii][jj] = d[i][j] + 1;
				qi[qe] = ii; qj[qe] = jj; qe++;
			}

		}
	}

	return 0;
}
