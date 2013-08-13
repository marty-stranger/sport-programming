#include <stdio.h>

int main() {
	int r, i, j;
	long long k;

	scanf("%d", &r);

	k = 0;
	j = 0;
	for (i = r-1; i >= 0; i--) {
		while ((long long)i*i + (long long)j*j < (long long)r*r)
			j++;

		k += j;
	}

	printf("%I64d", 4*k);

	return 0;
}

