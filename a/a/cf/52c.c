#include <stdio.h>

int n, a[200000], t[4*200000];
long long ta[4*200000];

long long min(long long a, long long b) {
	return a < b ? a : b;
}

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
		ta[i] = 0;
	} else {
		int m = (l+r)/2;
		build(i+i+1, l, m);
		build(i+i+2, m+1, r);
		t[i] = min(t[i+i+1], t[i+i+2]);
		ta[i] = 0;
	}
}

void update(int ll, int rr, int v) {
	void update_rec(int i, int l, int r) {
		if (r < ll || l > rr)
			return;
		if (ll <= l && r <= rr) {
			// printf("u: i = %d l = %d r = %d -> fin\n", i, l, r);
			ta[i] += v;
		} else {
			// printf("u: i = %d l = %d r = %d\n", i, l, r);
			if (ta[i] != 0) {
				ta[i+i+1] += ta[i];
				ta[i+i+2] += ta[i];
				ta[i] = 0;
			}

			int m = (l+r)/2;
			update_rec(i+i+1, l, m);
			update_rec(i+i+2, m+1, r);
			t[i] = min(t[i+i+1]+ta[i+i+1], t[i+i+2]+ta[i+i+2]);
		}
		
	}

	update_rec(0, 0, n-1);
}

long long range(int ll, int rr) {
	long long range_rec(int i, int l, int r, long long s) {
		if (r < ll || l > rr)
			return 2000000000000000000;
		else if (ll <= l && r <= rr) {
			// printf("r: i = %d l = %d r = %d -> fin\n", i, l, r);
			return s + t[i] + ta[i];
		} else {
			// printf("r: i = %d l = %d r = %d\n", i, l, r);
			/* if (ta[i] != 0) {
				ta[i+i+1] += ta[i];
				ta[i+i+2] += ta[i];
				ta[i] = 0;
			} */

			s += ta[i];
			int m = (l+r) / 2;
			return min(range_rec(i+i+1, l, m, s),
					range_rec(i+i+2, m+1, r, s));
		}
	}

	return range_rec(0, 0, n-1, 0);
}

int main() {
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	build(0, 0, n-1);

	int m; scanf("%d\n", &m);
	for (i = 0; i < m; i++) {
		char s[1000];
		gets(s);
		// puts(s);

		int l, r, v;
		if (sscanf(s, "%d%d%d", &l, &r, &v) == 3)
			if (l <= r)
				update(l, r, v);
			else {
				update(l, n-1, v);
				update(0, r, v);
			}
		else
			if (l <= r)
				printf("%I64d\n", range(l, r));
			else
				printf("%I64d\n", min(range(l, n-1), range(0, r)));
		// puts("");
	}

	return 0;
}
