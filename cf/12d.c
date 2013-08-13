#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int x, y, z; } triple;
triple ts[500000];

int less(triple a, triple b) {
	return a.x < b.x || a.x == b.x && a.y > b.y;
}

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	triple p = ts[m];

	while (i <= j)
		if (less(ts[i], p))
			i++;
		else if (less(p, ts[j]))
			j--;
		else {
			triple t = ts[i]; ts[i] = ts[j]; ts[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

int ys_n, ys[500000];

void sort_ys(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1), p = ys[m];
	while (i <= j)
		if (ys[i] < p)
			i++;
		else if (p < ys[j])
			j--;
		else {
			int t = ys[i]; ys[i] = ys[j]; ys[j] = t;
			i++; j--;
		}

	sort_ys(l, j); sort_ys(i, r);
}

struct { int n, m[500000+1]; } tree; // fenwick

int max(int a, int b) { return a > b ? a : b; }

const int inf = 1000000000;

void tree_init(int n) {
	tree.n = n;

	for (int i = 0; i < n; i++)
		tree.m[i] = -inf;
}

int tree_max(int i) {
	int m = -inf;
	while (i >= 0) {
		m = max(m, tree.m[i]);
		i = (i & i+1) - 1;
	}
	return m;
}

void tree_update(int i, int v) {
	while (i < tree.n) {
		tree.m[i] = max(tree.m[i], v);
		i = i | i+1;
	}
}

int ys_find(int y) {
	int l = 0, r = ys_n-1;
	while (l < r) {
		int m = (l+r)/2;
		if (y <= ys[m])
			r = m;
		else
			l = m+1;
	}

	return l;
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &ts[i].x);
	for (int i = 0; i < n; i++) 
		scanf("%d", &ts[i].y);
	for (int i = 0; i < n; i++)
		scanf("%d", &ts[i].z);

	sort(0, n-1);

	for (int i = 0; i < n; i++)
		ys[i] = ts[i].y;

	sort_ys(0, n-1);
	ys_n = 1;
	for (int i = 1; i < n; i++) 
		if (ys[i] != ys[i-1])
			ys[ys_n++] = ys[i];

	tree_init(ys_n+1);

	int c = 0;
	for (int i = n-1; i >= 0; i--) {
		int j = ys_n-ys_find(ts[i].y);
		int v = tree_max(j-1);
		if (v > ts[i].z)
			c++;
		tree_update(j, ts[i].z);
	}

	printf("%d\n", c);

	return 0;
}
