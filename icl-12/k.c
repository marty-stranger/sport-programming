#include <stdio.h>
#include <string.h>

int main() {
	int k, n, m, i, j, a[100], t[100], p[100];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(a, -1, sizeof(a));

	scanf("%d%d%d", &k, &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;

		scanf("%d%d", &x, &y);
		x--; y--;

		if (y != (a[x] + 1) % k)
			continue;

		a[x]++;
		t[x] = i;
	}

	for (i = 0; i < n; i++)
		p[i] = i;

	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (a[p[j]] > a[p[i]] || a[p[j]] == a[p[i]] && t[p[j]] < t[p[i]]) {
				int t = p[i]; p[i] = p[j]; p[j] = t;
			}

	for (i = 0; i < n; i++)
		printf("%d ", p[i]+1);
	putchar('\n');

	return 0;
}
