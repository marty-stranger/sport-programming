#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int l = 0, r = n-1, ta = 0, tb = 0, ca = 0, cb = 0;

	while (l < r)
		if (ta+a[l] < tb+a[r]) {
			ta += a[l];
			l++;
			ca++;
		} else if (ta+a[l] > tb+a[r]) {
			tb += a[r];
			r--;
			cb++;
		} else {
			ta += a[l]; tb += a[r];
			l++; r--;
			ca++; cb++;
		}

	if (l == r)
		if (ta <= tb)
			ca++;
		else
			cb++;

	printf("%d %d\n", ca, cb);

	return 0;
}
