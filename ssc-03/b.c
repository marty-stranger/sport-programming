#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[100];	
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i]) {
				int t = a[i]; a[i] = a[j]; a[j] = t;
			}

	int l = 0, r = n-1, c = 0;
	while (l != r)
		if (a[l] <= r-l) {
			a[r-1] += a[r] + 1;
			a[l]--;
			if (a[l] == 0)
				l++;
			r--;
			c++;
		} else {
			a[r-1] += a[r-1];
			r--;
			c++;
		}

	printf("%d\n", c);
	
	return 0;
}
