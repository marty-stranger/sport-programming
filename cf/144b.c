#include <stdio.h>
#include <string.h>

int main() {
	int x1, y1, x2, y2;

	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	if (x1 > x2) {
		int t = x1; x1 = x2; x2 = t;
	}

	if (y1 > y2) {
		int t = y1; y1 = y2; y2 = t;
	}

	int n;
	scanf("%d", &n);

	int i;
	int b[4][2000];
	memset(b, 0, sizeof(b));
		
	for (i = 0; i < n; i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);

		int xx, yy;
		for (xx = x1; xx < x2; xx++)
			if ((xx - x)*(xx - x) + (y1 - y)*(y1 - y) <= r*r)
				b[0][xx - x1] = 1;
		for (yy = y1; yy < y2; yy++)
			if ((x2 - x)*(x2 - x) + (yy - y)*(yy - y) <= r*r)
				b[1][yy - y1] = 1;
		for (xx = x2; xx > x1; xx--)
			if ((xx - x)*(xx - x) + (y2 - y)*(y2 - y) <= r*r)
				b[2][xx-x1-1] = 1;
		for (yy = y2; yy > y1; yy--)
			if ((x1 - x)*(x1 - x) + (yy - y)*(yy - y) <= r*r)
				b[3][yy-y1-1] = 1;
	}

	int xx, yy, c = 0;
	for (xx = x1; xx < x2; xx++)
		c += 1 - b[0][xx - x1];
	for (yy = y1; yy < y2; yy++)
		c += 1 - b[1][yy - y1];
	for (xx = x2; xx > x1; xx--)
		c += 1 - b[2][xx-x1-1];
	for (yy = y2; yy > y1; yy--)
		c += 1 - b[3][yy-y1-1];

	printf("%d\n", c);

	return 0;
}
