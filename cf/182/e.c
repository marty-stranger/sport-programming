#include <stdio.h>

int main() {
	const int mod = 1000000007;
	int n, l; scanf("%d%d", &n, &l);

	int a[100], b[100];
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);

	int c[3001][100][2] = {0};

	for (int i = 0; i < n; i++) {
		c[a[i]][i][0] = 1;
		c[b[i]][i][1] = 1;
	}

	for (int i = 1; i <= l; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				if (k != j) {
					if (a[j] == b[k] && i-a[j] >= 0)
						c[i][j][0] = (c[i][j][0] + c[i-a[j]][k][0]) % mod;
					if (b[k] != a[k] && a[j] == a[k] && i-a[j] >= 0)
						c[i][j][0] = (c[i][j][0] + c[i-a[j]][k][1]) % mod;
					if (b[j] == b[k] && i-b[j] >= 0)
						c[i][j][1] = (c[i][j][1] + c[i-b[j]][k][0]) % mod;
					if (b[k] != a[k] && b[j] == a[k] && i-b[j] >= 0)
						c[i][j][1] = (c[i][j][1] + c[i-b[j]][k][1]) % mod;
				}
		}

	int s = 0;
	for (int i = 0; i < n; i++) {
		s = (s + c[l][i][0]) % mod;
		if (a[i] != b[i])
			s = (s + c[l][i][1]) % mod;
	}
	
	printf("%d\n", s);

	return 0;
}
