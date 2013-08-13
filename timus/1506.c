#include <stdio.h>

int main() {
	int n, k, l, i, j, a[100];

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	if (n % k == 0)
		l = n / k;
	else
		l = n / k + 1;

	for (i = 0; i < l; i++) {
		for (j = i; j < n; j += l)
			printf("%4d", a[j]);
		putchar('\n');
	}
	
	return 0;
}

