#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int a, int b, int c, int d) {
	if (a+b+c+d == 0)
		return 0;

	int aa[4] = {a, b, c, d};
	int i, bb[4];
	for (i = 0; i < 4; i++)
		bb[i] = abs(aa[i] - aa[(i+1) % 4]);

	return count(bb[0], bb[1], bb[2], bb[3]) + 1;
}

int main() {
	int i, a, b, c, d;
	a = 0; b = 80;
	for (i = 6; i <= 100; i++) {
		int y = 0;
		while (b <= 1000) {
			printf("b = %d\n", b);
			for (c = 1; c <= 1000; c++) {
				for (d = 1; d <= 2000; d++) {
					if (count(a, b, c, d) == i) {
						printf("%d -> %d %d %d %d\n", i, a, b, c, d);
						y = 1;
						break;
					}
				}

				if (y)
					break;
			}

			if (y)
				break;

			b++;
		}
	}

	return 0;
}
