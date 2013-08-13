#include <stdio.h>

typedef struct {
	long long s, l, r, m;
} value;

long long maxll(long long a, long long b) {
	return a > b ? a : b;
}

void sum(value *v, value *l, value *r) {
	v->s = l->s + r->s;
	v->l = maxll(l->l, l->s + r->l);
	v->r = maxll(r->r, r->s + l->r);
	v->m = maxll(l->r + r->l, maxll(l->m, r->m));
}

value t[4*150000];

long long a[150000];

void build(int i, int l, int r) {
	if (l == r) {
		t[i].s = a[l];
		t[i].l = t[i].r = t[i].m = maxll(a[l], 0);
	} else {
		int m = (l+r)/2;
		build(2*i+1, l, m);
		build(2*i+2, m+1, r);
		sum(&t[i], &t[2*i+1], &t[2*i+2]);
	}
}

value get(int ll, int rr, int i, int l, int r) {
	if (rr < l || r < ll) {
		value v = {0, 0, 0, 0};
		return v; 
	}
	if (ll <= l && r <= rr)
		return t[i];

	int m = (l+r)/2;

	value lv, rv, av;
	lv = get(ll, rr, 2*i+1, l, m);
	rv = get(ll, rr, 2*i+2, m+1, r);
	sum(&av, &lv, &rv);
	return av;
}

int main() {
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);

	int i, x[150000];
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	int p[150000];
	for (i = 0; i < n-1; i++)
		scanf("%d", &p[i]);

	for (i = 0; i < n-1; i++)
		a[i] = 1LL*(x[i+1]-x[i])*50 - c*p[i];

	for (i = 0; i < n-1; i++)
		printf("%d\n", a[i]);

	build(0, 0, n-2);

	long long s = 0;
	for (i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--; r--; r--;
		int res = get(l, r, 0, 0, n-2).m;
		printf("!%d\n", res);
		s += get(l, r, 0, 0, n-2).m;
	}

	printf("%.2lf\n", 1.*s / 100);
	
	return 0;
}
