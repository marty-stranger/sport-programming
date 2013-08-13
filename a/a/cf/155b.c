#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[n], b[n], c[n];
	int ca = 0, cb = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);

		if (b[i] > 0) {
			ca += a[i];
			cb += b[i];
			cb--;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] > a[i]) {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				t = b[i]; b[i] = b[j]; b[j] = t;
			}

	for (int i = 0; i < n; i++)
		if (b[i] == 0 && cb > 0) {
			ca += a[i];
			cb--;
		}

	printf("%d\n", ca);

	return 0;
}
