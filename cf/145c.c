#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000000007

int a[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, p = a[l + rand() % (r - l)];
		while (i <= j)
			if (a[i] < p)
				i++;
			else if (a[j] > p)
				j--;
			else {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int inv(long long a) {
	int p = M - 2;
	long long b = 1;
	while (p) {
		if (p & 1)
			b = (b * a) % M;
		a = (a * a) % M;
		p >>= 1;
	}

	return b;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n - 1);

	int m = 0, b[1 << 10], l = 0;
	i = 0;
	while (i < n) {
		int t = a[i];
		while (t != 0)
			if (t % 10 == 4 || t % 10 == 7)
				t /= 10;
			else
				break;

		i++;
		if (t == 0) {
			b[m] = 1;
			while (i < n && a[i] == a[i-1]) {
				i++;
				b[m]++;
			}
			m++;
		} else
			l++;
	}

	long long c[1 << 10], cc[1 << 10];
	memset(c, 0, sizeof(c));
	c[0] = 1;

	for (i = 0; i < m; i++) {
		cc[0] = c[0];
		int j;
		for (j = 1; j <= m && j <= k; j++)
			cc[j] = (c[j] + (c[j-1] * b[i]) % M) % M;
		memcpy(c, cc, sizeof(c));
	}

	i = m;
	while (k - i < 0)
		i--;

	long long s = 0, p = 1;
	int j;
	for (j = 1; j <= k - i && j <= l; j++) {
		p = (p * (l - j + 1)) % M;
		p = (p * inv(j)) % M;
	}

	while (i >= 0 && k - i <= l) {
		s = (s + (c[i] * p) % M) % M;

		i--;
		int j = k - i;
		p = (p * (l - j + 1)) % M;
		p = (p * inv(j)) % M;
	}

	printf("%d", s);
	
	return 0;
}
