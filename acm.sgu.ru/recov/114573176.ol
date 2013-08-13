int main() {
	int n, k, p1, p2, p3, i, n1, l, j;
	long long cc;

	scanf("%d", &n);

	if (n == 1) {
		printf("1, 1");
		return;
	}

	memset(c, 0, sizeof(c));

	m = 0;
	for (p1 = 0; p1 < 1 << n; p1++)
		for (p2 = 0; p2 < 1 << n; p2++)
			if (!(p2 << 2 & p1) && !(p2 >> 2 & p1)) {
				c[m][cb(p1) + cb(p2)] = 1;
				pn[p1][p2] = m;
				np1[m] = p1;
				np2[m] = p2;
				m++;
			}
	
	/* printf("m = %d\n", m); */

	for (i = 1; i < n - 1; i++) {
		memset(c1, 0, sizeof(c1));
		for (n1 = 0; n1 < m; n1++) {
			p1 = np1[n1];
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
		cc = 0;
		for (n1 = 0; n1 < m; n1++)
			cc += c[n1][k];

		if (k != 0)
			printf(", ");
		printf("%lldLL", cc);

		/* printf("k = %d cc = %lld\n", k, cc); */
	}

	return 0