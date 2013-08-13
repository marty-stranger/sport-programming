#include <stdio.h>
#include <stdlib.h>

typedef struct { int t, a; } event;

event es[2*100000];

int less(event a, event b) {
	return a.a < b.a || a.a == b.a && a.t < b.t;
}

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand()%(r-l+1);
		event p = es[m];

		while (i <= j)
			if (less(es[i], p))
				i++;
			else if (less(p, es[j]))
				j--;
			else {
				event t = es[i]; es[i] = es[j]; es[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; scanf("%d", &n);

	long long s = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);

		es[2*i] = (event){0, a};
		s += a;

		a++;
		scanf("%d", &a);
		es[2*i+1] = (event){1, a};
	}

	sort(0, 2*n-1);

	int i = 0, c = 0, l, m;
	long long ms = 0;
	while (i < 2*n) {
		int j = i;
		while (j < 2*n && es[j].a == es[i].a && es[j].t == 0) {
			event e = es[j];
			if (c == 0) {
				c++;
				l = e.a;
			} else {
				s += 1ll*c*(e.a-l);
				l = e.a;
				c++;
			}
			j++;
		}

		// printf("j = %d a = %d -> %d\n", j, es[i].a, s);

		if (s > ms) {
			ms = s;
			m = es[i].a;
		}

		while (j < 2*n && es[j].a == es[i].a && es[j].t == 1) {
			event e = es[j];
			s += 1ll*c*(e.a-l);
			// printf("j = %d a = %d -> %d\n", j, es[i].a, s);
			if (s > ms) {
				ms = s;
				m = es[i].a;
			}

			l = e.a;
			c--;
			s -= e.a;
			j++;
		}


		i = j;
	}

	printf("%d %I64d\n", m, ms);

	return 0;
}
