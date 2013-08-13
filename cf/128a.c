#include <stdbool.h>
#include <stdio.h>

bool b[8][8] = {0};

bool dfs(int i, int j, int k) {
	if (i == 7 && j == 7)
		return true;
	
	if (k > 20)
		return false;

	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++) {
			int ii = i+dx, jj = j+dy;

			if (0 <= ii && ii < 8 && 0 <= jj && jj < 8) {
				int si = ii + k, sj = jj;
				if (0 <= si && si < 8 && 0 <= sj && sj < 8 && b[si][sj])
					continue;

				si = ii + (k+1); sj = jj;
				if (0 <= si && si < 8 && 0 <= sj && sj < 8 && b[si][sj])
					continue;

				if (dfs(ii, jj, k+1))
					return true;
			}
		}

	return false;
}

int main() {
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			char c = getchar();
			if (c == 'S')
				b[i][j] = true;
		}
		getchar();
	}

	if (dfs(0, 0, 0))
		puts("WIN");
	else
		puts("LOSE");

	return 0;
}
