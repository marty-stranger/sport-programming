#include <stdio.h>
#include <string.h>

char a[1000][1001];
int c[1000][1000];

int s(int x, int y) {
	if (c[x][y] == -1)
		c[x][y] = a[x+1][y] != '#' && !s(x+1, y) ||
			a[x][y+1] != '#' && !s(x, y+1);

	return c[x][y];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;
	scanf("%d%d\n", &m, &n);

	int i, j;
	for (i = 0; i < m; i++)
		gets(a[i]);

	memset(c, -1, sizeof(c));
	if (!s(1, 1))
		puts("Petr");
	else
		puts("Gennady");

	return 0;
}
