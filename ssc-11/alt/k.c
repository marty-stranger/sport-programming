#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 20000*200
int m, as[MAX], ai[MAX], af[MAX], ax[MAX];

void sort(int l, int r) {
	int i, j, pf, px, ps, t;

	if (l >= r)
		return;

	i = l; j = r; pf = af[(l + r) / 2]; px = ax[(l + r) / 2], ps = as[(l + r) / 2];
	while (i <= j)
		if (af[i] * px < pf * ax[i] || (af[i]*px == pf*ax[i] && as[i] > ps))
			i++;
		else if (af[j] * px > pf * ax[j] || (af[j]*px == pf*ax[j] && as[j] < ps))
			j--;
		else {
			t = as[i]; as[i] = as[j]; as[j] = t;
			t = ai[i]; ai[i] = ai[j]; ai[j] = t;
			t = af[i]; af[i] = af[j]; af[j] = t;
			t = ax[i]; ax[i] = ax[j]; ax[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

int main() {
	int n, i, k, s, vv, vvv, x, r, g, d, ss, ms, mi, b[20000];
	double xx;

	scanf("%d%d%d%d", &n, &s, &vv, &vvv);

	m = 0;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x, &r, &g, &d);
		// printf("i = %d\n", i);

		k = ceil((x * 1. / vvv - d) / (r + g));

		while (vv * (d - g + (r + g) * k) <= x) {
			as[m] = 1; ax[m] = x; af[m] = d - g + (r + g) * k; ai[m] = i;
			if (af[m] * vvv < x)
				ax[m] = vvv, af[m] = 1;
			m++;

			as[m] = -1; ax[m] = x; af[m] = d + (r + g) * k; ai[m] = i;
			if (af[m] * vv > x)
				ax[m] = vv, af[m] = 1;
			m++;

			// printf("%lf %lf\n", ax[m-2]*1./af[m-2], ax[m-1]*1./af[m-1]);
			k++;
		}
	}

	sort(0, m - 1);

	ss = 0; ms = 0;
	for (i = 0; i < m; i++) {
		ss += as[i];
		// printf("%d %d %lf\n", as[i], ai[i], ax[i]*1./af[i]);

		if (ss > ms)
			ms = ss, mi = i;
	}

	memset(b, 0, sizeof(b));
	for (i = 0; i <= mi; i++) {
		if (as[i] == 1)
			b[ai[i]] = 1;
		else
			b[ai[i]] = 0;
	}

	printf("%.10lf\n%d\n", ax[mi]*1. / af[mi], n - ms);
	for (i = 0; i < n; i++)
		if (!b[i])
			printf("%d ", i + 1);
	putchar('\n');

	return 0;
}
