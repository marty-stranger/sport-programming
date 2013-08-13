#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

typedef struct { char n[40]; int a; } round;
typedef struct { char *n; int s; } player;

int main() {
	int n; scanf("%d", &n);

	round rs[n];
	int ps_n = 0;
	player ps[n];
	for (int i = 0; i < n; i++) {
		scanf("%s%d", rs[i].n, &rs[i].a);

		int j;
		for (j = 0; j < ps_n; j++)
			if (!strcmp(ps[j].n, rs[i].n))
				break;

		if (j == ps_n)
			ps[ps_n++] = (player){rs[i].n, 0};
		
		ps[j].s += rs[i].a;
	}

	int m = 0;
	for (int i = 0; i < ps_n; i++)
		m = max(m, ps[i].s);

	int c = 0;
	for (int i = 0; i < ps_n; i++)
		if (ps[i].s == m)
			c++;
	
	if (c == 1)
		for (int i = 0; i < ps_n; i++)
			if (ps[i].s == m) {
				puts(ps[i].n);
				return 0;
			}

	int s[n];
	memset(s, 0, sizeof(s));

	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < ps_n; j++)
			if (!strcmp(ps[j].n, rs[i].n))
				break;

		if (ps[j].s == m) {
			s[j] += rs[i].a;
			if (s[j] >= m) {
				puts(ps[j].n);
				return 0;
			}
		}
	}

	return 0;
}
