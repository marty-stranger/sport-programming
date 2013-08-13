#include <stdio.h>
#include <string.h>

int n;
long long c[11][30000][101];
int pn[1<<10][1<<10];
int np1[30000];
int np2[30000];

int m = 0;

int cb(int a) {
	int c = 0;
	while (a != 0) {
		c += a%2;
		a /= 2;
	}

	return c;
}

long long count(int i, int j, int k) {
	if (c[i][j][k] != -1)
		return c[i][j][k];

	if (i == 2)
		return 0;

	int p1 = np1[j], p2 = np2[j];

	int l = cb(p1);

	long long s = 0;
	if (k >= l)
		for (int p3 = 0; p3 < 1<<n; p3++)
			if (!(p2 << 2 & p3) && !(p2 >> 2 & p3) && !(p1 << 1 & p3) && !(p1 >> 1 & p3))
				s += count(i-1, pn[p2][p3], k-l);
	return c[i][j][k] = s;
}

int main() {
	int k;
	scanf("%d%d", &n, &k); 

	memset(c, -1, sizeof(c));

	m = 0;
	for (int p1 = 0; p1 < 1<<n; p1++)
		for (int p2 = 0; p2 < 1<<n; p2++)
			if (!(p2 << 2 & p1) && !(p2 >> 2 & p1)) {
				// printf("%d %d %d %d %d\n", m, p1, p2, cb(p1), cb(p2));
				c[2][m][cb(p1) + cb(p2)] = 1;
				pn[p1][p2] = m;
				np1[m] = p1;
				np2[m] = p2;
				m++;
			}
	
	// printf("m = %d\n", m);

	long long s = 0;
	for (int i = 0; i < m; i++)
		s += count(n, i, k);
	printf("%lld\n", s);

	return 0;
}
