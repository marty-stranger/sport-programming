#include <stdio.h>
#include <string.h>

const int mod = 1000000007;
char s[701];
int c[700][700][3][3];

int sum(int a, int b) {
	return (a + b) % mod;
}

int mul(int a, int b) {
	return 1LL*a*b%mod;
}

int count(int i, int j, int ci, int cj) {
	int col, d = 0, k = i+1, l, cc1[3], cc2[3];

	if (c[i][j][ci][cj] != -1)
		return c[i][j][ci][cj];

	for (col = 0; col < 3; col++)
		if (col == ci)
			cc1[col] = 1;
		else
			cc1[col] = 0;

	k = i+1;
	while (k < j) {
		l = k; d = 1;
		while (d != 0) {
			l++;
			if (s[l] == '(')
				d++;
			else if (s[l] == ')')
				d--;
		}

		cc2[0] = sum(mul(count(k, l, 1, 0), sum(cc1[0], cc1[2])),
				mul(count(k, l, 2, 0), sum(cc1[0], cc1[1])));
		cc2[1] = mul(count(k, l, 0, 1), sum(sum(cc1[0], cc1[1]), cc1[2]));
		cc2[2] = mul(count(k, l, 0, 2), sum(sum(cc1[0], cc1[1]), cc1[2]));

		memcpy(cc1, cc2, sizeof(cc1));

		k = l+1;
	}

	int t;
	if (cj == 0)
		t = sum(sum(cc1[0], cc1[1]), cc1[2]);
	else if (cj == 1)
		t = sum(cc1[0], cc1[2]);
	else
		t = sum(cc1[0], cc1[1]);

	return c[i][j][ci][cj] = t;
}

int main() {
	int i, j, k, l, n, ci, cj, cc1[3], cc2[3], tc, d;

	gets(s);
	n = strlen(s);

	cc1[0] = 1; cc1[1] = cc1[2] = 0;

	memset(c, -1, sizeof(c));
	k = 0;
	while (k < n) {
		l = k; d = 1;
		while (d != 0) {
			l++;
			if (s[l] == '(')
				d++;
			else if (s[l] == ')')
				d--;
		}

		cc2[0] = sum(mul(count(k, l, 1, 0), sum(cc1[0], cc1[2])),
				mul(count(k, l, 2, 0), sum(cc1[0], cc1[1])));
		cc2[1] = mul(count(k, l, 0, 1), sum(sum(cc1[0], cc1[1]), cc1[2]));
		cc2[2] = mul(count(k, l, 0, 2), sum(sum(cc1[0], cc1[1]), cc1[2]));

		memcpy(cc1, cc2, sizeof(cc1));

		k = l+1;
	}

	printf("%d\n", sum(sum(cc1[0], cc1[1]), cc1[2]));

	return 0;
}
