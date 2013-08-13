int main() {
	int n, i, u, v;
	char s[10];

	scanf("%d", &n);

	for (u = 0; u < n; u++)
		g[u] = -1;
	for (i = 0; i < n-1; i++) {
		scanf("%d%d%s", &u, &v, s); u--; v--;

		db[u] = s[0] == 'p';
		di[u] = i;
		ne[u] = g[v];
		g[v] = u;

		if (s[0] == 'a')
			scanf("%s", s);
	}

	k = 0;
	rec(0, 0);

	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d ", l[i] + 1);

	return 0