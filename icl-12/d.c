// int64 is not enough
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

typedef long long int64;

int64 abs64(int64 a) {
	return a > 0 ? a : -a;
}

int64 det(int64 a11, int64 a12, int64 a13, int64 a21, int64 a22, int64 a23, int64 a31, int64 a32, int64 a33) {
	return a11*a22*a33 + a12*a23*a31 - a13*a22*a31 -
		a11*a23*a32 - a12*a21*a33 + a13*a21*a32;
}

int count(int64 a, int64 b, int64 c, int64 d) {
	// printf("%d %d %d %d\n", a, b, c, d);
	if (a+b+c+d == 0)
		return 0;

	int64 aa[4] = {a, b, c, d}, bb[4];
	int i;
	for (i = 0; i < 4; i++)
		bb[i] = abs64(aa[i] - aa[(i+1) % 4]);

	return count(bb[0], bb[1], bb[2], bb[3]) + 1;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	if (n == 1) {
		puts("1 1 1 1");
		return 0;
	}

	int64 a[4][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	int i;
	for (i = 0; i < n-2; i++) {
		int64 b[4][3];

		int j;
		for (j = 0; j < 3; j++) {
			b[0][j] = a[1][j] - a[0][j];
			b[1][j] = a[2][j] - a[1][j];
			b[2][j] = a[3][j] - a[2][j];
			b[3][j] = a[3][j] - a[0][j];
		}

		memcpy(a, b, sizeof(a));
		/* printf("(%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld)\n", 
				a[0][0], a[0][1], a[0][2],
				a[1][0], a[1][1], a[1][2],
				a[2][0], a[2][1], a[2][2],
				a[3][0], a[3][1], a[3][2]);
		puts(""); */
	}

	int64 b[4][3];
	int j;
	for (j = 0; j < 3; j++) {
		b[0][j] = a[1][j] - a[0][j];
		b[1][j] = a[1][j] - a[2][j];
		b[2][j] = a[3][j] - a[2][j];
		b[3][j] = a[3][j] - a[0][j];
	}
	memcpy(a, b, sizeof(a));
	/* printf("(%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld)\n", 
			a[0][0], a[0][1], a[0][2],
			a[1][0], a[1][1], a[1][2],
			a[2][0], a[2][1], a[2][2],
			a[3][0], a[3][1], a[3][2]);
	puts(""); */

	memcpy(b, a, sizeof(b));
	int64 d = det(a[0][0], a[0][1], a[0][2], a[1][0], a[1][1], a[1][2], a[2][0], a[2][1], a[2][2]);
	printf("d = %lld\n", d);

	int64 s[3];
	j = 0;
	while (j < 50) {
		for (i = 0; i < 3; i++) {
			memcpy(a, b, sizeof(b));

			a[0][i] = a[1][i] = a[2][i] = 1LL << j;
			int64 dd = det(a[0][0], a[0][1], a[0][2], a[1][0], a[1][1], a[1][2], a[2][0], a[2][1], a[2][2]);
			// printf("dd = %lld\n", dd);
			/* printf("(%lld %lld %lld) (%lld %lld %lld) (%lld %lld %lld)\n", 
					a[0][0], a[0][1], a[0][2],
					a[1][0], a[1][1], a[1][2],
					a[2][0], a[2][1], a[2][2]); */
			s[i] = dd / d;
			// printf("%lld\n", dd / d);
		}

		// printf("j = %d -> %d %d %d\n", j, s[0], s[1], s[2]);

		if (count(0, s[0], s[1], s[2]) == n)
			break;
		
		j++;
	}

	putchar('0');
	for (i = 0; i < 3; i++)
		printf(" %d", s[i]);
	putchar('\n');

	return 0;
}
