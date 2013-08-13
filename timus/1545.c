#include <stdio.h>

int main() {
	int n, i;
	char s[1000][3], ss[2];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

	scanf("%s", ss);

	for (i = 0; i < n; i++)
		if (s[i][0] == ss[0])
			printf("%s\n", s[i]);

	return 0;
}
