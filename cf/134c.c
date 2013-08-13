// NOTE seems to be O(s^2) in worst case
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, s; scanf("%d%d", &n, &s);

	int i, li = 0, a[200000], cl[200000], l[200000], ln[200000];

	memset(cl, -1, sizeof(cl));
	int mc = 0;
	for (i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		l[li] = i; ln[li] = cl[c]; cl[c] = li; li++;

		if (c > mc)
			mc = c;
	}

	int c, lvn = 0, lv1[200000], lv2[200000], tl = -1, lc[200000];
	for (i = mc; i > 0; i--)
		while (cl[i] != -1) {
			int k = i;
			int u = l[cl[i]]; cl[i] = ln[cl[i]];

			int j = i;
			while (k > 0 && j > 0) {
				while (k > 0 && cl[j] != -1) {
					int li = cl[j]; cl[j] = ln[li];
					int v = l[li];

					ln[li] = tl; lc[li] = j-1; tl = li;

					lv1[lvn] = u; lv2[lvn] = v; lvn++;
					k--;
				}

				j--;
			}

			if (k > 0) {
				puts("No");
				return 0;
			}

			while (tl != -1) {
				int li = tl; tl = ln[tl];
				int c = lc[li];
				ln[li] = cl[c]; cl[c] = li;
			}
		}

	puts("Yes");
	printf("%d\n", lvn);
	for (i = 0; i < lvn; i++)
		printf("%d %d\n", lv1[i]+1, lv2[i]+1);

	return 0;
}
