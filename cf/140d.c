#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, a[100];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i]) {
				int t = a[j]; a[j] = a[i]; a[i] = t;
			}

	/* for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n'); */

	i = 0;
	int t = 10;
	while (i < n && t + a[i] <= 360) {
		t += a[i];
		i++;
	}

	// printf("t = %d\n", t);

	t -= 360;
	int s = 0;
	while (i < n && t + a[i] <= 360) {
		t += a[i];
		s += t;
		i++;
	}

	printf("%d %d\n", i, s);

	return 0;
}
