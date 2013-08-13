#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; scanf("%d%d", &n, &m);

	int c[201][201];
	memset(c, 0, sizeof(c));

	for (int j = 1; j <= m; j++)
		c[1][j] = j;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= j; k++)
				c[i][j] = (c[i][j] + c[i-1][k-1]) % (1000000000 + 7);

	printf("%d\n", c[n][m]);

	return 0;
}
