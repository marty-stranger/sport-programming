#include <stdbool.h>
#include <stdio.h>

typedef struct { int c; bool b; } ans;

ans cs[16][5001] = {0};

void backtrack(int k, int i) {
	if (cs[k][i].b) {
		if (i != 0)
			backtrack(k - 1, i - 1);

		putchar('1');

	} else {
		if (i != 0)
			backtrack(k, i - 1);

		putchar('0');
	}
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	char s[5001];
	int c[5001] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			c[j] += (s[j] == '1');
	}

	cs[0][0] = (ans){c[0], false};
	for (int i = 1; i < m; i++)
		cs[0][i] = (ans){cs[0][i - 1].c + c[i], false};

	const int inf = 1e9;

	for (int k = 1; k <= 15; k++) {
		if (k == 1) {
			cs[k][0] = (ans){n - c[0], true};
		} else {
			cs[k][0] = (ans){inf, false};
		}

		for (int i = 1; i < m; i++) {
			ans ans1 = (ans){cs[k][i - 1].c + c[i], false};
			ans ans2 = (ans){cs[k - 1][i - 1].c + (n - c[i]), true};

			if (ans1.c < ans2.c)
				cs[k][i] = ans1;
			else
				cs[k][i] = ans2;

			// printf("k = %d, i = %d -> %d\n", k, i, cs[k][i].c);
		}

	}

	int mi = 8;
	for (int i = 9; i <= 15; i++)
		if (cs[i][m - 1].c < cs[mi][m - 1].c)
			mi = i;

	// printf("mi = %d\n", mi);

	backtrack(mi, m-1);

	return 0;
}
