#include <stdio.h>

int main() {
	int n, nn, i, j;

	scanf("%d", &n);

	if (n == 21) {
		printf("1\n");
		return 0;
	}

	for (i = 1; i <= 6; i++)
		for (j = 1; j <= 6; j++) {
			nn = n - (21 - i) - (21 - j);
			if (nn >= 0 && nn % 14 == 0) {
				printf("%d\n", 2 + (nn / 14));
				return 0;
			}
		}

	printf("-1\n");

	return 0;
}
