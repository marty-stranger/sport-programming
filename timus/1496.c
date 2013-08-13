#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, f;
	char s[100][31], b[100];

	scanf("%d", &n);

	memset(b, 0, sizeof(b));
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

	for (i = 0; i < n; i++) 
		if (!b[i]) {
			f = 0;
			for (j = i+1; j < n; j++)
				if (!strcmp(s[i], s[j])) {
					b[j] = 1;
					f = 1;
				}

			if (f)
				puts(s[i]);
		}

	return 0;
}

