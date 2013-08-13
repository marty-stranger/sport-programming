#include <stdio.h>
#include <string.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	char s[100001];
	gets(s);

	int i, l = strlen(s), c[10];
	memset(c, 0, sizeof(c));
	for (i = 0; i < l; i++)
		c[s[i] - '0']++;

	int cc[10];
	memcpy(cc, c, sizeof(cc));

	int mz = c[0], md, ms = 0, d, z;
	for (z = 0; z <= c[0]; z++) {
		c[0] -= z; cc[0] -= z;
		for (d = 1; d <= 9; d++)
			if (c[d] > 0 && cc[10 - d] > 0) {
				int s = 1 + z;
				c[d]--; cc[10 - d]--;

				int dd;
				for (dd = 0; dd <= 9; dd++)
					s += min(c[dd], cc[9 - dd]);

				c[d]++; cc[10 - d]++;

				if (s > ms)
					mz = z, ms = s, md = d;
			}

		c[0] += z; cc[0] += z;
	}

	int n1[100001], n2[100001];

	i = 0;
	int j;
	for (j = 0; j < mz; j++)
		n1[i] = n2[i] = 0, i++, c[0]--, cc[0]--;

	if (ms != 0) {
		n1[i] = md; n2[i] = 10 - md;
		c[md]--; cc[10 - md]--;
		i++;

		for (d = 0; d <= 9; d++) {
			int j, m = min(c[d], cc[9-d]);
			for (j = 0; j < m; j++)
				n1[i] = d, n2[i] = 9 - d, i++;
			c[d] -= m, cc[9 - d] -= m;
		}
	}

	int i1 = i, i2 = i;
	for (d = 0; d <= 9; d++) {
		while (c[d] > 0) {
			c[d]--;
			n1[i1] = d;
			i1++;
		}

		while (cc[d] > 0) {
			cc[d]--;
			n2[i2] = d;
			i2++;
		}
	}

	for (i = i1 - 1; i >= 0; i--)
		putchar(n1[i] + '0');
	putchar('\n');

	for (i = i2 - 1; i >= 0; i--)
		putchar(n2[i] + '0');
	putchar('\n');

	return 0;
}
