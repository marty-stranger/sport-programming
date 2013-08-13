#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a, b, c, d, n;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);

	int i, x[26];
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	int dir;
	if (a % 2 == 0)
		dir = 1;
	else
		dir = -1;

	char s[50][101];
	memset(s, '.', sizeof(s));
	for (i = 0; i < 50; i++)
		s[i][a+c] = '\0';

	i = 0;
	int j, k;
	for (j = 0; j < a; j++) {
		if (dir == 1)
			for (k = 0; k < b; k++) {
				s[k][j] = i + 'a';
				x[i]--;
				if (x[i] == 0)
					i++;
			}
		else
			for (k = b-1; k >= 0; k--) {
				s[k][j] = i + 'a';
				x[i]--;
				if (x[i] == 0)
					i++;
			}

		dir = -dir;
	}

	for (j = 0; j < c; j++) {
		if (dir == 1)
			for (k = 0; k < d; k++) {
				s[k][a+j] = i + 'a';
				x[i]--;
				if (x[i] == 0)
					i++;
			}
		else
			for (k = d-1; k >= 0; k--) {
				s[k][a+j] = i + 'a';
				x[i]--;
				if (x[i] == 0)
					i++;
			}

		dir = -dir;
	}

	puts("YES");
	for (i = 0; i < max(b, d); i++)
		puts(s[i]);

	return 0;
}
