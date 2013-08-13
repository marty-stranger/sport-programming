#include <stdio.h>
#include <string.h>

long long cs[5001][5001];

int main() {
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);

	int i, a[1000000];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	cs[0][0] = 1; cs[0][1] = 0;
	int j;
	for (i = 1; i <= 5000; i++) {
		cs[1][0] = 0;
		for (j = 1; j <= i+1; j++)
			cs[i][j] = (cs[i-1][j-1] + cs[i-1][j] * (j - 1)) % p;
	}

	long long ca[5001];
	ca[0] = 1;
	for (i = 1; i <= 5000; i++)
		ca[i] = (ca[i-1] * (m-i+1)) % p;

	long long cf[5001];
	cf[0] = 1;
	for (i = 1; i <= 5000; i++)
		cf[i] = (cf[i-1] * i) % p;

	long long c[5001], cc[5001];
	for (j = 1; j <= a[0]; j++)
		c[j] = cs[a[0]][j];
	for (i = 1; i < n; i++) {
		long long s = 0;
		for (j = 1; j <= a[i - 1]; j++)
			s = (s + c[j] * ca[j]) % p;
		
		for (j = 1; j <= a[i]; j++) {
			cc[j] = s;
			if (j <= a[i-1])
				cc[j] = (p + cc[j] - (c[j] * cf[j]) % p) % p;
			cc[j] = (cc[j] * cs[a[i]][j]) % p;
		}

		for (j = 1; j <= a[i]; j++)
			c[j] = cc[j];
	}

	long long s = 0;
	for (j = 1; j <= a[n-1]; j++)
		s = (s + ca[j] * c[j]) % p;

	printf("%d\n", s);

	return 0;
}
