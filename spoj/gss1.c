#include <stdio.h>

typedef struct value value;
struct value { int l, r, s, m; };

int n; value vs[2*50000];

int max(int a, int b) { return a > b ? a : b; }

value unite(value a, value b) {
	return (value){max(a.l, a.s+b.l), max(b.r, a.r+b.s), a.s+b.s,
		max(a.r+b.l, max(a.m, b.m))};
}

void set(int i) {
	if (i % 2)
		i ^= 1;
	vs[i/2] = unite(vs[i], vs[i^1]);
}

value one() {
	int ninf = (int)-1e9;
	return (value){ninf, ninf, 0, ninf};
}

int query(int l, int r) {
	l += n; r += n;

	value v1 = one(), v2 = one();
	while (l <= r) {
		if (l & 1) {
			v1 = unite(v1, vs[l]);
			l++;
		}

		if (!(r & 1)) {
			v2 = unite(vs[r], v2);
			r--;
		}

		l /= 2; r /= 2;
	}

	return unite(v1, v2).m;
}

int main() {
	scanf("%d", &n);

	for (value *v = vs+n; v != vs+2*n; v++) {
		int a; scanf("%d", &a);
		v->l = v->r = v->s = v->m = a;
	}

	for (int i = 2*n-1; i > 1; i -= 2)
		set(i);

	int m; scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int l, r; scanf("%d%d", &l, &r); l--; r--;
		printf("%d\n", query(l, r));
	}

	return 0;
}
