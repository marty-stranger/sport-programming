#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d\n", &n);

	int i, c = 0;
	for (i = 0; i < n; i++) {
		char s[200];
		gets(s);

		if (isdigit(s[0])) {
			int a;
			sscanf(s, "%d", &a);
			if (a < 18)
				c++;
		} else {
			const char* list[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

			int j;
			for (j = 0; j < 11; j++)
				if (strcmp(s, list[j]) == 0)
					break;

			if (j != 11)
				c++;
		}
	}

	printf("%d\n", c);

	return 0;
}
