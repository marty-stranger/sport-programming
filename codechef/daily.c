#include <stdio.h>
#include <string.h>

int main() {
	int x, n; scanf("%d%d", &x, &n);

	int cc[7][7] = {{0}};
	cc[0][0] = 1;
	for (int i = 1; i <= 6; i++) {
		cc[i][0] = 1;
		for (int j = 1; j <= i; j++)
			cc[i][j] = cc[i-1][j-1] + cc[i-1][j];
	}


	int c = 0;
	for (int i = 0; i < n; i++) {
		char s[55]; scanf("%s", s);

		for (int j = 0; j < 54; j++)
			s[j] -= '0';

		int i1 = 0, i2 = 54;
		for (int j = 0; j < 9; j++) {
			int ss = 6-(s[i1]+s[i1+1]+s[i1+2]+s[i1+3]+s[i2-1]+s[i2-2]);
			c += cc[ss][x];
			i1 += 4;
			i2 -= 2;
		}
	}

	printf("%d\n", c);

	return 0;
}
