#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int i, l, r; } query;

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

typedef struct { long long s, m, a, ma; } seg;

seg ss[4*1000000];

void inc(seg *s, int a, int ma) {
	s->ma = max(s->ma, s->a + ma);
	s->a += a;

	s->m = max(s->m, s->s + ma);
	s->s += a;
}

void push(int i) {
	seg *s = &ss[i];
	inc(&ss[2*i+1], s->a, s->ma);
	inc(&ss[2*i+2], s->a, s->ma);
	s->a = s->ma = 0;
}

void update(int ll, int rr, int a, int i, int l, int r) {
	if (r < ll || rr < l)
		return;

	if (ll <= l && r <= rr) {
		inc(&ss[i], a, a);
		return;
	}

	push(i);

	int m = (l+r)/2;
	update(ll, rr, a, 2*i+1, l, m);
	update(ll, rr, a, 2*i+2, m+1, r);

	seg ls = ss[2*i+1], rs = ss[2*i+2];
	ss[i] = (seg){max(ls.s, rs.s), max(ls.m, rs.m)};
}

long long range(int ll, int rr, int i, int l, int r) {
	if (r < ll || rr < l)
		return -1e18;
	if (ll <= l && r <= rr)
		return ss[i].m;

	push(i);

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
