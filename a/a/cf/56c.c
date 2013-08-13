#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[1001];
	gets(a);

	int n = strlen(a);

	int st = 0;

	char *na, *ns[10000];
	int i, nn = 0, nsn = 0, c = 0;
	for (i = 0; i < n; i++)
		if ('A' <= a[i] && a[i] <= 'Z') {
			na = malloc(11); nn = 0;
			while ('A' <= a[i] && a[i] <= 'Z')
				na[nn++] = a[i++];
			i--;
			na[nn] = '\0';

			int j;
			for (j = 0; j < nsn; j++)
				if (!strcmp(ns[j], na))
					c++;
			ns[nsn++] = na;
		} else if (a[i] == ':')
			;
		else if (a[i] == '.')
			nsn--;
		else (a[i] == ',')
			;

	printf("%d\n", c);

	return 0;
}
