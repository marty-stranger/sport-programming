#include <stdio.h>

int main() {
	char a[3][4];

	for (int i = 0; i < 3; i++)
		gets(a[i]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[2-i][2-j] != a[i][j]) {
				puts("NO");
				return 0;
			}

	puts("YES");

	return 0;
}
