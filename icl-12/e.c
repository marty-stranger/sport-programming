#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);

	int c[10001];
	c[1] = 0;
	
	int i;
	for (i = 2; i <= n; i++) {
		c[i] = 1000000000;
		int j;
		for (j = 1; j <= i; j++) {
			// NOTE can a sort of ternary search be used? the values are integers
			int cc = 0;
			if (1 < j)
				cc = max(cc, c[j-1] + a);
			if (j < i)
				cc = max(cc, c[i-j] + b);

			if (cc < c[i])
				c[i] = cc;
			printf("%d %d -> %d\n", i, j, cc);
		}
	}

	printf("%d\n", c[n]);

	return 0;
}
