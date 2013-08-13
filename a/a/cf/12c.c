#include <stdio.h>
#include <string.h>

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int ps[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &ps[i]);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (ps[j] < ps[i]) {
				int t = ps[i]; ps[i] = ps[j]; ps[j] = t;
			}

	char names[100][50];
	for (int i = 0; i < m; i++)
		scanf("%s", names[i]);

	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++)
			if (strcmp(names[j], names[i]) < 0) {
				char t[100];
				strcpy(t, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], t);
			}
	}

	int k = 1;
	int cs[100];
	cs[0] = 1;
	for (int i = 1; i < m; i++) {
		fprintf(stderr, "!%s\n", names[i]);
		if (!strcmp(names[i], names[i-1]))
			cs[k-1]++;
		else
			cs[k++] = 1;
	}

	for (int i = 0; i < k; i++)
		for (int j = i+1; j < k; j++)
			if (cs[j] < cs[i]) {
				int t = cs[i]; cs[i] = cs[j]; cs[j] = t;
			}

	int min = 0, max = 0;
	for (int i = 0; i < k; i++) {
		fprintf(stderr, "%d %d\n", cs[i], ps[n-k+i]);
		min += cs[i]*ps[k-1-i];
		max += cs[i]*ps[n-k+i];
	}

	printf("%d %d\n", min, max);

	return 0;
}
