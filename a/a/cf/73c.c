#include <stdio.h>
#include <string.h>

int b[200][200];
char s[101];

int c[101][200][100];
char cb[101][200][100];

int count(int n, char ch, int k) {
	if (n == 0)
		return 0;

	if (!cb[n][ch][k]) {
		char ch2;

		int m = count(n-1, s[n-1], k) + b[s[n-1]][ch];

		if (k > 0)
			for (ch2 = 'a'; ch2 <= 'z'; ch2++)
				if (ch2 != s[n-1]) {
					int cc = count(n-1, ch2, k-1) + b[ch2][ch];

					if (cc > m)
						m = cc;
				}
		
		c[n][ch][k] = m;
		cb[n][ch][k] = 1;

		// printf("%d %c %d -> %d\n", n+1, ch, k, m);
	}

	return c[n][ch][k];
}

int main() {
	int k, m;
	scanf("%s%d%d\n", s, &k, &m);
	
	int i;
	memset(b, 0, sizeof(b));
	for (i = 0; i < m; i++) {
		char c1, c2; int bb;
		scanf("%c %c%d\n", &c1, &c2, &bb);
		b[c1][c2] = bb;
	}

	int n = strlen(s);
	char ch;

	memset(cb, 0, sizeof(cb));

	n--;
	int mm = count(n, s[n], k);
	if (k != 0)
		for (ch = 'a'; ch <= 'z'; ch++)
			if (ch != s[n]) {
				int cc = count(n, ch, k-1);
				if (cc > mm)
					mm = cc;
			}

	printf("%d\n", mm);

	return 0;
}
