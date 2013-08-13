#include <stdio.h>
#include <string.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
	char s[100001];
	scanf("%s", s);

	int m; scanf("%d", &m);

	char p[200]; int pi[200];
	memset(pi, -1, sizeof(pi));
	for (int i = 0; i < m; i++) {
		char t[3]; scanf("%s", t);
		p[t[0]] = t[1]; p[t[1]] = t[0];
		pi[t[0]] = pi[t[1]] = i;
	}

	int n = strlen(s);

	int i = 0, c = 0;
	while (i < n) {
		char a = s[i], b = p[s[i]];
		int j = i+1, c1 = 1, c2 = 0;
		while (j < n && pi[s[j]] != -1 && pi[s[j]] == pi[s[i]]) {
			if (s[j] == a)
				c1++;
			else
				c2++;
			j++;
		}

		c += min(c1, c2);
		i = j;
	}

	printf("%d", c);
	putchar('\n');

	return 0;
}
