#include <stdio.h>
#include <string.h>

int main() {
	int m, n; scanf("%d%d\n", &m, &n);

	int i, j, a[1000], b[1000], ss[1000][1001];
	memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	for (i = 0; i < m; i++) {
		char s[1001];
		gets(s);
		for (j = 0; j < n; j++) {
			ss[i][j] = s[j];
			if (s[j] == '*')
				a[i]++, b[j]++;
		}
	}


	long long c = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (ss[i][j] == '*' && a[i] > 0 && b[j] > 0)
				c += (a[i]-1)*(b[j]-1);

	printf("%I64d\n", c);

	return 0;
}
