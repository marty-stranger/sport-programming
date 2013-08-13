/* ok */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sb[100*1024];
char *s[1000000];
int p[1000000];

int cmp(char *s1, char *s2) {
	int i, j, l1, l2, i1, j1, i2, j2, ii, d;

	l1 = strlen(s1);
	l2 = strlen(s2);
	i = j = 0;
	d = 0;
	while (i < l1 && j < l2)
		if (isdigit(s1[i]) && isdigit(s2[j])) {
			i1 = i; j1 = j;
			while (i < l1 && s1[i] == '0')
				i++;
			while (j < l2 && s2[j] == '0')
				j++;

			i2 = i; j2 = j;
			while (i < l1 && isdigit(s1[i]))
				i++;
			while (j < l2 && isdigit(s2[j]))
				j++;

			if (i - i2 != j - j2)
				return i - i2 - (j - j2);

			for (ii = 0; ii < i - i2; ii++)
				if (s1[i2 + ii] != s2[j2 + ii])
					return s1[i2 + ii] - s2[j2 + ii];

			if (i - i1 != j - j1 && d == 0)
				d = j - j1 - (i - i1);
		} else {
			if (s1[i] != s2[j])
				return s1[i] - s2[j];
			i++;
			j++;
		}

	if (i < l1)
		return 1;
	if (j < l2)
		return -1;

	if (d != 0)
		return d;

	return 0;
}

void sort(int l, int r) {
	int i, j, x, t;

	if (l < r) {
		i = l; j = r; x = p[l + rand() % (r - l + 1)];

		while (i <= j)
			if (cmp(s[p[i]], s[x]) < 0)
				i++;
			else if (cmp(s[x], s[p[j]]) < 0)
				j--;
			else {
				t = p[i]; p[i] = p[j]; p[j] = t;
				i++; j--;
			}

		sort(i, r);
		sort(l, j);
	}
}

int main() {
	int n, i;

	n = 0;
	s[0] = sb;
	while (scanf("%s", s[n]) == 1) {
		s[n + 1] = s[n] + strlen(s[n]) + 1;
		n++;
	}

	for (i = 0; i < n; i++)
		p[i] = i;

	sort(0, n - 1);

	for (i = 0; i < n; i++)
		puts(s[p[i]]);
		
	return 0;
}
