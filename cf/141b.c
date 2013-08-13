#include <stdio.h>

int main() {
	int a, x, y;
	scanf("%d%d%d", &a, &x, &y);

	if (y % a == 0) {
		puts("-1");
		return 0;
	}

	int t = y / a + 1;

	int r;
	if (t == 1 || t == 2)
		if (-a < 2*x && 2*x < a)
			r = t;
		else
			r = -1;
	else if (t % 2 == 1) {
		int j = t + (t - 1) / 2 - 1;
		if (-a < x && x < 0)
			r = j;
		else if (0 < x && x < a)
			r = j + 1;
		else
			r = -1;
	} else if (t % 2 == 0) {
		int j = t + (t - 2) / 2;
		if (-a < 2*x && 2*x < a)
			r = j;
	}

	printf("%d\n", r);

	return 0;
}
