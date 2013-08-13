#include <stdio.h>

int main() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);

	int hs[2000];
	for (int i = 0; i < n; i++)
		scanf("%d", &hs[i]);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (hs[j] < hs[i]) {
				int t = hs[j]; hs[j] = hs[i]; hs[i] = t;
			}

	b--;
	printf("%d\n", hs[b+1]-hs[b]);

	return 0;
}
