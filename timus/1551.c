#include <stdio.h>
#include <string.h>

int main() {
	int n, m, mm, i, j, c, b[1024];
	char s[1024][31];

	scanf("%d", &n);
	m = 1 << n;

	for (i = 0; i < m; i++)
		scanf("%*s%s", s[i]);

	mm = n;

	memset(b, 0, sizeof(b));
	for (i = 0; i < m; i++)
		if (!b[i])  {
			c = 0;
			for (j = 0; j < m; j++)
				if (!strcmp(s[i], s[j])) {
					b[j] = 1;
					c++;
				}

			j = 0;
			while (j < n && c <= (1 << (n - j - 1)))
				j++;

			if (j < mm)
				mm = j;
		}

	printf("%d", mm);

	return 0;
}
