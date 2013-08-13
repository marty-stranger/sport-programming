#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GM 2*100000 + 2

int ux[GM], p[GM];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, pp = p[l + rand() % (r - l)];
		while (i <= j)
			if (ux[p[i]] < ux[pp])
				i++;
			else if (ux[pp] < ux[p[j]])
				j--;
			else {
				int t = p[i]; p[i] = p[j]; p[j] = t;
				i++; j--;
			}
		
		sort(i, r); sort(l, j);
	}
}

int hn, h[GM], hk[GM], d[GM];

void down(int i) {
	int k = h[i], j = 2*i + 1;
	while (j < hn) {
		if (j + 1 < hn && less(h[j+1], h[j]))
			j++;

		if (!less(h[j], k))
			break;

		int l = h[j];
		h[i] = l; hk[l] = i;
		i = j; j = 2*i + 1;
	}

	h[i] = k; hk[k] = i;
}

int less(int u, int v) {
	return d[u] < d[v];
}

void up(int i) {
	int k = h[i], j = (i-1)/2;
	while (i != 0 && less(k, h[j])) {
		int l = h[j];
		h[i] = l; hk[l] = i;
		i = j; j = (i-1)/2;
	}

	h[i] = k; hk[k] = i;
}

void insert(int k) {
	h[hn] = k; hk[k] = hn; hn++;
	up(hn - 1);
}

int extract() {
	int k = h[0];
	h[0] = h[hn - 1]; hk[h[0]] = 0; hn--;
	down(0);
	return k;
}

void decrease(int k) {
	up(hk[k]);
}

int main() {
	int n, l;
	scanf("%d%d", &n, &l);

	int i, gn = 0, gu[GM][3], gw[GM][3], gwi[GM];

	memset(gu, -1, sizeof(gu));

	ux[gn] = 0; gn++;

	for (i = 0; i < n; i++) {
		int x, d, t, p;
		scanf("%d%d%d%d", &x, &d, &t, &p);

		if (x - p < 0 || t >= d)
			continue;

		int u = gn; gn++; ux[u] = x - p;
		int v = gn; gn++; ux[v] = x + d;
		gu[u][2] = v; gw[u][2] = p + t; gwi[u] = i;
	}

	ux[gn] = l; gn++;

	for (i = 0; i < gn; i++)
		p[i] = i;
	sort(0, gn - 1);

	for (i = 0; i < gn; i++) {
		if (i != 0) {
			int u = p[i - 1], v = p[i];
			gu[u][0] = v; gw[u][0] = ux[v] - ux[u];
			gu[v][1] = u; gw[v][1] = ux[v] - ux[u];
		}

		if (i != gn - 1) {
			int u = p[i], v = p[i + 1];
			gu[u][0] = v; gw[u][0] = ux[v] - ux[u];
			gu[v][1] = u; gw[v][1] = ux[v] - ux[u];
		}

	}

	const int inf = 2000000000;
	int u, b[GM], dp[GM];
	memset(dp, -1, sizeof(dp));

	b[0] = 0; d[0] = 0; insert(0);
	for (u = 1; u < gn; u++) {
		b[u] = 1; d[u] = inf; insert(u);
	}

	for (i = 0; i < gn; i++) {
		int u = extract();

		b[u] = 0;
		int j;
		for (j = 0; j < 3; j++) {
			int v = gu[u][j];
			if (v != -1 && b[v] && d[u] + gw[u][j] < d[v]) {
				d[v] = d[u] + gw[u][j]; dp[v] = u;
				decrease(v);
			}
		}
	}

	printf("%d\n", d[gn-1]);

	u = gn-1;
	int pln = 0, pl[GM];
	while (dp[u] != -1) {
		int v = dp[u];
		if (gu[v][2] == u)
			pl[pln] = gwi[v], pln++;
		u = v;
	}

	printf("%d\n", pln);
	for (i = pln - 1; i >= 0; i--)
		printf("%d ", pl[i]+1);
	putchar('\n');

	return 0;
}
