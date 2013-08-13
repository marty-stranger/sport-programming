#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reqs[100000][33];
char *names[100000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	char *p = names[m];

	while (i <= j)
		if (strcmp(names[i], p) < 0)
			i++;
		else if (strcmp(p, names[j]) < 0)
			j--;
		else {
			char *t = names[i]; names[i] = names[j]; names[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", reqs[i]);
		names[i] = reqs[i];
	}

	sort(0, n-1);

	int m = 0;
	for (int i = 0; i < n; i++)
		if (i == 0 || strcmp(names[i], names[i-1]) != 0) {
			names[m] = names[i];
			m++;
		}

	int c[m];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		int l = 0, r = m - 1;
		while (l < r) {
			int m = (l+r)/2;
			if (strcmp(reqs[i], names[m]) <= 0)
				r = m;
			else
				l = m+1;
		}

		if (c[l] == 0)
			puts("OK");
		else
			printf("%s%d\n", reqs[i], c[l]);
		c[l]++;
	}

	return 0;
}
