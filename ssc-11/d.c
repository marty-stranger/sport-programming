#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	if (n == 21) {
		puts("1");
		return 0;
	}

	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++) {
			int nn = n - (21-i) - (21-j);
			if (nn >= 0 && nn % 14 == 0) {
				printf("%d\n", 2 + nn/14);
				return 0;
			}
		}

	puts("-1");

	return 0;
}
