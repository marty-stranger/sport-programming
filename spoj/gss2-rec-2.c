#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct query { int i, l, r; } query;

query qs[100000];

bool less(query a, query b) {
	return a.r < b.r;
}

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	query p = qs[m];

	while (i <= j)
		if (less(qs[i], p))
			i++;
		else if (less(p, qs[j]))
			j--;
		else {
			query t = qs[i]; qs[i] = qs[j]; qs[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

long long max(long long a, long long b) {
	return a > b ? a : b;
}

typedef struct { long long a, ma, s, m; } value;

value vs[4*1000000];

void push(int i) {
	value *l = &vs[2*i+1], *r = &vs[2*i+2];
	l->ma = max(l->ma, l->a + vs[i].ma);
	r->ma = max(r->ma, r->a + vs[i].ma);
	l->a += vs[i].a;
	r->a += vs[i].a;
	vs[i].a = vs[i].ma = 0;
}

void set(int i) {
	value l = vs[2*i+1], r = vs[2*i+2];
	vs[i].s = max(l.s + l.a, r.s + r.a);
	vs[i].m = max(max(l.m, l.s+l.ma), max(r.m, r.s+r.ma));
}

void update(int ll, int rr, int v, int i, int l, int r) {
	if (r < ll || rr < l)
		return;

	if (ll <= l && r <= rr) {
		vs[i].a += v;
		vs[i].ma = max(vs[i].ma, vs[i].a);
		return;
	}

	push(i);

	int m = (l+r)/2;
	update(ll, rr, v, 2*i+1, l, m);
	update(ll, rr, v, 2*i+2, m+1, r);

	set(i);
}

long long range(int ll, int rr, int i, int l, int r) {
	if (r < ll || rr < l)
		return -1e18;
	if (ll <= l && r <= rr)
		return max(vs[i].m, vs[i].s + vs[i].ma);

	push(i);
	set(i);

	int m = (l+r)/2;
	return max(range(ll, rr, 2*i+1, l, m),
			range(ll, rr, 2*i+2, m+1, r));
}

int main() {
	int n; scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r; scanf("%d%d", &l, &r); l--; r--;
		qs[i] = (query){i, l, r};
	}

	sort(0, m-1);

	int ls[200001]; memset(ls, -1, sizeof(ls));
	long long rs[m];
	for (query *q = qs; q != qs+m; q++) {
		if (q == qs || q->r != (q-1)->r) {
			int j = q == qs ? 0 : (q-1)->r + 1;
			for (; j <= q->r; j++) {
				int li = a[j] + 100000;
				update(ls[li]+1, j, a[j], 0, 0, n-1);
				ls[li] = j;
			}
		}

		rs[q->i] = range(q->l, q->r, 0, 0, n-1);
	}

	for (long long *v = rs; v != rs+m; v++)
		printf("%lld\n", *v);

	return 0;
}
