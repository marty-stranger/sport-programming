#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char as[5000][5001];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	int hs[5000];

	for (int i = 0; i < n; i++) {
		scanf("%s", as[i]);

		hs[i] = 0;
		int p = 31;
		for (int j = 0; j < m; j++) {
			hs[i] += (as[i][j] - '0') * p;
			p *= 31;
		}
	}

	int mi = -1;
	int min = -1;
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < m; j++)
			c += (as[i][j] == '1');

		if (!(8 <= c && c <= 15))
			continue;

		c = 0;
		for (int j = 0; j < n; j++)
			if (hs[i] != hs[j] || strcmp(as[i], as[j]) != 0)
				c++;

		// printf("i = %d c = %d\n", i, c);

		if (mi == -1 || c < min) {
			mi = i;
			min = c;
		}
	}

	if (mi == -1) {
		for (int i = 0; i < 8; i++)
			putchar('1');
		for (int i = 8; i < m; i++)
			putchar('0');

		return 0;
	}

	puts(as[mi]);

	return 0;
} 
