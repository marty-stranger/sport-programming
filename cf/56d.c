#include <stdio.h>
#include <string.h>

char s[2001], t[2001];
int m, p[2001][2001], a[2001];

void trace(int i, int j) {
	if (i == 0 && j == 0)
		return;

	// printf("i = %d, j = %d\n", i, j);

	if (p[i][j] == 0) {
		trace(i, j-1);
		// printf("i = %d\n", i);
		printf("INSERT %d %c\n", a[i]+1, t[j-1]);
		int k;
		for (k = i; k <= m; k++)
			a[k]++;
		/* printf("a = ");
		for (k = 0; k <= m; k++)
			printf("%d ", a[k]+1);
		putchar('\n'); */
	} else if (p[i][j] == 1) {
		trace(i-1, j);
		printf("DELETE %d\n", a[i-1]+1);
		int k;
		for (k = i-1; k <= m; k++)
			a[k]--;
	} else if (p[i][j] == 2) {
		trace(i-1, j-1);
		printf("REPLACE %d %c\n", a[i-1]+1, t[j-1]);
	} else
		trace(i-1, j-1);
}

int c[2001][2001];

int main() {
	gets(s);
	gets(t);

	m = strlen(s); int n = strlen(t);

	int i, j;
	c[0][0] = 0;
	for (i = 1; i <= n; i++) {
		c[0][i] = c[0][i-1] + 1;
		p[0][i] = 0; // insert
	}
	for (i = 1; i <= m; i++) {
		c[i][0] = c[i-1][0] + 1;
		p[i][0] = 1; // delete
	}

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (s[i-1] == t[j-1]) {
				c[i][j] = c[i-1][j-1];
				p[i][j] = 3;
			} else {
				int c1 = c[i][j-1] + 1;
				int c2 = c[i-1][j] + 1;
				int c3 = c[i-1][j-1] + 1;

				int cc = c1;
				if (c2 < cc)
					cc = c2;
				if (c3 < cc)
					cc = c3;

				c[i][j] = cc;
				if (c1 == cc)
					p[i][j] = 0;
				else if (c2 == cc)
					p[i][j] = 1;
				else
					p[i][j] = 2;

			}

	printf("%d\n", c[m][n]);

	for (i = 0; i <= m; i++)
		a[i] = i;

	trace(m, n);

	return 0;
}
