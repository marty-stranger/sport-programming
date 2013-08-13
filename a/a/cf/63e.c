#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char r[1 << 20];

int box2mask(char b[5][5]) {
	int mask = 0, i, j, k = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5-abs(2-i); j++) {
			if (b[i][j])
				mask |= 1 << k;
			k++;
		}

	return mask;
}

int go(int mask) {
	if (r[mask] != -1)
		return r[mask];
	
	// printf("mask = %d\n", mask);

	char b[5][5];
	memset(b, 0, sizeof(b));

	int i, j, k = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5-abs(2-i); j++) {
			if (mask & (1 << k))
				b[i][j] = 1;
			k++;
		}

	char bb[5][5];
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5-abs(2-i); j++) {
			memcpy(bb, b, sizeof(bb));
			int l;
			for (k = i, l = j; k < 5 && l < 5-abs(2-k) && l >= 0 && bb[k][l]; k++) {
				bb[k][l] = 0;
				if (!go(box2mask(bb)))
					return r[mask] = 1;
				if (k >= 2)
					l--;
			}

			memcpy(bb, b, sizeof(bb));
			for (k = i, l = j; k < 5 && l < 5-abs(2-k) && bb[k][l]; k++) {
				bb[k][l] = 0;
				if (!go(box2mask(bb)))
					return r[mask] = 1;
				if (k < 2)
					l++;
			}

			memcpy(bb, b, sizeof(bb));
			for (k = j; k < 5-abs(2-i) && bb[i][k]; k++) {
				bb[i][k] = 0;
				if (!go(box2mask(bb)))
					return r[mask] = 1;
			}
		}
	
	return r[mask] = 0;
}

int main() {
	int i, mask = 0, j = 0;
	for (i = 0; i < 5; i++) {
		char s[100];
		gets(s);

		char *t = s;
		while (*t != '\0') {
			if (*t == 'O')
				mask |= (1 << j);
			if (*t == 'O' || *t == '.')
				j++;
			t++;
		}

	}
	
	if (j != 19)
		exit(1);

	memset(r, -1, sizeof(r));

	if (go(mask))
		puts("Karlsson");
	else
		puts("Lillebror");

	return 0;
}
