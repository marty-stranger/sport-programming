#include <ctype.h>
#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
	char a[2501]; scanf("%s", a);

	char st[2500];
	int stn = 0, cc = 0, n = 0, ln = 0, l[10], lln = 0, ll[10];
	for (char *c = a; *c != '\0'; c++)
		if (islower(*c))
			st[stn++] = *c;
		else if (isupper(*c))
			if (stn == 0)
				a[n++] = *c;
			else if (*c - 'A' == st[stn-1] - 'a') {
				stn--;
				cc++;
			} else {
				puts("-1");
				return 0;
			}
		else { // '*'
			if (ln == 0 && n != 0) {
				puts("-1");
				return 0;
			}

			ll[lln++] = n;
			for (int i = 0; i < stn; i++)
				a[n++] = st[i];
			stn = 0;

			l[ln++] = n;
			a[n++] = *c;
		}

	if (stn != 0) {
		puts("-1");
		return 0;
	}

	static int c[2500][2500] = {0};

	const int inf = 1e9;
	for (int i = 0; i < n; i++)
		if (a[i] == '*')
			c[i][i] = 0;
		else
			c[i][i] = inf;

	for (int d = 1; d < n; d++)
		for (int i = 0, j = d; j < n; i++, j++) {
			if (islower(a[i]) && a[j] == '*')
				c[i][j] = c[i+1][j] + 1;
			else if (a[i] == '*' && isupper(a[j]))
				c[i][j] = c[i][j-1] + 1;
			else if (islower(a[i]) && isupper(a[j]) && a[i]-'a' == a[j]-'A')
				c[i][j] = c[i+1][j-1] + 1;
			else
				c[i][j] = inf;

			for (int li = 0; li < ln; li++) {
				int k = l[li];
				if (i < k && k < j)
					c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}

			for (int li = 0; li < lln; li++) {
				int k = ll[li];
				if (i < k && k <= j)
					c[i][j] = min(c[i][j], c[i][k-1] + c[k][j]);
			}
		}

	if (c[0][n-1] == inf)
		puts("-1");
	else
		printf("%d\n", c[0][n-1] + cc);

	return 0;
}
