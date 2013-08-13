#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, a[1000];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	int b[1000];
	memset(b, 0, sizeof(b));

	for (i = 0; i < n; i++)
		if (!b[a[i]])
			b[a[i]] = 1;
		else
			break;

	if (i != n) {
		puts("0 0");
		return 0;
	}

	i = 0;
	while (i < n && a[i] == i)
		i++;

	int l = i;
	int x = a[i];

	while (i < n && a[i] == x - (i-l))
		i++;

	int h = i-1;

	while (i < n && a[i] == i)
		i++;

	if (i < n || l > h) {
		puts("0 0");
		return 0;
	}

	printf("%d %d\n", l+1, h+1);

	return 0;
}
