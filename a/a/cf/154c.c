#include <stdio.h>
#include <stdlib.h>

long long h[1000000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand() % (r-l+1);
	long long p = h[m];

	while (i <= j)
		if (h[i] < p)
			i++;
		else if (p < h[j])
			j--;
		else {
			long long t = h[i]; h[i] = h[j]; h[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

typedef struct { int u, v; } edge;

int main() {
	int n, m; scanf("%d%d", &n, &m);

	long long p[n];
	p[0] = 1;
	for (int i = 1; i < n; i++)
		p[i] = p[i-1] * 97;

	edge es[m];
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;

		h[u] += p[v];
		h[v] += p[u];
		es[i] = (edge){u, v};
	}

	long long c = 0;
	for (int i = 0; i < m; i++) {
		int u = es[i].u, v = es[i].v;
		if (h[u]-p[v] == h[v]-p[u])
			c++;
	}

	sort(0, n-1);

	int i = 0;
	while (i < n) {
		int j = i+1;
		while (j < n && h[j] == h[i])
			j++;

		c += 1ll*(j-i)*(j-i-1)/2;
		i = j;
	}

	printf("%I64d\n", c);

	return 0;
}
