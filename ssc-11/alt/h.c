#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long gcd(long long a, long long b) {
	long long t;

	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int ln;
long long a[10000];

void sort(int l, int r) {
	int i, j;
	long long p, t;

	if (l >= r)
		return;

	i = l; j = r; p = a[(l + r) / 2];
	while (i <= j)
		if (a[i] < p)
			i++;
		else if (a[j] > p)
			j--;
		else {
			t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

int main() {
	int n, m, i, ri, si, sj, r, b[10], li, fn, d, fi, ln, nln, qi;
	char s[15], t[15];
	long long sa, sgcd, f[1000], fq[1000];

	srand(time(NULL));

	scanf("%d\n", &n);

	for (i = 0; i < n; i++) {
		gets(s); m = strlen(s);

		sgcd = -1;

		for (ri = 0; ri < 50; ri++) {
			memset(b, 0, sizeof(b));

			memset(t, -1, sizeof(t));

			r = rand() % 9 + 1;
			for (si = 0; si < m; si++)
				if (s[si] == s[0])
					t[si] = '0' + r;
			b[r] = 1;

			for (si = 1; si < m; si++)
				if (t[si] == -1) {
					r = rand() % 10;
					while (b[r])
						r = rand() % 10;

					b[r] = 1;

					for (sj = 0; sj < m; sj++)
						if (s[sj] == s[si])
							t[sj] = '0' + r;
				}

			t[m] = '\0';
			// puts(t);

			sa = atoll(t);

			if (sgcd == -1)
				sgcd = sa;
			else
				sgcd = gcd(sgcd, sa);
		}

		printf("Case %d:", i + 1);

		fn = 0;
		for (d = 3; d*d <= sgcd; d++)
			if (sgcd % d == 0) {
				f[fn] = d;
				fq[fn] = 0;
				while (sgcd % d == 0) {
					fq[fn]++;
					sgcd /= d;
				}
				fn++;
			}

		if (sgcd != 1) {
			f[fn] = sgcd;
			fq[fn] = 1;
			fn++;
		}

		ln = 0;
		a[ln++] = 1;

		for (fi = 0; fi < fn; fi++) {
			d = 1;
			nln = ln;
			for (qi = 0; qi < fq[fi]; qi++) {
				d *= f[fi];
				for (li = 0; li < ln; li++)
					a[nln++] = d * a[li];
			}

			ln = nln;
		}

		sort(0, ln - 1);

		for (li = 0; li < ln; li++)
			printf(" %I64d", a[li]);
			// printf(" %lld", a[li]);
		printf("\n");
	}

	return 0;
}
