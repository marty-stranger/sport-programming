#include <stdio.h>
#include <string.h>

int main() {
	int m, kk, n, k, i, j, l, d, s, next[11112], ind[11112], num[11112];

	for (i = 1; i <= 11111; i++) {
		j = 3 * i;
		s = 0;
		while (j != 0) {
			d = j % 10;
			s += d*d*d;
			j /= 10;
		}

		next[i] = s / 3;
	}

	scanf("%d", &m);
	for (kk = 0; kk < m; kk++) {
		scanf("%d%d%d", &n, &k, &l); k /= 3;

		/* ind[k] = 0;
		num[0] = k;
		memset(ind, 0, sizeof(ind));
		i = 0;
		while (i < n - 1 && ind[next[k]] == 0) {
			i++;
			ind[next[k]] = i;
			num[i] = next[k];
			k = next[k];
		}

		if (i == n - 1)
			d = k;
		else {
			n -= ind[next[k]];
			d = num[ind[next[k]]] + n % (ind[k] - ind[next[k]] + 1);
		} */

		for (i = 0; i < n - 1; i++)
			k = next[k];

		printf("%d\n", 3*k - l);
	}
}
