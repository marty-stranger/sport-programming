#include <stdio.h>

int main() {
	int n, m, k, x, y, z, xm, ym, zm, xmm, ymm, zmm;
	char c;
	long long p;

	scanf("%d%d%d\n", &n, &m, &k);
	
	x = y = z = 0;
	xm = ym = zm = xmm = ymm = zmm = 0;

	c = getchar();
	while (c != '\n' && c != '\r' && c != EOF) {
		if (c == 'u')
			z++;
		else if (c == 'd')
			z--;
		else if (c == 'l')
			y--;
		else if (c == 'r')
			y++;
		else if (c == 'f')
			x--;
		else if (c == 'b')
			x++;
		else if (c == ' ')
			;

		if (x > xm)
			xm = x;
		if (y > ym)
			ym = y;
		if (z > zm)
			zm = z;
		if (x < xmm)
			xmm = x;
		if (y < ymm)
			ymm = y;
		if (z < zmm)
			zmm = z;

		c = getchar();
	}

	p = 1;
	if (n - ym + ymm > 0)
		p *= n - ym + ymm;
	if (m - zm + zmm > 0)
		p *= m - zm + zmm;
	if (k - xm + xmm > 0)
		p *= k - xm + xmm;

	printf("%I64d", p);

	return 0;
}
