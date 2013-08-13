#include <stdio.h>

typedef struct res res;
struct res { int n, p; };

int main() {
	int n, k; scanf("%d%d", &n, &k);
	k--;

	res rs[50];
	for (int i = 0; i < n; i++)
		scanf("%d%d", &rs[i].n, &rs[i].p);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (rs[j].n > rs[i].n || rs[j].n == rs[i].n && rs[j].p < rs[i].p) {
				res t = rs[i]; rs[i] = rs[j]; rs[j] = t;
			}

	int c = 1;
	int i = k-1;
	while (i >= 0 && rs[i].n == rs[k].n && rs[i].p == rs[k].p) {
		i--;
		c++;
	}

	i = k+1;
	while (i < n && rs[i].n == rs[k].n && rs[i].p == rs[k].p) {
		i++;
		c++;
	}

	printf("%d\n", c);

	return 0;
}
