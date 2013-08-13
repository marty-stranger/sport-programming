#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, a[100];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int m = 0;
	for (i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	for (i = 0; i < n; i++)
		if (a[i] == m)
			break;

	int c = i;
	int j = i;

	m = 101;
	for (i = 0; i < n; i++)
		if (a[i] < m)
			m = a[i];

	for (i = n-1; i >= 0; i--)
		if (a[i] == m)
			break;

	c += (n-1 - i);

	if (j > i)
		c--;

	printf("%d\n", c);
}
