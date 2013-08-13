#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int i;
	char names[100][30];
	int c[100][3];
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) {
		int k;
		scanf("%d%s\n", &k, names[i]);

		int j;
		for (j = 0; j < k; j++) {
			char s[100];
			gets(s);
			strcpy(s + 2, s + 3);
			strcpy(s + 4, s + 5);
			// puts(s);

			int ii;
			for (ii = 1; ii < 6; ii++)
				if (s[ii] != s[ii-1])
					break;

			if (ii == 6) {
				c[i][0]++;
				continue;
			}

			for (ii = 1; ii < 6; ii++)
				if (s[ii] >= s[ii-1])
					break;

			if (ii == 6) {
				c[i][1]++;
				continue;
			}

			c[i][2]++;
		}
	}

	int m[3];
	memset(m, 0, sizeof(m));
	int j;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++) {
			// printf("i = %d j = %d c = %d\n", i+1, j+1, c[i][j]);
			if (c[i][j] > m[j])
				m[j] = c[i][j];
		}

	for (j = 0; j < 3; j++) {
		if (j == 0)
			printf("If you want to call a taxi, you should call:");
		else if (j == 1)
			printf("If you want to order a pizza, you should call:");
		else
			printf("If you want to go to a cafe with a wonderful girl, you should call:");

		int f = 1;
		for (i = 0; i < n; i++)
			if (m[j] == c[i][j])
				if (f) {
					printf(" %s", names[i]);
					f = 0;
				} else
					printf(", %s", names[i]);
		puts(".");
	}	

	return 0;
}
