#include <stdio.h>
#include <string.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int t;
	scanf("%d", &t);

	int ti;
	for (ti = 0; ti < t; ti++) {
		int n, k;
		scanf("%d%d\n", &n, &k);

		char s[10101];
		gets(s);

		int c[10101][28], cs[10101];
		memset(c, 0, sizeof(c));
		memset(cs, 0, sizeof(cs));
		c[0][0] = 1; cs[0] = 1;

		int i;
		for (i = 0; i < n+k; i++) {
			int j;

			for (j = min(i+1, n); j >= 1 && j >= min(i+1, n) - k-1; j--) {
				char ch;

				cs[j] = (cs[j] - c[j][s[i]-'a'+1] + 1009419529) % 1009419529;
				c[j][s[i]-'a'+1] = cs[j-1];
				cs[j] = (cs[j] + cs[j-1]) % 1009419529;
			}
		}

		int r = 0;
		char ch;
		for (ch = 'a'; ch <= 'z'; ch++)
			r = (r + c[n][ch-'a'+1]) % 1009419529;

		r = (r - 1 + 1009419529) % 1009419529;

		printf("%d\n", r);
	}

	return 0;
}
