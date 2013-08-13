#include <stdio.h>
#include <string.h>

int n, sp[1000], ss[1000];

void init() {
	int i;
	for (i = 0; i < n; i++)
		sp[i] = i, ss[i] = 1;
}

int find(int i) {
	if (sp[i] != i)
		sp[i] = find(sp[i]);
	return sp[i];
}

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

int ds_union(int i, int j) {
	i = find(i); j = find(j);

	if (i != j) {
		if (ss[i] < ss[j])
			swap(&ss[i], &ss[j]);
		sp[j] = i;
		ss[i] += ss[j];
	}

	return i != j;
}

int main() {
	int m;
	scanf("%d%d", &n, &m);

	if (n % 2 == 0) {
		puts("-1");
		return 0;
	}

	init();

	int cc = n, i, e1n = 0, e2n = 0, e1u[100000], e1v[100000], e1i[100000],
		e2u[100000], e2v[100000], e2i[100000];
	for (i = 0; i < m; i++) {
		int u, v;
		char c;
		scanf("%d%d %c", &u, &v, &c);
		u--; v--;

		if (u == v)
			continue;

		if (c == 'M') {
			if (ds_union(u, v))
				cc--;
			e1u[e1n] = u, e1v[e1n] = v, e1i[e1n] = i, e1n++;
		} else
			e2u[e2n] = u, e2v[e2n] = v, e2i[e2n] = i, e2n++;
	}

	if (cc-1 > (n-1)/2) {
		puts("-1");
		return 0;
	}

	int en = 0, e[1000];
	for (i = 0; i < e2n && en < cc-1; i++)
		if (ds_union(e2u[i], e2v[i]))
			e[en++] = i;

	if (en != cc-1) {
		puts("-1");
		return 0;
	}

	init();

	for (i = 0; i < en; i++) {
		int j = e[i];
		if (ds_union(e2u[j], e2v[j]))
			e[i] = e2i[j];
	}

	for (i = 0; i < e2n && en < (n-1)/2; i++)
		if (ds_union(e2u[i], e2v[i]))
			e[en++] = e2i[i];

	if (en != (n-1)/2) {
		puts("-1");
		return 0;
	}

	for (i = 0; i < e1n && en < n-1; i++)
		if (ds_union(e1u[i], e1v[i]))
			e[en++] = e1i[i];

	if (en != n-1) {
		puts("-1");
		return 0;
	}

	printf("%d\n", n - 1);
	for (i = 0; i < n - 1; i++)
		printf("%d ", e[i] + 1);

	return 0;
}
