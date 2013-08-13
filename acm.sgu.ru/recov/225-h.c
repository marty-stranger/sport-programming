#include <stdio.h>
#include <string.h>

int m = 0;

int ones(int a) {
	int c = 0;
	while (a != 0) {
		c += a%2;
		a /= 2;
	}

	return c;
}

int main() {
	int n; scanf("%d", &n);

	if (n == 1) {
		printf("1, 1");
		return 0; 
	}

	long long cs[1<<15][101] = {0};
	memset(c, 0, sizeof(c));

	int pn = 0, ps[1<<15][2], ps_r[1<<10][1<<10];
	for (int p1 = 0; p1 < 1 << n; p1++)
		for (int p2 = 0; p2 < 1 << n; p2++)
			if (p2 << 2 & p1 == 0 && p2 >> 2 & p1 == 0) {
				// printf("%d %d %d %d %d\n", m, p1, p2, cb(p1), cb(p2));
				cs[m][ones(p1) + ones(p2)] = 1;
				ps[m][2] = (int[2]){p1, p2};
				ps_r[p1][p2] = m;
				m++;
			}
	
	printf("m = %d\n", m);

	for (int i = 2; i < n; i++) {
		memset(c1, 0, sizeof(c1));
		for (int j = 0; j < m; j++) {
			p1 = np1[n1]; p2 = np2[n1];
			p2 = np2[n1];

			l = cb(p1);
			for (j = l; j <= (i + 2) * n; j++)
				for (p3 = 0; p3 < 1 << n; p3++)
					if (!(p2 << 2 & p3) && !(p2 >> 2 & p3) && !(p1 << 1 & p3) && !(p1 >> 1 & p3))
						c1[n1][j] += c[pn[p2][p3]][j - l];
		}
		memcpy(c, c1, sizeof(c));
	}

	for (k = 0; k <= n*n; k++) {
		int s = 0;
		for (n1 = 0; n1 < m; n1++)
			s += c[n1][k];

		printf("%lld ", s);
	}

	return 0;
}
