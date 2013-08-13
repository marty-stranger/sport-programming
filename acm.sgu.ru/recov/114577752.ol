int main() {
	int n, m, k, i, j;
	long long s;

	scanf("%d%d%d", &n, &m, &k);

	for (i = 0; i < 1 << m; i++) {
		s = 0; j = i;
		while (j != 0) {
			s += j % 2;
			j /= 2;
		}
		c[m][i] = s >= k;
	}

	for (i = m+1; i <= n; i++)
		for (j = 0; j < 1 << m; j++)
			if (!c[m][j])
				c[i][j] = 0;
			else
				c[i][j] = c[i - 1][j >> 1] + c[i - 1][(j >> 1) + (1 << m - 1)];

	s = 0;
	for (i = 0; i < 1 << m; i++)
		s += c[n][i];
		
	printf("%lld", s);

	return 0