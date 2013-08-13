#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int count(int l) {
	int c = 0;
	while (l != 0) {
		if (l%2 != 0)
			c++;
		l /= 2;
	}

	return c;
}

bool not_attack(int p1, int p2, int s) {
	return (lp & lp<<s) == 0 && (lp & lp>>s) == 0;
}

int main() {
	int n; scanf("%d", &n);

	if (n == 1) {
		puts("1 1");
		return 0;
	}

	static long long c[51][1<<10][1<<10] = {0};
	for (int p1 = 0; p1 < 1<<n; p1++) for (int p2 = 0; p2 < 1<<n; p2++)
		if (not_attack(p1, p2, 2))
			c[count(p1) + count(p2)][p1][p2] = 1;

	for (int i = 2; i < n; i++) {
		static long long cc[51][1<<10][1<<10];
		memset(cc, 0, sizeof cc);

		for (int k = 0; k <= n*n && k <= 50; k++)
			for (int p1 = 0; p1 < 1<<n; p1++) {
				int p1c = count(p1);
				if (k < p1c) 
					continue;

				for (int p2 = 0; p2 < 1<<n; p2++)
					if (not_attack(p1, p2, 2))
						for (int l3 = 0; l3 < 1<<n; l3++)
							if (not_attack(p2, l3, 2) && not_attack(p1, l3, 1))
								cc[k][p1][p2] += c[k-p1c][p2][l3];
			}

		memcpy(c, cc, sizeof cc);
	}

	for (int k = 0; k <= n*n && k <= 50; k++) {
		long long s = 0;
		for (int p1 = 0; p1 < 1<<n; p1++)
			for (int p2 = 0; p2 < 1<<n; p2++)
				s += c[k][p1][p2];

		printf("%lld ", s);
	}

	putchar('\n');

	return 0;
}
