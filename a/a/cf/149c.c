#include <stdio.h>

int a[100000], p[100000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, pp = p[l + rand() % (r-l)];
	while (i <= j)
		if (a[p[i]] < a[pp])
			i++;
		else if (a[pp] < a[p[j]])
			j--;
		else {
			int t = p[i]; p[i] = p[j]; p[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n; scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
	}

	sort(0, n-1);

	printf("%d\n", (n+1)/2);
	for (i = 0; i < n; i += 2)
		printf("%d ", p[i]+1);
	putchar('\n');

	printf("%d\n", n/2);
	for (i = 1; i < n; i += 2)
		printf("%d ", p[i]+1);
	putchar('\n');

	return 0;
}
