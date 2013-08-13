#include <stdio.h>
#include <string.h>

int main() {
	int n, m, k;
	scanf("%d%d%d\n", &n, &m, &k);

	char a[500][501];
	int i;
	for (i = 0; i < n; i++)
		gets(a[i]);

	int j, c[500][500]; memset(c, 0, sizeof(c));
	for (i = 2; i < n; i++)
		for (j = 2; j < m; j++) {
			c[i][j] = c[i][j-1] + c[i-1][j] - c[i-1][j-1];
			if (a[i-1][j-1] == '1' && a[i-1][j] == '1' && a[i][j-1] == '1' &&
					a[i-2][j-1] == '1' && a[i-1][j-2] == '1')
				c[i][j]++;
			// printf("%d %d -> %d\n", i+1, j+1, c[i][j]);
		}

	long long cc = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			int ii, jj = m-1;
			for (ii = i+2; ii < n; ii++) {
				int rc;
				while (1) {
					jj--;
					if (j+2 > jj || c[ii][jj] - c[ii][j+1] - c[i+1][jj] + c[i+1][j+1] < k) {
						jj++;
						break;
					}
				}

				// printf("%d %d %d %d\n", i+1, j+1, ii+1, jj+1);

				if (j+2 <= jj && c[ii][jj] - c[ii][j+1] - c[i+1][jj] + c[i+1][j+1] >= k) {
					cc += (m-jj);
					// printf("%lld\n", cc);
				}
			}
		}

	printf("%I64d\n", cc);

	return 0;
}
