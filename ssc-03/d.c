#include <stdio.h>
#include <string.h>

typedef struct line line;
typedef struct segm segm;

struct line { double k, b; };
struct segm { double x1, x2; line *l; char c; };

double diff(line *l, line *m, double x) {
	return (l->k * x + l->b) - (m->k * x + m->b);
}

double inters(line *l, line *m) {
	return -(m->b - l->b)/(m->k - l->k);
}

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

const double eps = 1e-9;

int main() {
	int n; scanf("%d", &n);

	segm ss[300*100]; int sn = 0;
	line ls[300];
	for (line *l = ls; l != ls+n; l++) {
		double x1, y1, x2, y2; char c; scanf("%lf%lf%lf%lf %c", &x1, &y1, &x2, &y2, &c);
		*l = (line){(y2-y1)/(x2-x1), (-x1*y2 + x2*y1)/(x2-x1)};

		if (x1 > x2) {
			double t = x1; x1 = x2; x2 = t;
		}

		segm ts[300*100]; int tn = 0;

		segm *s = ss;
		while (s != ss+sn && s->x2 < x1)
			ts[tn++] = *s++;

		while (s != ss+sn && x2 >= s->x1 && x1 <= s->x2) {
			if (x1 - s->x1 > eps)
				ts[tn++] = (segm){s->x1, x1, s->l, s->c};
			else if (s->x1 - x1 > eps)
				ts[tn++] = (segm){x1, s->x1, l, c};

			double xx1 = max(s->x1, x1), xx2 = min(s->x2, x2);
			double d1 = diff(s->l, l, xx1), d2 = diff(s->l, l, xx2);

			if (xx2 - xx1 > eps)
				if (d1 < 0 && d2 < 0)
					ts[tn++] = (segm){xx1, xx2, s->l, s->c};
				else if (d1 >= 0 && d2 >= 0)
					ts[tn++] = (segm){xx1, xx2, l, c};
				else {
					double x = inters(s->l, l);
					if (d1 < 0 && d2 >= 0) {
						if (x-xx1 > eps)
							ts[tn++] = (segm){xx1, x, s->l, s->c};
						if (xx2-x > eps)
							ts[tn++] = (segm){x, xx2, l, c};
					} else {
						if (x-xx1 > eps)
							ts[tn++] = (segm){xx1, x, l, c};
						if (xx2-x > eps)
							ts[tn++] = (segm){x, xx2, s->l, s->c};
					}
				}

			if (x2 > s->x2)
				x1 = s->x2;
			else {
				if (s->x2 - x2 > eps)
					ts[tn++] = (segm){x2, s->x2, s->l, s->c};
				x1 = x2;
			}

			s++;
		}

		if (x2-x1 > eps)
			ts[tn++] = (segm){x1, x2, l, c};

		while (s != ss+sn)
			ts[tn++] = *s++;

		if (tn > 300*100)
			return 1;

		memcpy(ss, ts, sizeof ts);
		sn = tn;

		/* for (segm *s = ss; s != ss+sn; s++)
			printf("[%.1lf:%.1lf]%c ", s->x1, s->x2, s->c);
		putchar('\n'); */
	}

	double l1 = 0, l2 = 0, l3 = 0;
	for (segm *s = ss; s != ss+sn; s++) {
		double l = s->x2 - s->x1;
		if (s->c == 'R')
			l1 += l;
		else if (s->c == 'G')
			l2 += l;
		else
			l3 += l;
	}

	printf("R %.2lf\nG %.2lf\nB %.2lf\n", l1, l2, l3);

	return 0;
}
