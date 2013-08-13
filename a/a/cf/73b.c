#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s[100000], *ss[100000];
int a[100000], aa[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand() % (r-l+1);
		char *ps = s[m]; int pa = a[m];
		while (i <= j)
			if (a[i] > pa || a[i] == pa && strcmp(s[i], ps) < 0)
				i++;
			else if (pa > a[j] || pa == a[j] && strcmp(ps, s[j]) < 0)
				j--;
			else {
				char *ts = s[i]; s[i] = s[j]; s[j] = ts;
				int ta = a[i]; a[i] = a[j]; a[j] = ta;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int b[100000];

void sortb(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand() % (r-l+1), p = b[m];
		while (i <= j)
			if (b[i] < p)
				i++;
			else if (b[j] > p)
				j--;
			else {
				int t = b[i]; b[i] = b[j]; b[j] = t;
				i++; j--;
			}

		sortb(i, r); sortb(l, j);
	}
}



int main() {
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		s[i] = (char*) malloc(21);
		scanf("%s%d", s[i], &a[i]);
	}

	sort(0, n-1);

	memcpy(ss, s, sizeof(s));
	memcpy(aa, a, sizeof(a));

	int m;
	scanf("%d", &m);

	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sortb(0, m-1);

	char v[21];
	scanf("%s", v);

	for (i = 0; i < n; i++)
		if (strcmp(s[i], v) == 0)
			break;
	int vi = i;

	if (m != 0) {
		int c[1000000];
		memset(c, 0, sizeof(c));

		a[vi] += b[m-1];
		c[vi] = 1;

		i = 0; int j = 0;
		while (i < n && j < m-1) {
			if (i != vi && a[vi] > a[i] + b[j] || a[vi] == a[i] + b[j] && strcmp(s[vi], s[i]) < 0) {
				a[i] += b[j];
				c[i] = 1;
				j++;
			}
			i++;
		}

		for (i = 0; i < n-1 && j < m-1; i++)
			if (!c[i]) {
				a[i] += b[j];
				j++;
			}
	}

	sort(0, n - 1);

	for (i = 0; i < n; i++)
		if (strcmp(s[i], v) == 0)
			break;

	int h = i;

	memcpy(s, ss, sizeof(s));
	memcpy(a, aa, sizeof(a));

	if (m != 0) {
		if (m == n)
			a[vi] += b[0];

		i = n-1; int j = m-1;
		while (i >= 0 && j >= (m == n)) {
			if (i != vi && a[i] + b[j] > a[vi] ||
					a[i] + b[j] == a[vi] && strcmp(s[i], v) < 0) {
				a[i] += b[j];
				j--;
			}
			i--;
		}
	}

	sort(0, n - 1);

	for (i = 0; i < n; i++)
		if (strcmp(s[i], v) == 0)
			break;

	int l = i;

	printf("%d %d\n", h + 1, l + 1);

	return 0;
}
