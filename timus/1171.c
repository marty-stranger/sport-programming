// #include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef int bool;
const bool true = 1;
const bool false = 0;

int max(int a, int b) { return a > b ? a : b; }

typedef struct { int f, d, px, py; char s[20]; } res;
typedef struct { bool b; int f; res r[301]; } room;

typedef struct { int f; char s[20]; } path;
typedef struct { bool b; path p[21]; } room2;

char dirs[20];

void g(room rs[4][4], room2 rs2[4][4], int x, int y, int c, int s, int dir) {
	room2 *r2 = &rs2[x][y];
	path *p = &r2->p[c+1];

	if (x < 0 || x >= 4 || y < 0 || y >= 4 || r2->b)
		return;

	if (c != 0)
		dirs[c-1] = dir;
	s += rs[x][y].f;

	c++;

	if (s > p->f) {
		p->f = s;
		dirs[c-1] = '\0';
		strcpy(p->s, dirs);
	}

	r2->b = true;

	g(rs, rs2, x+1, y, c, s, 'S');
	g(rs, rs2, x-1, y, c, s, 'N');
	g(rs, rs2, x, y+1, c, s, 'E');
	g(rs, rs2, x, y-1, c, s, 'W');

	r2->b = false;
} 

int main() {
	int n, i, x, y, sx, sy, d, days_opt;
	static room rooms[17][4][4];
	double ratio;

	scanf("%d", &n);

	for (i = n; i >= 1; i--) {
		for (x = 0; x < 4; x++) for (y = 0; y < 4; y++)
			scanf("%d", &rooms[i][x][y].f);
		for (x = 0; x < 4; x++) for (y = 0; y < 4; y++)
			scanf("%d", &rooms[i][x][y].b);
	}

	scanf("%d%d", &sx, &sy); sx--; sy--;

	for (x = 0; x < 4; x++) for (y = 0; y < 4; y++) {
		res *r = rooms[0][x][y].r;

		r[0].f = 0;
		for (i = 1; i <= 300; i++)
			r[i].f = -1e9;
	}

	for (i = 1; i <= n; i++)
		for (x = 0; x < 4; x++) for (y = 0; y < 4; y++) {
			res *rs = rooms[i][x][y].r;
			room2 rs2[4][4] = {0};
			int xx, yy, dd;

			for (xx = 0; xx < 4; xx++) for (yy = 0; yy < 4; yy++)
				for (dd = 0; dd <= 20; dd++)
					rs2[xx][yy].p[dd].f = -1e9;

			g(rooms[i], rs2, x, y, 0, 0, ' ');

			rs[0].f = -1e9;
			for (d = 1; d <= 300; d++) {
				res *r = &rs[d];

				r->f = -1e9;
				for (xx = 0; xx < 4; xx++) for (yy = 0; yy < 4; yy++) {
					if (i != 1 && !rooms[i][xx][yy].b) continue;

					for (dd = 0; dd <= 20; dd++) {
						path p = rs2[xx][yy].p[dd];
						int f = rooms[i-1][xx][yy].r[d-dd].f + p.f;

						if (d - dd < 0) continue;

						if (f > r->f) {
							r->px = xx;
							r->py = yy;
							r->f = f;
							r->d = dd;
							strcpy(r->s, p.s);
						}
					}
				}
			}
		}

	ratio = -1e9;
	for (d = 1; d <= 300; d++) {
		double r = 1. * rooms[n][sx][sy].r[d].f / d;

		if (r > ratio) {
			ratio = r;
			days_opt = d;
		}
	}

	printf("%.5lf\n%d\n", ratio, days_opt - 1);

	x = sx; y = sy; d = days_opt;
	for (i = n; i >= 1; i--) {
		res r = rooms[i][sx][sy].r[d];

		fputs(r.s, stdout);

		sx = r.px; sy = r.py;
		d -= r.d;

		if (i != 1)
			putchar('D');
	}

	putchar('\n');

	return 0;
}
