#include <stdio.h>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	char s[100][101];
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

	int mm[100];
	for (i = 0; i < m; i++) {
		mm[i] = '0';
		for (j = 0; j < n; j++) {
			if (mm[i] == '0' || s[j][i] > mm[i])
				mm[i] = s[j][i];
		}
	}

	int c = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			if (s[i][j] == mm[j])
				break;

		if (j != m)
			c++;
	}

	printf("%d\n", c);

	return 0;
}
