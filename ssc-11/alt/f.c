#include <ctype.h>
#include <stdio.h>
#include <string.h>

int c[2500][2500];

int main() {
	const int inf = 1000000000;
	char a[2501];
	int n, i, j, d, k, cc, sn, s[2500], ln, l[5], lln, ll[4], li;

	gets(a); n = strlen(a);

	cc = 0; sn = 0; ln = lln = 0; j = 0;
	for (i = 0; i < n; i++)
		if (islower(a[i]))
			s[sn++] = a[i];
		else if (isupper(a[i]))
			if (sn == 0)
				a[j++] = a[i];
			else if (a[i] - 'A' == s[sn-1] - 'a') {
				sn--;
				cc++;
			} else
				break;
		else { // '*'
			if (ln == 0 && j != 0)
				break;

			ll[lln++] = j;
			for (k = 0; k < sn; k++)
				a[j++] = s[k];
			sn = 0;

			l[ln++] = j;
			a[j++] = a[i];
		}

	if (i != n || sn != 0) {
		puts("-1");
		return 0;
	}

	n = j;

	for (i = 0; i < n; i++)
		if (a[i] == '*')
			c[i][i] = 0;
		else
			c[i][i] = inf;

	for (d = 1; d < n; d++) {
		for (i = 0, j = d; j < n; i++, j++) {
			if (islower(a[i]) && a[j] == '*')
				c[i][j] = c[i+1][j] + 1;
			else if (a[i] == '*' && isupper(a[j]))
				c[i][j] = c[i][j-1] + 1;
			else if (islower(a[i]) && isupper(a[j]) && a[i] - 'a' == a[j] - 'A')
				c[i][j] = c[i+1][j-1] + 1;
			else
				c[i][j] = inf;

			for (li = 0; li < ln; li++) {
				k = l[li];
				if (i < k && k < j && c[i][k] + c[k][j] < c[i][j])
					c[i][j] = c[i][k] + c[k][j];
			}

			for (li = 0; li < lln; li++) {
				k = ll[li];
				if (i < k && k <= j && c[i][k-1] + c[k][j] < c[i][j])
					c[i][j] = c[i][k-1] + c[k][j];
			}
		}
	}

	if (c[0][n-1] == inf)
		puts("-1");
	else
		printf("%d\n", c[0][n-1] + cc);

	return 0;
}
