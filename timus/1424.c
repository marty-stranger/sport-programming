#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif

typedef struct segm segm;
struct segm { int i, s, f; bool b; };

bool less(segm s, segm t) {
	return s.f < t.f;
}

void sort(segm *ss, int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r;
	segm p = ss[l + rand() % (r-l+1)];

	while (i <= j)
		if (less(ss[i], p))
			i++;
		else if (less(p, ss[j]))
			j--;
		else {
			segm t = ss[i]; ss[i] = ss[j]; ss[j] = t;
			i++; j--;
		}

	sort(ss, i, r); sort(ss, l, j);
}

int main() {
	int n, m, k, p; scanf("%d%d%d%d", &n, &m, &k, &p);

	segm ss[50000] = {0};

	for (int i = 0; i < k; i++)
		ss[i].i = i;

	for (segm *s = ss; s != ss+k; s++)
		scanf("%d%d", &s->s, &s->f);

	srand(time(NULL));

	sort(ss, 0, k-1);

	int c = 0;
	for (int i = 0; i < m; i++) {
		int l = -1;

		for (segm *s = ss; s != ss+k; s++)
			if (!s->b && s->s >= l) {
				s->b = true;
				l = s->f;
				c++;
			}
	}

	printf("%d\n", c*p);

	for (segm *s = ss; s != ss+k; s++)
		if (s->b)
			printf("%d ", s->i + 1);

	printf("\n");

	return 0;
}
