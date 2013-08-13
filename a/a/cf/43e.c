#include <stdio.h>

int main() {
	int n, s; scanf("%d%d", &n, &s);

	int i, j, k[100], v[100][100], t[100][100];
	for (i = 0; i < n; i++) {
		scanf("%d", &k[i]);
		for (j = 0; j < k[i]; j++)
			scanf("%d%d", &v[i][j], &t[i][j]);
	}

	int c = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++) {
			int ii = 0, jj = 0, s1 = 0, s2 = 0,
				t1 = 0, t2 = 0, s = 0;
			while (ii < k[i] && jj < k[j]) {
				int t0 = t1 > t2 ? t1 : t2,
					tt1 = t1 + t[i][ii], tt2 = t2 + t[j][jj];
				if (tt1 < tt2) {
					s1 += v[i][ii]*(tt1-t0);
					s2 += v[j][jj]*(tt1-t0);
					t1 = tt1;
					ii++;
				} else {
					s1 += v[i][ii]*(tt2-t0);
					s2 += v[j][jj]*(tt2-t0);
					t2 = tt2;
					jj++;
				}

				if (s1 < s2) {
					if (s == -1)
						c++;
					s = 1;
				} else if (s1 > s2) {
					if (s == 1)
						c++;
					s = -1;
				}
			}
		}

	printf("%d\n", c);

	return 0;
}
