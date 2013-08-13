#include <stdio.h>
#include <string.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int cn[1000], xn[1000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, p = xn[(l + r) / 2];
		while (i <= j)
			if (xn[i] < p)
				i++;
			else if (xn[j] > p)
				j--;
			else {
				int t = cn[i]; cn[i] = cn[j]; cn[j] = t;
				t = xn[i]; xn[i] = xn[j]; xn[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	int z;
	scanf("%d", &z);

	int zi;
	for (zi = 0; zi < z; zi++) {
		int c, t, l;
		scanf("%d%d%d", &c, &t, &l);

		int i, cl[1000], cr[1000], x[1000];
		memset(cl, 0, sizeof(cl));
		memset(cr, 0, sizeof(cr));
		memset(x, 0, sizeof(x));

		for (i = 0; i < c; i++) {
			int j;
			for (j = 0; j < t; j++) {
				scanf("%d%d", &xn[j], &cn[j]);

				int l = 0, r = t - 1;
				while (l < r) {
					int m = (l + r + 1) / 2;
					if (x[m] < xn[j])
						l = m;
					else
						r = m - 1;
				}

				if (x[l] >= xn[j])
					cn[j] += cr[l] - xn[j];
				else if (l + 1 >= t)
					cn[j] += cl[l] + xn[j];
				else
					cn[j] += min(cl[l] + xn[j], cr[l + 1] - xn[j]);

				// printf("j = %d cn = %d\n", j, cn[j]);
			}

			sort(0, t - 1);

			cl[0] = cn[0] - xn[0];
			for (j = 1; j < t; j++)
				cl[j] = min(cl[j - 1], cn[j] - xn[j]);

			cr[t-1] = cn[t-1] + xn[t-1];
			for (j = t - 2; j >= 0; j--)
				cr[j] = min(cr[j+1], cn[j] + xn[j]);

			memcpy(x, xn, sizeof(x));
		}

		printf("%d\n", cl[t-1] + l);
	}

	return 0;
}
