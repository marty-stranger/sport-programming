#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, p = b[l + rand() % (r-l+1)];
		while (i <= j)
			if (b[i] < p)
				i++;
			else if (b[j] > p)
				j--;
			else {
				int t = b[i]; b[i] = b[j]; b[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	int n, c1, c2; scanf("%d%d%d", &n, &c1, &c2);

	int i, a[100000];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	
	memcpy(b, a, sizeof(b));
	sort(0, n-1);

	int cc1[5], cc2[5], s1[100000], s2[100000], s[100000];
	memset(cc1, 0, sizeof(cc1));
	memset(cc2, 0, sizeof(cc2));

	for (i = c2; i < n; i++)
		cc1[b[i]]++;

	for (i = 0; i < c1; i++)
		cc2[b[i]]++;

	for (i = 0; i < n; i++)
		if (cc1[a[i]] > 0) {
			cc1[a[i]]--;
			s1[i] = 1;
		} else
			s1[i] = 2;

	for (i = 0; i < n; i++)
		if (cc2[a[i]] > 0) {
			cc2[a[i]]--;
			s2[i] = 1;
		} else
			s2[i] = 2;

	if (c1 == c2) {
		for (i = 0; i < c1; i++)
			s[i] = 1;
		for (i = c1; i < n; i++)
			s[i] = 2;
	} else if (c1 < c2)
		memcpy(s, s1, sizeof(s));
	else
		memcpy(s, s2, sizeof(s));

	for (i = 0; i < n; i++) {
		if (i != 0)
			putchar(' ');
		printf("%d", s[i]);
	}
	putchar('\n');

	return 0;
}
