#include <stdio.h>
#include <string.h>

int main() {
	int n; scanf("%d", &n);

	int i, a[100000], b[100000];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	char f[100000]; memset(f, 0, sizeof(f));
	int j;
	for (j = 0; j < 2; j++) {
		if (j == 1) {
			for (i = 1; i < n/2; i++) {
				int t = a[i]; a[i] = a[n-i]; a[n-i] = t;
			}

			for (i = 0; i < n/2; i++) {
				int t = b[i]; b[i] = b[n-1-i]; b[n-1-i] = t;
			}
		}

		int d = a[0] - b[0], m = d;
		for (i = 1; i < n; i++) {
			d += a[i] - b[i];
			if (d < m)
				m = d;
		}

		for (i = 0; i < n; i++) {
			if (m >= 0) {
				if (j == 0)
					f[i] = 1;
				else
					if (i == 0)
						f[i] = 1;
					else
						f[n-i] = 1;
			}
			m -= a[i] - b[i];
		}
	}

	int c = 0;
	for (i = 0; i < n; i++)
		if (f[i])
			c++;

	printf("%d\n", c);
	for (i = 0; i < n; i++)
		if (f[i])
			printf("%d ", i+1);
	putchar('\n');

	return 0;
}
