#include <stdio.h>
#include <string.h>

int c[5001][5001] = {0};

const int mod = 1000000007;

int main() {
	char s[5000+1], t[5000+1];
	scanf("%s%s", s, t);

	int sl = strlen(s), tl = strlen(t);

	c[0][0] = (s[0] == t[0]);
	for (int j = 1; j < tl; j++)
		if (s[0] == t[j])
			c[0][j] = c[0][j-1] + 1;
		else
			c[0][j] = c[0][j-1];

	for (int i = 1; i < sl; i++) {
		if (s[i] == t[0])
			c[i][0] = 1;
		else
			c[i][0] = 0;

		for (int j = 1; j < tl; j++)
			if (s[i] == t[j])
				c[i][j] = (c[i-1][j-1] + c[i][j-1] + 1) % mod;
			else
				c[i][j] = c[i][j-1];
	}

	int r = 0;
	for (int i = 0; i < sl; i++)
		r = (r + c[i][tl-1]) % mod;

	printf("%d\n", r);

	return 0;
}
