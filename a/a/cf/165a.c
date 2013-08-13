#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int x[n], y[n];
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);

	int t = 0;
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++)
			if (x[j] < x[i] && y[j] == y[i]) {
				c++;
				break;
			}
		for (int j = 0; j < n; j++)
			if (x[j] > x[i] && y[j] == y[i]) {
				c++;
				break;
			}
		for (int j = 0; j < n; j++)
			if (x[j] == x[i] && y[j] < y[i]) {
				c++;
				break;
			}
		for (int j = 0; j < n; j++)
			if (x[j] == x[i] && y[j] > y[i]) {
				c++;
				break;
			}

		if (c == 4)
			t++;
	}

	printf("%d\n", t);

	return 0;
}
