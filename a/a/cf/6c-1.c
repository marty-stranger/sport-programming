#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int l = 0, r = n-1, ta = 0, tb = 0;

	while (l <= r)
		if (ta <= tb)
			ta += a[l], l++;
		else
			tb += a[r], r--;

	printf("%d %d\n", l, n-l);

	return 0;
}
