#include <stdio.h>

typedef struct { int min, max; } value;
value t[4*100000];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

value join(value a, value b) {
	return (value){min(a.min, b.min), max(a.max, b.max)};
}

void build(int a[], int i, int l, int r) {
	if (l == r)
		t[i] = (value){a[l], a[l]};
	else {
		int m = (l+r)/2;
		build(a, 2*i+1, l, m);
		build(a, 2*i+2, m+1, r);
		t[i] = join(t[2*i+1], t[2*i+2]);
	}
}

value get(int l, int r, int i, int ll, int rr) {
	if (r < ll || l > rr)
		return (value){(int)1e9, 0};
	else if (l <= ll && rr <= r)
		return t[i];
	else {
		int m = (ll+rr)/2;
		value a = get(l, r, 2*i+1, ll, m),
			b = get(l, r, 2*i+2, m+1, rr);
		return join(a, b);
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	build(a, 0, 0, n-1);

	int i = 0, j = 0, m = 1;
	while (i < n) {
		// printf("i = %d\n", i);
		while (j+1 < n) {
			// fprintf(stderr, "j = %d\n", j);
			value v = get(i, j+1, 0, 0, n-1);
			// fprintf(stderr, "mi = %d ma = %d\n", v.min, v.max);
			if (v.max - v.min > k)
				break;
			j++;
		}

		if (j-i+1 > m)
			m = j-i+1;
		i++;
	}

	int c = 0 ;
	for (int i = 0; i+m-1 < n; i++) {
		value v = get(i, i+m-1, 0, 0, n-1);
		if (v.max - v.min <= k)
			c++;
	}
	
	printf("%d %d\n", m, c);
	for (int i = 0; i+m-1 < n; i++) {
		value v = get(i, i+m-1, 0, 0, n-1);
		if (v.max - v.min <= k)
			printf("%d %d\n", i+1, i+m);
	}

	return 0;
}
