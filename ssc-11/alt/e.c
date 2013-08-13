// TODO prettify
#include <stdio.h>
#include <string.h>

int mm, mu, mv, mw, eu[100000], ev[100000], et[100000], ep[100000], gi[100000], lei[200000], ln[200000],
    b[100000], h[100000], hu[100000], p[100000], pb[100000-1];

int dfs(int u) {
	int i, v, ei, u1, u2, m, m1, m2;

	u1 = u2 = -1; m1 = m2 = 0;

	b[u] = 1;

	for (i = gi[u]; i != -1; i = ln[i]) {
		ei = lei[i]; v = eu[ei] + ev[ei] - u;

		if (!b[v]) {
			p[v] = ei;
			dfs(v);

			m = h[v] + et[ei];
			if (u1 == -1)
				u1 = v, m1 = m;
			else if (u2 == -1)
				u2 = v, m2 = m;
			else if (m > m1 && m > m2)
				if (m1 > m2)
					u2 = v, m2 = m;
				else
					u1 = v, m1 = m;
			else if (m > m1)
				u1 = v, m1 = m;
			else if (m > m2)
				u2 = v, m2 = m;
		}
	}

	if (m1 + m2 > mm)
		mu = hu[u1], mv = hu[u2], mw = u, mm = m1 + m2;

	if (u1 == -1 && u2 == -1)
		h[u] = 0, hu[u] = u;
	else if (m1 > m2)
		h[u] = m1, hu[u] = hu[u1];
	else
		h[u] = m2, hu[u] = hu[u2];
}

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int dfs2(int ei, int u) {
	int i, v, ej, m, pp;

	b[u] = 1;

	m = 0;
	for (i = gi[u]; i != -1; i = ln[i]) {
		ej = lei[i]; v = eu[ej] + ev[ej] - u;

		if (!b[v]) {
			dfs2(ej, v);
			if (h[v] > m)
				m = h[v];
		}
	}

	h[u] = m + et[ei];

	pp = 0;
	for (i = gi[u]; i != -1; i = ln[i]) {
		ej = lei[i]; v = eu[ej] + ev[ej] - u;

		if (h[v] == h[u] - et[ei])
			pp += p[v];
	}

	if (pp == 0)
		p[u] = ep[ei];
	else
		p[u] = min(pp, ep[ei]);
}

int dfs2c(int u) {
	int i, v, ei;

	for (i = gi[u]; i != -1; i = ln[i]) {
		ei = lei[i]; v = eu[ei] + ev[ei] - u;
		if (!b[v])
			dfs2(ei, v);
	}
}

int dfs3(int ei, int u) {
	int i, v, ej;

	b[u] = 1;

	if (p[u] == ep[ei]) {
		pb[ei] = 1;
		return;
	}

	i = gi[u];
	for (i = gi[u]; i != -1; i = ln[i]) {
		ej = lei[i]; v = eu[ej] + ev[ej] - u;

		if (!b[v] && h[v] == h[u] - et[ei])
			dfs3(ej, v);
	}
}

int main() {
	int n, f, i, u, v, deg[100000], dpn, dp2n, dp[100000], dp2[100000], ei, s, r, c1, c2, cei, mp, c, diam,
	    mpu, p1, p2, pp;

	scanf("%d", &n);

	memset(deg, 0, sizeof(deg));
	memset(gi, -1, sizeof(gi));
	f = 0;
	for (i = 0; i < n - 1; i++) {
		scanf("%d%d%d%d", &u, &v, &et[i], &ep[i]);
		u--; v--; eu[i] = u; ev[i] = v;
		lei[f] = i; ln[f] = gi[u]; gi[u] = f; f++;
		lei[f] = i; ln[f] = gi[v]; gi[v] = f; f++;
		deg[u]++; deg[v]++;
	}

	if (n == 2) {
		printf("%d\n%d\n%d\n", ep[0], 1, 1);
		return 0;
	}

	for (u = 0; u < n; u++)
		if (deg[u] != 1)
			break;

	memset(b, 0, sizeof(b));
	p[u] = -1; mm = 0;
	dfs(u);

	u = mu; dpn = 0;
	while (u != mw) {
		ei = p[u];
		dp[dpn++] = ei;
		u = eu[ei] + ev[ei] - u;
	}

	if (mv != -1) {
		u = mv; dp2n = 0;
		while (u != mw) {
			ei = p[u];
			dp2[dp2n++] = ei;
			u = eu[ei] + ev[ei] - u;
		}

		for (i = dp2n - 1; i >= 0; i--)
			dp[dpn++] = dp2[i];
	}

	diam = 0;
	for (i = 0; i < dpn; i++)
		diam += et[dp[i]];

	r = -1;

	s = 0;
	for (i = 0; i < dpn; i++) {
		if (r == -1 || max(s, diam - s) < r)
			r = max(s, diam - s);
		ei = dp[i];
		s += et[ei];
	}

	c1 = -1; c2 = -1;

	s = 0; u = mu;
	for (i = 0; i < dpn; i++) {
		if (max(s, diam - s) == r)
			if (c1 == -1)
				c1 = u;
			else if (c2 == -1)
				c2 = u;
		ei = dp[i];
		s += et[ei];
		u = eu[ei] + ev[ei] - u;
	}

	if (max(s, diam - s) == r) {
		if (c1 == -1)
			c1 = u;
		else if (c2 == -1)
			c2 = u;
	}

	if (c2 != -1) {
		cei = -1;
		u = mu;
		for (i = 0; i < dpn; i++) {
			ei = dp[i];
			v = eu[ei] + ev[ei] - u;
			if (u == c1 && v == c2 || u == c2 && v == c1)
				cei = ei;
			u = v;
		}
	}
	
	memset(pb, 0, sizeof(pb));
	if (c2 == -1) {
		memset(b, 0, sizeof(b));
		b[c1] = 1; dfs2c(c1);

		if (r == s - r) {
			mpu = -1;
			pp = 0;
			for (i = gi[c1]; i != -1; i = ln[i]) {
				ei = lei[i]; u = eu[ei] + ev[ei] - c1;
				if (h[u] == r) {
				       	if (mpu == -1 || p[u] > p[mpu])
						mpu = u;
					pp += p[u];
				}
			}

			memset(b, 0, sizeof(b));
			b[c1] = 1;

			for (i = gi[c1]; i != -1; i = ln[i]) {
				ei = lei[i]; u = eu[ei] + ev[ei] - c1;
				if (h[u] == r && u != mpu)
					dfs3(ei, u);
			}
			mp = pp - p[mpu];
		} else {
			p1 = 0; p2 = -1;
			for (i = gi[c1]; i != -1; i = ln[i]) {
				ei = lei[i]; u = eu[ei] + ev[ei] - c1;
				if (h[u] == diam - r)
					p1 += p[u];
				else if (h[u] == r)
					p2 = p[u];
			}
			
			memset(b, 0, sizeof(b));
			b[c1] = 1;

			if (p1 < p2)
				for (i = gi[c1]; i != -1; i = ln[i]) {
					ei = lei[i]; u = eu[ei] + ev[ei] - c1;
					if (h[u] == diam - r)
						dfs3(ei, u);
				}
			else
				for (i = gi[c1]; i != -1; i = ln[i]) {
					ei = lei[i]; u = eu[ei] + ev[ei] - c1;
					if (h[u] == r)
						dfs3(ei, u);
				}
			mp = min(p1, p2);
		}
	} else {
		memset(b, 0, sizeof(b));
		b[c1] = 1; b[c2] = 1; dfs2c(c1); dfs2c(c2);

		pp = 0; mpu = -1;
		for (i = gi[c1]; i != -1; i = ln[i]) {
			ei = lei[i]; u = eu[ei] + ev[ei] - c1;
			if (u != c2 && h[u] == r - et[cei])
				p1 += p[u];
		}
		
		p1 = 0;
		for (i = gi[c1]; i != -1; i = ln[i]) {
			ei = lei[i]; u = eu[ei] + ev[ei] - c1;
			if (u != c2 && h[u] == r - et[cei])
				p1 += p[u];
		}
		p2 = 0;
		for (i = gi[c2]; i != -1; i = ln[i]) {
			ei = lei[i]; u = eu[ei] + ev[ei] - c2;
			if (u != c1 && h[u] == r - et[cei])
				p2 += p[u];
		}

		if (ep[cei] < min(p1, p2)) {
			printf("%d\n%d\n%d\n", ep[cei], 1, cei + 1);
			return 0;
		}

		memset(b, 0, sizeof(b));
		b[c1] = 1; b[c2] = 1;

		if (p1 < p2)
			for (i = gi[c1]; i != -1; i = ln[i]) {
				ei = lei[i]; u = eu[ei] + ev[ei] - c1;
				if (u != c2 && h[u] == r - et[cei])
					dfs3(ei, u);
			}
		else
			for (i = gi[c2]; i != -1; i = ln[i]) {
				ei = lei[i]; u = eu[ei] + ev[ei] - c2;
				if (u != c1 && h[u] == r - et[cei])
					dfs3(ei, u);
			}

		mp = min(p1, p2);
	}

	printf("%d\n", mp);
	c = 0;
	for (i = 0; i < n-1; i++)
		if (pb[i])
			c++;
	printf("%d\n", c);
	for (i = 0; i < n-1; i++)
		if (pb[i])
			printf("%d ", i+1);
	putchar('\n');

	return 0;
}
