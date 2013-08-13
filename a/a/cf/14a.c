#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
	int n, m; scanf("%d%d", &n, &m);

	char a[50][51];
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	int xmi = 100, ymi = 100, xma = -1, yma = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '*') {
				xmi = min(xmi, i);
				ymi = min(ymi, j);
				xma = max(xma, i);
				yma = max(yma, j);
			}

	for (int i = xmi; i <= xma; i++) {
		for (int j = ymi; j <= yma; j++)
			putchar(a[i][j]);
		putchar('\n');
	}

	return 0;
}
