#include <stdio.h>

int int_ceil(int a, int b) {
	int c = a/b;
	if (a % b != 0)
		c++;
	return c;
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

typedef struct { int c, m; } result;

int main() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);

	int h[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]); h[i]++;
	}

	result rs[20][17][17][17];
	const int inf = 1000000000;
	for (int h1 = 0; h1 <= h[0]; h1++)
		for (int h2 = 0; h2 <= h[1]; h2++)
			for (int h3 = 0; h3 <= h[2]; h3++) {
				int c = max(int_ceil(h1, b), max(int_ceil(h2, a), int_ceil(h3, b)));
				rs[1][h1][h2][h3] = (result){c, c};
			}

	for (int i = 2; i < n-1; i++)
		for (int h1 = 0; h1 <= h[i-1]; h1++)
			for (int h2 = 0; h2 <= h[i]; h2++)
				for (int h3 = 0; h3 <= h[i+1]; h3++) {
					int c = int_ceil(h3, b);
					int ch1 = max(0, h1 - b*c),
					    ch2 = max(0, h2 - a*c);

					int mc = c, m = c + rs[i-1][h[i-2]][ch1][ch2].m;
					while (ch1 > 0 || ch2 > 0) {
						ch1 = max(0, ch1-b); ch2 = max(0, ch2-a); c++;

						int cc = c + rs[i-1][h[i-2]][ch1][ch2].m;
						if (cc < m)
							mc = c, m = cc;
					}
					rs[i][h1][h2][h3] = (result){mc, m};
					// fprintf(stderr, "%d %d %d %d -> %d\n", i, j, k, l, m);
				}

	int h1 = h[n-3], h2 = h[n-2], h3 = h[n-1];
	printf("%d\n", rs[n-2][h1][h2][h3].m);
	for (int i = n-2; i >= 1; i--) {
		int c = rs[i][h1][h2][h3].c;
		fprintf(stderr, "i = %d c = %d h = %d %d %d\n", i, c, h1, h2, h3);

		if (i >= 2) {
			h3 = max(0, h2 - c*a);
			h2 = max(0, h1 - c*b);
			h1 = h[i-2];
		}

		while (c > 0) {
			printf("%d ", i+1);
			c--;
		}
	}
	putchar('\n');
 
	return 0;
}
