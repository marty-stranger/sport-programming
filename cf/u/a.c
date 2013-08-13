#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100000], b[100000];

void sort(int *a, int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	int p = a[m];

	while (i <= j)
		if (a[i] < p)
			i++;
		else if (a[j] > p)
			j--;
		else {
			int t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	sort(a, i, r); sort(a, l, j);
}

int main() {
	int n, m, x, y; scanf("%d%d%d%d", &n, &m, &x, &y);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, 0, n-1);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, 0, m-1);

	int p[n];
	memset(p, -1, sizeof(p));

	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] - x <= b[j] && b[j] <= a[i] + y) {
			p[i] = j;
			i++; j++; k++;
		} else if (b[j] < a[i]-x)
			j++;
		else
			i++;
	}

	printf("%d\n", k);
	for (int i = 0; i < n; i++)
		if (p[i] != -1)
			printf("%d %d\n", i+1, p[i]+1);

	return 0;
}
