#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int c[10000];
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	int r[100][101];
	for (int i = 1; i < m; i++) {
		r[i%m][2] = c[i] + c[i-1];
		for (int j = 3; j <= m && j <= i+1; j++)
			r[i%m][j] = min(r[i%m][j-1], c[i-j+1] + c[i]);
	}

	for (int i = m; i < n; i++) {
		r[i%m][2] = c[i] + r[(i-1)%m][m];
		for (int j = 3; j <= m; j++)
			r[i%m][j] = min(r[i%m][j-1], r[(i-j+1)%m][m-j+2] + c[i]);
	}

	int a = 1e9;
	for (int i = n-m+1; i < n; i++)
		a = min(a, r[i%m][m-(n-1-i)]);
	
	printf("%d\n", a); 

	return 0;
}
