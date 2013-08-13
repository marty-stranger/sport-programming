#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[100][100][100][100];

int count(int a, int b, int c, int d) {
	// printf("%d %d %d %d\n", a, b, c, d);
	if (a+b+c+d == 0)
		return 0;

	/* if (a < 100 && b < 100 && c < 100 && d < 100)
		if (m[a][b][c][d] != -1)
			return m[a][b][c][d]; */

	int aa[4] = {a, b, c, d};
	int i, bb[4];
	for (i = 0; i < 4; i++)
		bb[i] = abs(aa[i] - aa[(i+1) % 4]);

	int cc = count(bb[0], bb[1], bb[2], bb[3]) + 1;
	/* if (a < 100 && b < 100 && c < 100 && d < 100)
		m[a][b][c][d] = cc; */

	return cc;
}

int main() {
	/* count(1, 1, 1, 1);
	return 0;
	// count(0, 24, 68, 149);
	count(0, 81, 230, 504);
	puts("");
	count(0, 1, 2, 3);
	return 0; */

	char *mm[10000];
	memset(mm, 0, sizeof(mm));

	memset(m, -1, sizeof(m));
	m[0][0][0][0] = 0;

	int a, b, c, d;
	for (a = 0; a < 2; a++)
		for (b = 0; b < 100; b++)
			for (c = 0; c < 1000; c++)
				for (d = 0; d < 1000; d++) {
					int cc = count(a, b, c, d);
					if (mm[cc] == NULL) {
						mm[cc] = (char*) malloc(100);
						sprintf(mm[cc], "%d %d %d %d", a, b, c, d);
						printf("%d -> %d %d %d %d\n", cc, a, b, c, d);
					}
				}

	/* int i;
	for (i = 1; i <= 100; i++)
		printf("%d %s\n", i, mm[i]); */

	return 0;
}
