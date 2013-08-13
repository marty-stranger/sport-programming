#include <stdio.h>
#include <string.h>

const int mod = 1000000007;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	char s[100][101];
	int i;
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

	long long r = 1;
	for (i = 0; i < m; i++) {
		char b[100];
		memset(b, 0, sizeof(b));
		int j;

		int c = 0;
		for (j = 0; j < n; j++)
			if (!b[s[j][i]]) {
				b[s[j][i]] = 1;
				c++;
			}

		r = (r * c) % mod;
	}

	printf("%d\n", r);

	return 0;
}
