#include <stdio.h>

int main() {
	int n, d, i, j, m, mm, mj, mmi, mmj, x[200000], w[200000];

	scanf("%d%d", &n, &d);
	for (i = 0; i < n; i++)
		scanf("%d%d", &x[i], &w[i]);

	m = -1; j = 0; mm = -1;
	for (i = 0; i < n; i++) {
		while (x[j] + d <= x[i]) {
			if (w[j] > m) {
				m = w[j];
				mj = j;
			}
			j++;
		}

		if (m != -1 && w[i] + m > mm) {
			mm = w[i] + m;
			mmi = i;
			mmj = mj;
		}
	}

	if (mm == -1)
		printf("-1 -1\n");
	else
		printf("%d %d", mmi + 1, mmj + 1);

	return 0;
}
