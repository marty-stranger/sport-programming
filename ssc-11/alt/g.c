#include <stdio.h>

const int inf = 1000000000;

int m, n, l, a[15][15], ai[15][15], ix[15], iy[15], c[15][15][1 << 15];

int kdx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int kdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bdx[4] = {1, -1, -1, 1};
int bdy[4] = {1, 1, -1, -1};

int rdx[4] = {1, 0, -1, 0};
int rdy[4] = {0, 1, 0, -1};

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int check(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

int count(int kx, int ky, int mask) {
	int x, y, i, j, xx, yy, b[15][15], qs, qe, qx[225], qy[225], mm, cc;

	if (mask == 0)
		return 0;

	if (c[kx][ky][mask] != -1)
		return c[kx][ky][mask];

	for (x = 0; x < m; x++)
		for (y = 0; y < n; y++)
			b[x][y] = -1;

	for (j = 0; j < l; j++)
		if (mask & (1 << j)) {
			x = ix[j]; y = iy[j];
			if (a[x][y] == 'K')
				for (i = 0; i < 8; i++) {
					xx = x + kdx[i]; yy = y + kdy[i];
					if (check(xx, yy))
						b[xx][yy] = inf;
				}
			else if (a[x][y] == 'B')
				for (i = 0; i < 4; i++) {
					xx = x + bdx[i]; yy = y + bdy[i];
					while (check(xx, yy) && (a[xx][yy] == '.' || !(mask & (1 << ai[xx][yy])))) {
						b[xx][yy] = inf;
						xx += bdx[i]; yy += bdy[i];
					}

					if (check(xx, yy) && a[xx][yy] != '.' && (mask & (1 << ai[xx][yy])))
						b[xx][yy] = inf;
				}
			else if (a[x][y] == 'R')
				for (i = 0; i < 4; i++) {
					xx = x + rdx[i]; yy = y + rdy[i];
					while (check(xx, yy) && (a[xx][yy] == '.' || !(mask & (1 << ai[xx][yy])))) {
						b[xx][yy] = inf;
						xx += rdx[i]; yy += rdy[i];
					}

					if (check(xx, yy) && a[xx][yy] != '.' && (mask & (1 << ai[xx][yy])))
						b[xx][yy] = inf;
				}
		}

	qs = qe = 0;
	qx[qe] = kx; qy[qe] = ky; qe++;
	b[kx][ky] = 0;
	
	mm = inf;
	while (qs != qe) {
		x = qx[qs]; y = qy[qs]; qs++;

		for (i = 0; i < 8; i++) {
			xx = x + dx[i]; yy = y + dy[i];
			if (check(xx, yy) && b[xx][yy] == -1) {
				j = ai[xx][yy];
				if ((a[xx][yy] == 'K' || a[xx][yy] == 'B' || a[xx][yy] == 'R') &&
						(mask & (1 << j))) {
					cc = b[x][y] + 1 + count(xx, yy, mask & ~(1 << j));
					if (cc < mm)
						mm = cc;
				} else {
					b[xx][yy] = b[x][y] + 1;
					qx[qe] = xx; qy[qe] = yy; qe++;
				}
			}
		}
	}

	c[kx][ky][mask] = mm;
	return mm;
}

int main() {
	int x, y, kx, ky, mask, cc;
	char ch;

	l = 0;
	scanf("%d%d", &m, &n);
	scanf("%c", &ch);
	for (x = 0; x < m; x++) {
		for (y = 0; y < n; y++) {
			scanf("%c", &a[x][y]);

			if (a[x][y] == '*') {
				kx = x; ky = y;
			} else if (a[x][y] != '.') {
				ai[x][y] = l;
				ix[l] = x; iy[l] = y; l++;
			}

		}
		scanf("%c", &ch);
	}

	for (x = 0; x < m; x++)
		for (y = 0; y < n; y++)
			for (mask = 0; mask < (1 << l); mask++)
				c[x][y][mask] = -1;

	cc = count(kx, ky, (1 << l) - 1);
	if (cc == inf)
		printf("-1\n");
	else
		printf("%d\n", cc);

	return 0;
}
