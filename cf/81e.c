#include <stdio.h>
#include <string.h>

int g[100000], l[100000], ln[100000], s[100000], b[100000], cp[100000][2], cs[100000][2],
    cb[100000], cu[100000];

int max(int a, int b) {
	return a > b ? a : b;
}

int count(int u) {
	b[u] = 1;
	
	// printf("count u = %d\n", u+1);

	int i;
	cp[u][0] = cs[u][0] = 0;
	for (i = g[u]; i != -1; i = ln[i]) {
		int v = l[i];
		if (v < 0)
			continue;
		// printf("%d -> %d\n", u+1, v+1);
		count(v);

		int pc, sc;
		if (cp[v][0] > cp[v][1] || cp[v][0] == cp[v][1] && cs[v][0] > cs[v][1])
			pc = cp[v][0], sc = cs[v][0], cb[v] = 0;
		else
			pc = cp[v][1], sc = cs[v][1], cb[v] = 1;

		cp[u][0] += pc;
		cs[u][0] += sc;
	}

	// printf("u = %d c[0] -> %d %d\n", u+1, cp[u][0], cs[u][0]);

	cp[u][1] = cs[u][1] = 0;
	for (i = g[u]; i != -1; i = ln[i]) {
		int v = l[i];
		if (v < 0)
			continue;

		int pc, sc;
		if (cp[v][0] > cp[v][1] || cp[v][0] == cp[v][1] && cs[v][0] > cs[v][1])
			pc = cp[v][0], sc = cs[v][0];
		else
			pc = cp[v][1], sc = cs[v][1];

		pc = cp[u][0] - pc + cp[v][0] + 1;
		sc = cs[u][0] - sc + cs[v][0] + abs(s[u] - s[v]);

		if (pc > cp[u][1] || pc == cp[u][1] && sc > cs[u][1])
			cp[u][1] = pc, cs[u][1] = sc, cu[u] = v;
	}

	// printf("u = %d c[1] -> %d %d\n", u+1, cp[u][1], cs[u][1]);
}

int p[100000];

void edge_switch(int u) {
	int i;
	for (i = g[p[u]]; i != -1; i = ln[i])
		if (l[i] == u || l[i] == -u-1) {
			l[i] = -l[i]-1;
			i = ln[i];
			break;
		}
}

int en = 0, eu[100000];

void backtrace(int u, int b) {
	// printf("bt: u = %d %d\n", u+1, b);
	if (b) {
		// printf("cu = %d\n", cu[u]);
		int i;
		for (i = g[u]; i != -1; i = ln[i]) {
			int v = l[i];
			if (v < 0)
				continue;
			if (v == cu[u])
				eu[en++] = cu[u];
			backtrace(v, cu[u] == v ? 0 : cb[v]);
		}
	} else {
		int i;
		for (i = g[u]; i != -1; i = ln[i]) {
			int v = l[i];
			if (v < 0)
				continue;
			backtrace(v, cb[v]);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	
	int u, i = 0;
	memset(g, -1, sizeof(g));
	for (u = 0; u < n; u++) {
		int v, t; scanf("%d%d", &v, &t); v--; t--;
		p[u] = v; s[u] = t;
		l[i] = u; ln[i] = g[v]; g[v] = i; i++;
	}

	memset(b, 0, sizeof(b));
	int ps = 0, ss = 0;
	for (u = 0; u < n; u++)
		if (!b[u]) {
			// printf("main: u = %d\n", u+1);
			int v = u;
			while (!b[v]) {
				b[v] = 1;
				v = p[v];
			}
			
			// printf("main: v = %d\n", v+1);

			edge_switch(v);

			// puts("non-paired");
			count(v);

			int mp, ms, b;
			if (cp[v][0] > cp[v][1] || cp[v][0] == cp[v][1] && cs[v][0] > cs[v][1])
				mp = cp[v][0], ms = cs[v][0], b = 0;
			else
				mp = cp[v][1], ms = cs[v][1], b = 1;
			// printf("non-paired: %d %d\n", mp, ms);

			int w = p[v];
			edge_switch(w);

			// puts("paired");
			count(v);
			count(w);

			int pc = cp[v][0] + cp[w][0] + 1,
			    sc = cs[v][0] + cs[w][0] + abs(s[w] - s[v]);
			// printf("paired: %d %d\n", pc, sc);

			if (pc > mp || pc == mp && sc > ms) {
				// puts("back-paired");
				mp = pc, ms = sc;
				eu[en++] = v;
				backtrace(v, 0);
				backtrace(w, 0);
			} else {
				// puts("back-non-paired");
				edge_switch(w);
				count(v);
				backtrace(v, b);
			}

			ps += mp; ss += ms;
		}

	printf("%d %d\n", ps, ss);

	for (i = 0; i < en; i++)
		printf("%d %d\n", eu[i]+1, p[eu[i]]+1);

	return 0;
}
