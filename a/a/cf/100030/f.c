#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word word;
struct word { char *s; int i, d; word *p; };

word ws[60000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand()%(r-l+1);
		char *p = ws[m].s;

		while (i <= j)
			if (strcmp(ws[i].s, p) < 0)
				i++;
			else if (strcmp(p, ws[j].s) < 0)
				j--;
			else {
				word t = ws[i]; ws[i] = ws[j]; ws[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

#define HS 1000000
bool hs[HS] = {0};

int n;

word* find(char *s) {
	int l = 0, r = n-1;

	while (l < r) {
		int m = (l+r)/2;
		int c = strcmp(ws[m].s, s);
		if (c < 0)
			l = m+1;
		else if (c > 0)
			r = m-1;
		else
			return &ws[m];
	}

	if (strcmp(ws[l].s, s) == 0)
		return &ws[l];

	return NULL;
}

int hash(char *s) {
	int n = strlen(s);

	unsigned int h = 0, p = 31;
	for (int i = 0; i < n; i++) {
		h += (s[i]-'a'+1)*p;
		p *= 31;
	}

	return h % HS;
}

void backtrace(word *w) {
	if (w == NULL)
		return;

	backtrace(w->p);
	printf("%s\n", w->s);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		word *w = &ws[i];
		w->s = (char*)malloc(11);
		scanf("%s", w->s);
		w->i = i;

		int h = hash(w->s);
		// printf("h = %d\n", h);
		hs[h] = true;
	}

	sort(0, n-1);

	word *f;
	for (word *w = ws; w != ws+n; w++) {
		// printf("%s\n", w->s);
		if (w->i == 0) {
			f = w;
			w->d = 1;
			w->p = NULL;
		} else
			w->d = -1;
	}

	word *q[100000];
	word **qf = q, **ql = q;

	*ql = f; ql++;

	while (qf != ql) {
		word *w = *qf; qf++;

		int l = strlen(w->s);
		for (int i = 0; i < l; i++) {
			char t[11]; strcpy(t, w->s);
			for (char c = 'a'; c <= 'z'; c++) if (c != w->s[i]) {
				t[i] = c;
				if (hs[hash(t)]) {
					word *x = find(t);
					// printf("t = %s -> %d\n", t, x != NULL);
					if (x != NULL && x->d == -1) {
						x->d = w->d + 1;
						x->p = w;
						*ql = x; ql++;
					}
				}
			}
		}
	}

	word *l;
	for (int i = 0; i < n; i++)
		if (ws[i].i == n-1)
			l = &ws[i];

	if (l->d == -1) {
		puts("FAIL");
		return 0;
	}

	printf("%d\n", l->d);
	backtrace(l);

	return 0;
}
