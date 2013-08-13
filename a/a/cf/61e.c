#include <stdio.h>
#include <string.h>

int a[1000000], p[1000000], b[1000000], c[1000000], c2[1000000];

void count(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		count(l, m); count(m + 1, r);

		int i = l, j = m+1, k = l;
		while (i <= m && j <= r)
			if (a[p[i]] > a[p[j]]) {
				c[p[i]] += r-j+1;
				b[k++] = p[i++];
			} else {
				b[k++] = p[j++];
			}

		while (i <= m)
			b[k++] = p[i++];
		while (j <= r)
			b[k++] = p[j++];

		for (k = l; k <= r; k++)
			p[k] = b[k];
	}
}

void count2(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		count2(l, m); count2(m + 1, r);

		int i = l, j = m+1, k = l;
		while (i <= m && j <= r)
			if (a[p[j]] < a[p[i]]) {
				c2[p[j]] += m-i+1;
				b[k++] = p[j++];
			} else {
				b[k++] = p[i++];
			}

		while (i <= m)
			b[k++] = p[i++];
		while (j <= r)
			b[k++] = p[j++];

		for (k = l; k <= r; k++)
			p[k] = b[k];
	}
}

int main() {
	int n; scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
	}

	memset(c, 0, sizeof(c));
	count(0, n-1);

/*	for (i = 0; i < n; i++)
		printf("%d ", c[i]);
	putchar('\n'); */

	memset(c2, 0, sizeof(c2));
	for (i = 0; i < n; i++)
		p[i] = i;
	count2(0, n-1);
	/* for (i = 0; i < n; i++)
		printf("%d ", c2[i]);
	putchar('\n'); */

	long long t = 0;
	for (i = 0; i < n; i++)
		t += 1LL*c[i]*c2[i];

	printf("%I64d\n", t);

	return 0;
}
