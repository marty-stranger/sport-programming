#include <math.h>
#include <stdio.h>

typedef struct { int x, y; } point;

void read(point *p) {
	scanf("%d%d", &p->x, &p->y);
}

typedef struct { int x, y; } vector;

int cross(vector v, vector w) {
	return v.x*w.y - w.x*v.y;
}

int dot(vector v, vector w) {
	return v.x*w.x + v.y*w.y;
}

vector sub(point a, point b) {
	return (vector){b.x-a.x, b.y-a.y};
}

typedef struct { point a, b; } segment;

int parallels(segment s, segment t) {
	return cross(sub(s.a, s.b), sub(t.a, t.b)) == 0;
}

int direction(point a, point b, point c) {
	return cross(sub(a, c), sub(a, b));
}

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int on_segment(point a, point b, point c) {
	return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
		min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int intersects(segment s, segment t) {
	int d1 = direction(t.a, t.b, s.a),
	    d2 = direction(t.a, t.b, s.b),
	    d3 = direction(s.a, s.b, t.a),
	    d4 = direction(s.a, s.b, t.b);

	return (d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) &&
			(d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0) ||
		d1 == 0 && on_segment(t.a, t.b, s.a) ||
		d2 == 0 && on_segment(t.a, t.b, s.b) ||
		d3 == 0 && on_segment(s.a, s.b, t.a) ||
		d4 == 0 && on_segment(s.a, s.b, t.b);
}

typedef struct { double x, y; } float_point;

float_point intersection(segment s, segment t) {
	double c = 1. * cross(sub(s.a, t.a), sub(t.a, t.b)) / cross(sub(s.a, s.b), sub(t.a, t.b));
	return (float_point){s.a.x + c*(s.b.x - s.a.x), s.a.y + c*(s.b.y - s.a.y)};
}

double sqr(double a) { return a*a; }

float_point to_float_point(point p) {
	return (float_point){p.x, p.y};
}

double dist(float_point a, float_point b) {
	return sqrt(sqr(b.x-a.x) + sqr(b.y-a.y));
}

int main() {
	point p1, p2; read(&p1); read(&p2);

	int n; scanf("%d", &n);
	point ps[n];
	for (int i = 0; i < n; i++)
		read(&ps[i]);

	segment s = {p1, p2};
	int c = 0, i1, i2;
	float_point ip1, ip2;
	for (int i = 0; i < n; i++) {
		segment t = {ps[i], ps[(i+1)%n]};

		if (!intersects(s, t) || cross(sub(p1, p2), sub(p1, t.a)) == 0)
			continue;

		if (parallels(s, t)) {
			c++;
			continue;
		}

		float_point p = intersection(s, t);
		if (c == 0) {
			i1 = i;
			ip1 = p;
		} else if (c == 1) {
			i2 = i;
			ip2 = p;
		}
		c++;
	}


	float_point fp1 = to_float_point(p1), fp2 = to_float_point(p2);

	if (c != 2) {
		printf("%lf\n", dist(fp1, fp2));
		return 0;
	}

	if (dist(fp1, ip2) < dist(fp1, ip1)) {
		float_point tp = ip1; ip1 = ip2; ip2 = tp;
		int t = i1; i1 = i2; i2 = t;
	}

	double m = 2*dist(ip1, ip2);

	float_point fps[n];
	for (int i = 0; i < n; i++)
		fps[i] = to_float_point(ps[i]);

	double d = dist(ip1, fps[(i1+1)%n]);
	for (int i = (i1+1)%n; i != i2; i = (i+1)%n) {
		d += dist(fps[i], fps[(i+1)%n]);
	}
	d += dist(fps[i2], ip2);
	if (d < m)
		m = d;

	d = dist(ip1, fps[i1]);
	for (int i = i1; (i-1+n)%n != i2; i = (i-1+n)%n)
		d += dist(fps[i], fps[(i-1+n)%n]);
	d += dist(fps[(i2+1)%n], ip2);
	if (d < m)
		m = d;

	printf("%lf\n", m + dist(fp1, ip1) + dist(ip2, fp2));

	return 0;
}
