#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

FILE *f;

int rand() {
	return fgetc(f)*256*256 + fgetc(f)*256 + fgetc(f);
}

int main(int argc, char *argv[]) {
	f = fopen("/dev/urandom", "r");

	int n = atoi(argv[1]);

	printf("%d\n", n);

	int m;
	if (argv[2] == NULL)
		m = rand() % (n*(n-1) / 2 + 1);
	else
		m = atoi(argv[2]);

	fprintf(stderr, "n = %d m = %d ", n, m);

	bool g[300][300] = {0};
	for (int i = 0; i < m; i++)
		for (;;) {
			int u = rand() % n, v = rand() % n;

			if (u != v && !g[u][v]) {
				printf("%d %d\n", u+1, v+1);
				g[v][u] = g[u][v] = true;
				break;
			}
		}

	fclose(f);

	return 0;
}
