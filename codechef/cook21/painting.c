#include <stdbool.h>
#include <stdio.h>

typedef struct segm segm;
struct segm { long long x1, y1, x2, y2; };

typedef struct range range;
struct range { long long a, b; };

long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }

bool less(range a, range b) {
	return a.a < b.a;
}

void sort(range rs[], int l, int r) {
	if (l < r) {
		int i = l, j = r, m = (l+r)/2;
		range p = rs[m];

		while (i <= j)
			if (less(rs[i], p))
				i++;
			else if (less(p, rs[j]))
				j--;
			else {
				range t = rs[i]; rs[i] = rs[j]; rs[j] = t;
				i++; j--;
			}

		sort(rs, i, r); sort(rs, l, j);
	}
}

int main() {
	int n; scanf("%d", &n);

	int sn = 0;
	segm ss[1001];

	ss[sn++] = (segm){0, 0, 0, 0};

	long long x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		char s[3]; scanf("%s", s);
		int d; scanf("%d", &d);

		if (s[0] == 'R') {
			ss[sn++] = (segm){x+1, y, x+d, y};
			x += d;
		} else if (s[0] == 'L') {
			ss[sn++] = (segm){x-d, y, x-1, y};
			x -= d;
		} else if (s[0] == 'U') {
			ss[sn++] = (segm){x, y+1, x, y+d};
			y += d;
		} else {
			ss[sn++] = (segm){x, y-d, x, y-1};
			y -= d;
		}
	}

	for (int i = 1; i < sn; i++) {
		int rn = 0;
		range rs[2000];

		for (int j = 0; j < i; j++) {
			segm si = ss[i], sj = ss[j]; 
			if (si.x1 == si.x2)
				if (sj.x1 == sj.x2) {
					if (si.x1 == sj.x1) {
						range r = {max(si.y1, sj.y1), min(si.y2, sj.y2)};
						if (r.a <= r.b)
							rs[rn++] = r;
					}
				} else {
					if (si.y1 <= sj.y1 && sj.y1 <= si.y2 &&
							sj.x1 <= si.x1 && si.x1 <= sj.x2)
						rs[rn++] = (range){sj.y1, sj.y1};
				}
			else
				if (sj.y1 == sj.y2) {
					if (si.y1 == sj.y1) {
						range r = {max(si.x1, sj.x1), min(si.x2, sj.x2)};
						if (r.a <= r.b)
							rs[rn++] = r;
					}
				} else { // sj.x1 == sj.x2
					if (si.x1 <= sj.x1 && sj.x1 <= si.x2 &&
							sj.y1 <= si.y1 && si.y1 <= sj.y2)
						rs[rn++] = (range){sj.x1, sj.x1};
				}
		}

		sort(rs, 0, rn-1);

		long long s;
		if (ss[i].x1 == ss[i].x2)
			s = ss[i].y2 - ss[i].y1 + 1;
		else
			s = ss[i].x2 - ss[i].x1 + 1;

		if (rn != 0) {
			range r = rs[0];
			for (int j = 1; j < rn; j++)
				if (r.b < rs[j].a) {
					s -= r.b - r.a + 1;
					r = rs[j];
				} else
					r = (range){min(r.a, rs[j].a), max(r.b, rs[j].b)};

			s -= r.b - r.a + 1;
		}

		printf("%lld\n", s);
	}

	return 0;
}
