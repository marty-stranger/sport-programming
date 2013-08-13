#include <stdio.h>

char a[3][4];

int win(char c) {
	for (int i = 0; i < 3; i++) {
		int j;
		for (j = 0; j < 3; j++)
			if (a[i][j] != c)
				break;
		if (j == 3)
			return 1;

		for (j = 0; j < 3; j++)
			if (a[j][i] != c)
				break;
		if (j == 3)
			return 1;
	}

	int i;
	for (i = 0; i < 3; i++)
		if (a[i][i] != c)
			break;
	if (i == 3)
		return 1;

	for (i = 0; i < 3; i++)
		if (a[i][2-i] != c)
			break;
	if (i == 3)
		return 1;

	return 0;
}

int main() {
	int c1 = 0, c2 = 0;
	for (int i = 0; i < 3; i++) {
		gets(a[i]);
		for (int j = 0; j < 3; j++)
			if (a[i][j] == 'X')
				c1++;
			else if (a[i][j] == '0')
				c2++;
	}

	int xw = win('X'), ow = win('0');
	if (c1 != c2 && c1 != c2+1 || xw && c1 != c2+1 ||
			ow && c1 != c2 || xw && ow)
		puts("illegal");
	else if (xw)
		puts("the first player won");
	else if (ow)
		puts("the second player won");
	else if (c1 + c2 == 9)
		puts("draw");
	else if (c1 == c2)
		puts("first");
	else
		puts("second");

	return 0;
}
