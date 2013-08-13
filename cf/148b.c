#include <stdio.h>

int main() {

	int vp, vd, t, f, c;
	scanf("%d%d%d%d%d", &vp, &vd, &t, &f, &c);

	if (vp > vd) {
		puts("0");
		return 0;
	}

	double tt = t;
	int cc = 0;
	while (1) {
		double t = vp*tt / (vd - vp);

		if (!(vd*t + 1e-9 < c))
			break;

		cc++;
		tt += 2*t + f;

	}

	printf("%d\n", cc);

	return 0;
}
