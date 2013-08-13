#include <stdio.h>
#include <string.h>

int main() {
	char s[100000+1]; scanf("%s", s);
	int k; scanf("%d", &k);

	int n = strlen(s);

	if (k > 1ll*n*(n+1)/2) {
		puts("No such line.");
		return 0;
	}

	int an = n, a[100000];
	for (int i = 0; i < n; i++)
		a[i] = i;

	while (k != 0) {
		long long cs[200] = {0};
		for (int i = 0; i < an; i++)
			cs[s[a[i]]] += n-a[i];

		char c = 'a';
		while (k > cs[c]) {
			k -= cs[c];
			c++;
		}

		putchar(c);

		int bn = 0, b[100000], cc = 0;
		for (int i = 0; i < an; i++)
			if (s[a[i]] == c) {
				cc++;
				if (a[i]+1 < n)
					b[bn++] = a[i]+1;
			}
		
		memcpy(a, b, sizeof(*a) * bn);
		an = bn;

		if (k >= cc)
			k -= cc;
		else
			break;
	}

	putchar('\n');

	return 0;
}
