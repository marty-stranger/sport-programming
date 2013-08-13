#include <stdio.h>
#include <string.h>

int n, k, a[5000];
char g[5000][5000];

void dfs(int i) {
	int j;

	a[i] = k;

	for (j = 0; j < n; j++)
		if (g[i][j] && a[j] == -1)
			dfs(j);
}

int main() {
	int i, b[5000], c[5000];
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	memset(g, 0, sizeof(g));
	for (i = 1; i < n; i++) {
		int j;
		scanf("%d", &b[i]);

		if (b[i] > n-i) {
			puts("-1");
			return 0;
		}

		for (j = 0; j < b[i]; j++)
			g[i+j][j] = g[j][i+j] = 1;
	}


	/* for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j < n; j++)
			printf("%d", g[i][j]);
		putchar('\n');
	} */

	k = 0;
	memset(a, -1, sizeof(a));
	for (i = 0; i < n; i++)
		if (a[i] == -1) {
			dfs(i);
			k++;
		}

	for (i = 1; i < n; i++) {
		int j;

		for (j = 0; j < n; j++)
			if (a[i+j] != a[j])
				break;

		c[i] = j;
	}

	for (i = 1; i < n; i++)
		if (c[i] != b[i]) {
			puts("-1");
			return 0;
		}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]+1);
	putchar('\n');

	return 0;
}
