#include <stdbool.h>
#include <stdio.h>

int main() {
	bool g[5][5] = {0};

	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		g[u][v] = g[v][u] = true;
	}

	bool f1 = false, f2 = false;
	for (int i = 0; i < 1<<5; i++) {
		int c = 0;
		for (int j = 0; j < 5; j++)
			if ((i & (1<<j)) != 0)
				c++;

		if (c != 3)
			continue;

		bool f = true;
		for (int u = 0; u < 5; u++) if ((i & (1<<u)) != 0)
			for (int v = 0; v < 5; v++) if ((i & (1<<v)) != 0)
				if (u != v && !g[u][v])
					f = false;

		if (f)
			f1 = true;

		f = true;
		for (int u = 0; u < 5; u++) if ((i & (1<<u)) != 0)
			for (int v = 0; v < 5; v++) if ((i & (1<<v)) != 0)
				if (u != v && g[u][v])
					f = false;

		if (f)
			f2 = true;
	}

	if (f1 || f2)
		puts("WIN");
	else
		puts("FAIL");

	return 0;
}
