#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int n, m; scanf("%d%d", &n, &m);

	char a[n][m + 1];
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	long long cs[100002] = {0};
	for (int i = 0; i < n; i++) {
		int j = 0;

		while (j < m) {
			while (j < m && a[i][j] != '.')
				j++;

			int k = j;
			while (j < m && a[i][j] == '.')
				j++;

			cs[j - k]++;
		}
	}

	for (int j = 0; j < m; j++) {
		int i = 0;

		while (i < n) {
			while (i < n && a[i][j] != '.')
				i++;

			int k = i;
			while (i < n && a[i][j] == '.')
				i++;

			cs[i - k]++;
		}
	}

	int c1 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '.')
				c1++;

	int mn = m;
	if (n > mn)
		mn = n;

	for (int i = mn; i >= 2; i--)
		cs[i] += cs[i + 1];

	long long as[100002] = {0};

	for (int i = mn; i >= 2; i--)
		as[i] = as[i+1] + cs[i];

	printf("%d", c1);
	for (int i = 2; i <= mn; i++)
		printf(" %lld", as[i]);

	return 0;
}
