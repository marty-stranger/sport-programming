#include <stdio.h>
#include <string.h>

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int pn = 0, p[n+1];
	p[pn++] = 2;
	for (int i = 3; i*i <= n; i += 2) {
		int f = 1;
		for (int j = 0; j < pn && p[j]*p[j] <= i; j++)
			if (i % p[j] == 0) {
				f = 0;
				break;
			}

		if (f)
			p[pn++] = i;
	}

	int c[n+1], l[n+1], b[n+1];
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < m; i++) {
		char s[3]; int a;
		scanf("%s%d", s, &a);

		if (s[0] == '+') {
			if (b[a]) {
				puts("Already on");
				continue;
			}

			int f = 1, t = a, pp;
			for (int j = 0; j < pn && p[j]*p[j] <= t; j++) {
				// printf("p = %d t = %d\n", p[j], t);
				if (t % p[j] == 0)
					if (c[p[j]] != 0) {
						f = 0;
						pp = p[j];
						break;
					} else {
						while (t % p[j] == 0)
							t /= p[j];
					}
			}

			if (f && t != 1 && c[t] != 0) {
				f = 0;
				pp = t;
				// printf("t = %d pp = %d\n", t, pp);
			}

			// printf("pp = %d\n", pp);

			if (f) {
				int t = a;
				for (int j = 0; j < pn && p[j]*p[j] <= t; j++)
					while (t % p[j] == 0) {
						c[p[j]]++;
						l[p[j]] = a;
						t /= p[j];
					}

				if (t != 1) {
					// printf("t != 1 -> t = %d %d\n", t, a);
					c[t]++;
					l[t] = a;
				}

				puts("Success");
				b[a] = 1;
			} else
				printf("Conflict with %d\n", l[pp]);
		} else {
			if (!b[a])
				puts("Already off");
			else {
				int t = a;
				for (int j = 0; j < pn && p[j]*p[j] <= a; j++)
					while (t % p[j] == 0) {
						c[p[j]]--;
						t /= p[j];
					}

				if (t != 1)
					c[t]--;
				b[a] = 0;
				puts("Success");
			}
		}
	}

	return 0;
}

