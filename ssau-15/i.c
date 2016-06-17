#include <stdio.h>

int main() {
	int n;
	long long d, c;
	scanf("%d%lld%lld", &n, &d, &c);
	
	long long a[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	long long ss[1001];
	ss[0] = 0;
	for (int i = 1; i <= n; i++)
		ss[i] = ss[i-1] + a[i-1];

	long long cs[1000 + 1] = {0};
	cs[0] = 0;
	for (int i = 1; i <= n; i++) {
		cs[i] = 1e18;
		for (int j = 0; j < i; j++) {
			long long cc = cs[j] + d + (a[i - 1] * (i - j) - (ss[i] - ss[j])) * c;
			if (cc < cs[i])
				cs[i] = cc;
		}

		// printf("i = %d -> %d\n", i, cs[i]);
	}

	printf("%lld\n", cs[n]);

	return 0;
}
