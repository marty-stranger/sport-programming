#include <stdio.h>

typedef struct { int x1, y1, x2, y2, b; } segm;
segm ss[4];

int parallel(segm s, segm t) {
	return 1ll*(s.x2-s.x1)*(t.y2-t.y1) - 1ll*(t.x2-t.x1)*(s.y2-s.y1) == 0;
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d%d%d", &ss[i].x1, &ss[i].y1, &ss[i].x2, &ss[i].y2);
		if (ss[i].x1 == ss[i].x2 && ss[i].y1 == ss[i].y2) {
			puts("NO");
			return 0;
		}
	}

	int x = ss[0].x2, y = ss[0].y2;
	int p[4];
	ss[0].b = 1; p[0] = 0;
	for (int i = 1; i < 4; i++) {
		int f = 0;
		for (int j = 0; j < 4; j++)
			if (!ss[j].b) {
				if (ss[j].x1 == x && ss[j].y1 == y) {
					ss[j].b = 1;
					x = ss[j].x2; y = ss[j].y2;
					p[i] = j;
					f = 1;
					break;
				}

				if (ss[j].x2 == x && ss[j].y2 == y) {
					ss[j].b = 1;
					x = ss[j].x1; y = ss[j].y1;
					p[i] = j;
					f = 1;
					break;
				}
			}

		if (!f) {
			puts("NO");
			return 0;
		} else
			fprintf(stderr, "p = %d\n", p[i]);
	}

	if (x != ss[0].x1 || y != ss[0].y1) {
		puts("NO");
		return 0;
	}

	segm ox = (segm){0, 0, 1, 0};
	segm oy = (segm){0, 0, 0, 1};
	if (parallel(ss[p[0]], ss[p[2]]) && parallel(ss[p[1]], ss[p[3]]) &&
			(parallel(ss[p[0]], ox) && parallel(ss[p[1]], oy) ||
			  parallel(ss[p[1]], ox) && parallel(ss[p[0]], oy)))
				 
		puts("YES");
	else
		puts("NO");

	return 0;
}
