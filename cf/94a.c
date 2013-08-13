#include <stdio.h>
#include <string.h>

int main() {
	char a[81]; scanf("%s", a);

	int r[8];

	for (int i = 0; i < 10; i++) {
		char s[11]; scanf("%s", s);

		for (int j = 0; j < 80; j += 10)
			if (strncmp(a+j, s, 10) == 0)
				r[j/10] = i;
	}

	for (int i = 0; i < 8; i++)
		printf("%d", r[i]);
	putchar('\n');

	return 0;
}
