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

int n;
seg ss[4*1000000];

void seg_update(seg *s, int a, int ma) {
	s->ma = max(s->ma, s->a + ma);
	s->a += a;

	s->m = max(s->m, s->s + ma);
	s->s += a;
}

void push(int i) {
	seg *s = &ss[i];
	seg_update(&ss[2*i], s->a, s->ma);
	seg_update(&ss[2*i+1], s->a, s->ma);
	s->a = s->ma = 0;
}

void clear(int i) {
	int k = 0;

	while (i>>k != 1)
		k++;

	while (k != 0) {
		push(i>>k);
		k--;
	}
}

void set(int i) {
	i /= 2;
	while (i != 0) {
		if (ss[i].a == 0 && ss[i].ma == 0) {
			seg ls = ss[2*i], rs = ss[2*i+1];
			ss[i] = (seg){max(ls.s, rs.s), max(ls.m, rs.m)};
		}
		i /= 2;
	}
}

void update(int l, int r, int a) {
	l += n; r += n;

	clear(l); clear(r);

	int i = l, j = r;
	while (i <= j) {
		if (i & 1)
			seg_update(&ss[i], a, a);
		if (!(j & 1))
			seg_update(&ss[j], a, a);

		i = (i+1)/2; j = (j-1)/2;
	}

	set(l); set(r);
}

long long range(int l, int r) {
	l += n; r += n;

	clear(l); clear(r);

	int i = l, j = r;
	long long m = -1e18;
	while (i <= j) {
		if (i & 1)
			m = max(m, ss[i].m);
		if (!(j & 1))
			m = max(m, ss[j].m);

		i = (i+1)/2; j = (j-1)/2;
	}

	return m;
}

int main() {
	scanf("%d", &n);

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
				update(ls[li]+1, j, a[j]);
				ls[li] = j;
			}
		}

		rs[q->i] = range(q->l, q->r);
	}

	for (long long *v = rs; v != rs+m; v++)
		printf("%lld\n", *v);

	return 0;
}
