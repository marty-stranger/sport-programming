#include <stdio.h>
#include <string.h>

int rs[101][101];

int go(int a, int b) {
	// printf("%d %d\n", a, b);
	if (a == 0 || b == 0)
		return 0;

	if (a > b) {
		int t = a; a = b; b = t;
	}

	if (rs[a][b] != -1)
		return rs[a][b];

	int c = a;
	while (b-c >= 0) {
		// printf("a = %d b = %d c = %d b-c = %d\n", a, b, c, b-c);
		if (!go(a, b-c)) {
			rs[a][b] = 1;
			return 1;
		}

		c *= a;
		if (a == 1)
			break;
	}

	if (!go(a, b%a)) {
		rs[a][b] = 1;
		return 1;
	}

	rs[a][b] = 0;
	return 0;
}

int main() {
	for (int a = 0; a <= 21; a++)
		for (int b = 0; b <= 21; b++) {
			memset(rs, -1, sizeof(rs));
			printf("a = %d b = %d -> ", a, b);
			if (go(a, b))
				puts("First");
			else
				puts("Second");
		}

	return 0;
}
