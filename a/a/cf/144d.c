// 140ms
#include <stdio.h>
#include <string.h>

int hn = 0, h[100000], hk[100000], d[100000];

int less(int u, int v) {
	return d[u] < d[v];
}

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
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	s--;

	int i, li = 0, lv[200000], lw[200000], ln[200000], g[100000];
	memset(g, -1, sizeof(g));
	for (i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;

		lv[li] = v; lw[li] = w; ln[li] = g[u]; g[u] = li; li++;
		lv[li] = u; lw[li] = w; ln[li] = g[v]; g[v] = li; li++;
	}

	int u, b[100000];
	for (u = 0; u < n; u++) {
		b[u] = 1; d[u] = 2000000000; insert(u);
	}
	b[s] = 0; d[s] = 0; decrease(s);

	for (i = 0; i < n-1; i++) {
		int u = extract();

		b[u] = 0;
		for (li = g[u]; li != -1; li = ln[li]) {
			int v = lv[li], w = lw[li];

			if (b[v] && d[u] + w < d[v]) {
				d[v] = d[u] + w;
				decrease(v);
			}
		}
	}

	int l;
	scanf("%d", &l);

	int c = 0;
	for (u = 0; u < n; u++) {
		if (d[u] == l)
			c++;

		for (li = g[u]; li != -1; li = ln[li]) {
			int v = lv[li], w = lw[li];
			
			if (d[u] < l && l < d[u] + w) {
				int x = l - d[u];
				if (2*x == d[v] - d[u] + w && u < v)
					c++;
				if (2*x < d[v] - d[u] + w)
					c++;
			}
		}
	}

	printf("%d\n", c);

	return 0;
}

