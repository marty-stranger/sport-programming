#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int reversedec(char *a) {
	int n, l, r, t;

	l = 0; r = strlen(a) - 1;
	while (l < r) {
		t = a[l]; a[l] = a[r]; a[r] = t;
		l++; r--;
	}

	r = strlen(a);
	for (l = 0; l < r; l++)
		a[l] = a[l] - '0';
}

int main() {
	const int inf = 1000000000;
	int m, n, k, l, i, al, ah, bl, bh, cl, ch, as, bs, cs, s, cc[1001][2];
	char a[1001], b[1001], c[1001];

	scanf("%s%s%s", a, b, c);

	m = strlen(a); n = strlen(b); k = strlen(c); l = max(m, max(n, k));

	reversedec(a);
	reversedec(b);
	reversedec(c);

	cc[0][0] = 0; cc[0][1] = inf;
	for (i = 1; i <= l; i++) {
		if (i < m) {
			al = 0;
			ah = 9;
		} else if (i == m) {
			al = 1;
			ah = 9;
		} else
			al = ah = 0;

		if (i < n) {
			bl = 0;
			bh = 9;
		} else if (i == n) {
			bl = 1;
			bh = 9;
		} else
			bl = bh = 0;

		if (i < k) {
			cl = 0;
			ch = 9;
		} else if (i == k) {
			cl = 1;
			ch = 9;
		} else
			cl = ch = 0;

		cc[i][0] = cc[i][1] = inf;

		for (as = al; as <= ah; as++)
			for (bs = bl; bs <= bh; bs++)
				for (cs = cl; cs <= ch; cs++) {
					s = abs(a[i - 1] - as) + abs(b[i - 1] - bs) + abs(c[i - 1] - cs);
					if (as + bs == 10 + cs)
						if (s + cc[i - 1][0] < cc[i][1])
							cc[i][1] = s + cc[i - 1][0];
					if (as + bs + 1 == 10 + cs)
						if (s + cc[i - 1][1] < cc[i][1])
							cc[i][1] = s + cc[i - 1][1];
					if (as + bs == cs)
						if (s + cc[i - 1][0] < cc[i][0])
							cc[i][0] = s + cc[i - 1][0];
					if (as + bs + 1 == cs)
						if (s + cc[i - 1][1] < cc[i][0])
							cc[i][0] = s + cc[i - 1][1];
				}
	}

	if (cc[l][0] == inf)
		puts("-1");
	else
		printf("%d", cc[l][0]);
		
	return 0;
}
