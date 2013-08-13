#include <stdio.h>
#include <string.h>

int main() {
	int n, t; scanf("%d%d", &n, &t);

	long long c[n][t+1][t][4][4];
	memset(c, 0, sizeof(c));
	for (int y1 = 0; y1 < 4; y1++)
		for (int y2 = 0; y2 < 4; y2++)
			if (y1 != y2)
				c[1][0][0][y1][y2] = 1;

	for (int i = 2; i < n; i++)
		for (int t1 = 0; t1 <= t; t1++)
			for (int t2 = 0; t2 <= t-1; t2++)
				for (int y2 = 0; y2 < 4; y2++)
					for (int y3 = 0; y3 < 4; y3++) {
						long long s = 0;
						for (int y1 = 0; y1 < 4; y1++)
							if (y1 < y2 && y2 > y3 && t1 > 0) {
								if (t1 > 0)
									s += c[i-1][t1-1][t2][y1][y2];
							} else if (y1 > y2 && y2 < y3) {
								if (t2 > 0)
									s += c[i-1][t1][t2-1][y1][y2];
							} else if (y1 != y2 && y2 != y3)
								s += c[i-1][t1][t2][y1][y2];

						c[i][t1][t2][y2][y3] = s;
						// fprintf(stderr, "%d %d %d %d %d -> %d\n", i, t1, t2, y2, y3, s);
					}

	long long s = 0;
	for (int y1 = 0; y1 < 4; y1++)
		for (int y2 = 0; y2 < 4; y2++)
			if (y1 != y2)
				s += c[n-1][t][t-1][y1][y2];

	printf("%I64d\n", s);

	return 0;
}
