#include <stdio.h>
#include <string.h>

char g[10][5], ss[5], s[5];
int n, cc = 0, a[10], b[10];

void check() {
	int i;
	for (i = 0; i < n; i++) {
		int j, aa = 0, bb = 0;
		for (j = 0; j < 4; j++)
			if (g[i][j] == s[j])
				aa++;
			else {
				int k;
				for (k = 0; k < 4; k++)
					if (g[i][j] == s[k])
						break;

				if (k != 4)
					bb++;
			}

		if (aa != a[i] || bb != b[i])
			break;
	}

	if (i == n) {
		cc++;
		strcpy(ss, s);
	}
}

int main() {
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
		scanf("%s%d%d", g[i], &a[i], &b[i]);

	char a, b, c, d;
	for (a = '0'; a <= '9'; a++)
		for (b = '0'; b <= '9'; b++)
			for (c = '0'; c <= '9'; c++)
				for (d = '0'; d <= '9'; d++)
					if (a != b && a != c && a != d && b != c && b != d && c != d) {
						s[0] = a; s[1] = b; s[2] = c; s[3] = d; s[4] = '\0';
						check();
					}

	if (cc == 0)
		puts("Incorrect data");
	else if (cc == 1)
		puts(ss);
	else
		puts("Need more data");

	return 0;
}
