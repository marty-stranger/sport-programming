#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen(argv[1], "r", stdin);

	bool g[300][300] = {0};
	int n; scanf("%d", &n);

	for (;;) {
		int i, j;
		if (scanf("%d%d", &i, &j) == EOF)
			break;

		i--; j--;

		if (i != j)
			g[j][i] = g[i][j] = true;
	}

	freopen(argv[2], "r", stdin);

	int m; scanf("%d", &m);

	int c = 0;

	bool b[300] = {0};
	for (;;) {
		int i, j; 
		if (scanf("%d%d", &i, &j) == EOF)
			break;
		i--; j--;
		
		if (b[i]) {
			printf("duplicate %d\n", i+1);
			return 1;
		}

		if (b[j]) {
			printf("duplicate %d\n", j+1);
			return 1;
		}

		b[i] = b[j] = true;

		if (!g[i][j]) {
			printf("non-existent edge %d %d\n", i+1, j+1);
			return 1;
		}

		c++;
	}

	if (m != 2*c) {
		printf("first number and lines count mismatch\n");
		return 1;
	}

	return 0;
}
