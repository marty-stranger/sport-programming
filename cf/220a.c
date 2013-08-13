#include <stdio.h>
#include <stdlib.h>

int a[100000], b[100000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, p = a[l + rand() % (r - l)];

	while (i <= j)
		if (a[i] < p)
			i++;
		else if (a[j] > p)
			j--;
		else {
			int t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(0, n-1);

	int c = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			c++;

	if (c == 2 || c == 0)
		puts("YES");
	else
		puts("NO");

	return 0;
}
