#include <stdio.h>
#include <string.h>

int main() {
	int n, m; char pc; scanf("%d%d %c", &n, &m, &pc);

	char a[100][101];
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	char b[200];
	memset(b, 0, sizeof(b));
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == pc)
				for (int di = 0; di < 4; di++) {
					int ii = i + (const int[4]){1, 0, -1, 0}[di],
					    jj = j + (const int[4]){0, 1, 0, -1}[di];

					if (0 <= ii && ii < n && 0 <= jj && jj < m)
						if (a[ii][jj] != '.' && a[ii][jj] != pc) {
							if (!b[a[ii][jj]]) {
								b[a[ii][jj]] = 1;
								c++;
							}
						}
				}

	printf("%d\n", c);

	return 0;
}
