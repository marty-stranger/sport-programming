#include <stdio.h>

int main() {
	int k; scanf("%d", &k);

	int i, a[12];
	for (i = 0; i < 12; i++)
		scanf("%d", &a[i]);

	int j;
	for (i = 0; i < 12; i++)
		for (j = i+1; j < 12; j++)
			if (a[j] > a[i]) {
				int t = a[i]; a[i] = a[j]; a[j] = t;
			}

	if (k == 0) {
		puts("0");
		return 0;
	}

	for (i = 0; i < 12; i++)
		if (k > a[i])
			k -= a[i];
		else
			break;

	if (i == 12)
		puts("-1");
	else
		printf("%d\n", i+1);

	return 0;
}
