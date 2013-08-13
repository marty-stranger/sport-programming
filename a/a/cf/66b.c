#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int i, a[1000];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int m = 0;
	for (i = 0; i < n; i++) {
		int j, c = 0;
		for (j = i+1; j < n; j++)
			if (a[j] <= a[j-1])
				c++;
			else
				break;

		for (j = i-1; j >= 0; j--)
			if (a[j] <= a[j+1])
				c++;
			else
				break;

		if (c > m)
			m = c;
	}

	printf("%d\n", m + 1);

	return 0;
}
