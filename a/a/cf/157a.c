#include <stdio.h>
#include <string.h>

int main() {
	int n; scanf("%d", &n);

	int a[n][n], s1[n], s2[n];
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			s1[i] += a[i][j];
			s2[j] += a[i][j];
		}

	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s2[j] > s1[i])
				c++;

	printf("%d\n", c);
	
	return 0;
}
