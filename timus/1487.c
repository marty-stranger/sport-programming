#include <stdio.h>
#include <string.h>

#define BITS_COUNT 32
#define LOW_BITS_COUNT 5
int g[1000][1000 / BITS_COUNT + 1];

int main() {
	int n, u, v, w, m, i, k;
	int nb, lowbits, allbits, b;
	char s[1001];

	scanf("%d", &n);

	nb = n / BITS_COUNT;
	if (n % BITS_COUNT != 0)
		nb++;
	lowbits = (1 << LOW_BITS_COUNT) - 1;

	memset(g, 0, sizeof(g));
	for (u = 0; u < n; u++) {
		scanf("%s", s);
		for (v = 0; v < n; v++) 
			if (s[v] == '1')
				g[v][u >> LOW_BITS_COUNT] |= 1 << (u & lowbits);
	}

	allbits = (1LL << BITS_COUNT) - 1;
	for (w = 0; w < n; w++)
		for (u = 0; u < n; u++) {
			b = g[u][w >> LOW_BITS_COUNT] & 1 << (w & lowbits) ? allbits : 0;
			for (i = 0; i < nb; i++)
				g[u][i] |= b & g[w][i];
		}

	scanf("%d", &m);
	for (k = 0; k < m; k++) {
		scanf("%d%d", &u, &v); u--; v--;

		for (i = 0; i < nb; i++)
			if (g[u][i] & g[v][i])
				break;
		if (i != nb)
			puts("No");
		else
			puts("YES");
	}

	return 0;
}

