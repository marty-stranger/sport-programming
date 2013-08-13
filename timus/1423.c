#include <stdio.h>

char p[250001], s[250001];

int main() {
	int n; scanf("%d%s%s", &n, p, s);

	int l[250001] = {0}, k = 0;
	for (int i = 1; i < n; i++) {
		while (k != 0 && p[k] != p[i])
			k = l[k];
		if (p[k] == p[i])
			k++;
		l[i + 1] = k;
	}

	k = 0;
	for (int i = 0; i < 2*n-1; i++) {
		while (k != 0 && p[k] != s[i % n])
			k = l[k];
		
		if (p[k] == s[i % n])
			k++;

		if (k == n) {
			printf("%d\n", i - n + 1);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}
