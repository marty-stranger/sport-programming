#include <stdio.h>
#include <string.h>

int c[1000][1000];

int main() {
	int n, i, j, c1, c2, cx1[1000], cy1[1000], cx2[1000], cy2[2000];
	char ch;

	memset(cx1, 0, sizeof(cx1));
	memset(cy1, 0, sizeof(cy1));
	memset(cx2, 0, sizeof(cx2));
	memset(cy2, 0, sizeof(cy2));
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ch = getchar();
			if (ch == 'W') {
				cx1[i]++;
				cy1[j]++;
				c[i][j] = 1;
			} else {
				cx2[i]++;
				cy2[j]++;
			}
		}
		getchar();
	}

	c1 = c2 = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if ((cx1[i] + cy1[j] + c[i][j]) % 2)
				c1++;
			if ((cx2[i] + cy2[j] + (1 - c[i][j])) % 2)
				c2++;
		}

	if (c1 < c2) {
		printf("%d\n", c1);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if ((cx1[i] + cy1[j] + c[i][j]) % 2)
					printf("%d %d\n", i + 1, j + 1);
	} else {
		printf("%d\n", c2);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if ((cx2[i] + cy2[j] + (1 - c[i][j])) % 2)
					printf("%d %d\n", i + 1, j + 1);
	}

	return 0;
}
