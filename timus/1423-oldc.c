/* ok */
#include <stdio.h>

char p[250001], s[250000];
int l[250001];

int main() {
	int n, m, i, ii, k;

	scanf("%d\n", &n);
	gets(p); gets(s);

	l[1] = k = 0;
	for (i = 1; i < n; i++) {
		while (k != 0 && p[k] != p[i])
			k = l[k];
		if (p[k] == p[i])
			k++;
		l[i + 1] = k;
	}

	k = 0; m = 2*n - 1;
	for (i = 0; i < m && k != n; i++) {
		ii = i % n;
		while (k != 0 && p[k] != s[ii])
			k = l[k];
		if (p[k] == s[ii])
			k++;
	}

	if (k == n)
		printf("%d", i - n);
	else
		puts("-1");
	
	return 0;
}
