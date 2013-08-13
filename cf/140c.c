#include <stdio.h>
#include <stdlib.h>

int a[100000], c[100000], hn, h[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, p = a[l + rand() % (r - l)];
		while (i <= j)
			if (a[i] < p)
				i++;
			else if (a[j] > p)
				j--;
			else {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

void down(int i) {
	int t = h[i];
	while (2*i+1 < hn && c[h[2*i+1]] > c[t] || 2*i+2 < hn && c[h[2*i+2]] > c[t])
		if (2*i+2 < hn && c[h[2*i+2]] > c[h[2*i+1]]) {
			h[i] = h[2*i+2];
			i = 2*i+2;
		} else {
			h[i] = h[2*i+1];
			i = 2*i+1;
		}
	h[i] = t;
}

void up(int i) {
	int t = h[i];
	while (i != 0 && c[t] > c[h[(i-1)/2]]) {
		h[i] = h[(i-1)/2];
		i = (i-1)/2;
	}
	h[i] = t;
}

int main() {
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n - 1);

	c[0] = 1;
	int j = 0;
	for (i = 1; i < n; i++)
		if (a[i] == a[j]) {
			c[j]++;
		} else {
			j++;
			a[j] = a[i];
			c[j] = 1;
		}

	n = j + 1;

	hn = n;
	for (i = 0; i < n; i++)
		h[i] = i;

	for (i = hn / 2; i >= 0; i--)
		down(i);

	int sn = 0, s[100000 / 3 + 1][3];
	while (hn >= 3) {
		for (i = 0; i < 3; i++) {
			j = h[0]; h[0] = h[hn - 1]; hn--; down(0);
			s[sn][i] = j;
			c[j]--;
		}

		for (i = 0; i < 3; i++) {
			j = s[sn][i];
			if (c[j] > 0) {
				h[hn] = j; hn++; up(hn - 1);
			}
			s[sn][i] = a[j];
		}
		sn++;
	}

	printf("%d\n", sn);
	for (i = 0; i < sn; i++) {
		if (s[i][0] < s[i][1]) {
			int t = s[i][0]; s[i][0] = s[i][1]; s[i][1] = t;
		}
		if (s[i][0] < s[i][2]) {
			int t = s[i][0]; s[i][0] = s[i][2]; s[i][2] = t;
		}
		if (s[i][1] < s[i][2]) {
			int t = s[i][1]; s[i][1] = s[i][2]; s[i][2] = t;
		}
		
		printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
	}

	return 0;
}
