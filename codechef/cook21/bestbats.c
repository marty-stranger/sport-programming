#include <stdio.h>

int main() {
	int t; scanf("%d", &t);

	int c[12][12] = {0};

	c[0][0] = 1;
	for (int i = 0; i <= 11; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	for (int ti = 0; ti < t; ti++) {
		int a[11];
		int cs[101] = {0};
		for (int i = 0; i < 11; i++) {
			scanf("%d", &a[i]);
			cs[a[i]]++;
		}

		for (int i = 0; i < 11; i++)
			for (int j = i; j < 11; j++)
				if (a[j] > a[i]) {
					int t = a[i]; a[i] = a[j]; a[j] = t;
				}
		
		int k; scanf("%d", &k);

		int cs1[101] = {0};
		for (int i = 0; i < k; i++)
			cs1[a[i]]++;

		long long p = 1;
		for (int i = 0; i < 101; i++)
			p *= c[cs[i]][cs1[i]];

		printf("%lld\n", p);
	}


	return 0;
}
