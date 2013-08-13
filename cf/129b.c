#include <stdbool.h>
#include <stdio.h>

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int d[100] = {0}; bool g[100][100] = {0};

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;

		g[u][v] = g[v][u] = true;
		d[u]++; d[v]++;
	}

	int c = 0;
	while (true) {
		bool b[100] = {0}, f = false;
		for (int i = 0; i < n; i++)
			if (d[i] == 1) {
				b[i] = true;
				f = true;
			}

		if (!f)
			break;

		for (int i = 0; i < n; i++)
			if (b[i]) {
				d[i]--;
				for (int j = 0; j < n; j++)
					if (g[i][j]) {
						g[i][j] = g[j][i] = false;
						d[j]--;
					}
			}

		c++;
	}

	printf("%d\n", c);

	return 0;
}
