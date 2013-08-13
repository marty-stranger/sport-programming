#include <stdio.h>
#include <string.h>

double p[1001][1001];
int pb[1001][1001];

double count(int w, int b) {
	if (w < 0 || b < 0)
		return 0;

	printf("w = %d b = %d\n", w, b);

	if (w == 0 && b == 0) 
		return 0.0 ;
	else if (w == 1 && b == 0)
		return 1.0;
	else if (w == 0 && b == 1)
		return 0;

	if (pb[w][b])
		return p[w][b];

	double pp = 0;
	if (w+b-2 > 0) {
		pp += 1.*w/(w+b-2)*count(w-1, b-2);
		pp += 1.*(b-2)/(w+b-2)*count(w, b-3);
	}

	p[w][b] = 1.*w/(w+b) + 1.*b/(w+b)*(b-1)/(w+b-1)*pp;
	pb[w][b] = 1;

	printf("w = %d b = %d -> %lf\n", w, b, p[w][b]);

	return p[w][b];
}

int main() {
	int w, b; scanf("%d%d", &w, &b);

	memset(pb, 0, sizeof(pb));
	printf("%.10lf", count(w, b));

	return 0;
}
