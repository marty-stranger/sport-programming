#include <stdio.h>
#include <string.h>

char s[10][10];
int n, k, b[10], p[10];

int d = -1;

void gen(int i) {
	if (i == k) {
		int j, m = -1, mm = -1;
		for (j = 0; j < n; j++) {
			char ss[10];
			int ii;
			for (ii = 0; ii < k; ii++)
				ss[ii] = s[j][p[ii]];
			ss[k] = '\0';

			int a;
			sscanf(ss, "%d", &a);
			if (m == -1 || a < m)
				m = a;
			if (mm == -1 || a > mm)
				mm = a;
		}

		if (d == -1 || mm - m < d)
			d = mm - m;

		return;
	}

	int j;
	for (j = 0; j < k; j++)
		if (!b[j]) {
			b[j] = 1;
			p[i] = j;
			gen(i + 1);
			b[j] = 0;
		}
}

int main() {
	scanf("%d%d\n", &n, &k);

	int i;
	for (i = 0; i < n; i++)
		gets(s[i]);

	memset(b, 0, sizeof(b));
	gen(0);

	printf("%d\n", d);

	return 0;
}
