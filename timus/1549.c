#include <stdio.h>

int main() {
	int s, t, f, k, l, i;

	scanf("%d%d", &s, &t);

	l = s / 2;
	if (t < 4)
		printf("Atawazu");
	else if (l > 0 && ((t - 6) % 8 == 0 || (t - 7) % 8 == 0)) {
		k = (t - 6) / 8;

		printf("%d\n", 8 + 8*k + 2*(l - 1));
		putchar('R');
		for (i = 0; i < l - 1; i++)
			putchar('F');
		for (i = 0; i < k; i++)
			printf("LRRL");
		printf("LRRFRF");
		for (i = 0; i < k; i++)
			printf("LRRL");
		for (i = 0; i < l - 1; i++)
			putchar('F');
		putchar('R');
	} else if (l > 0 && ((t - 8) % 8 == 0 || (t - 9) % 8 == 0)) {
		k = (t - 8) / 8;

		printf("%d\n", 10 + 8*k + 2*(l - 1));
		putchar('R');
		for (i = 0; i < l - 1; i++)
			putchar('F');
		for (i = 0; i < k; i++)
			printf("LRRL");
		printf("LRRFFRRL");
		for (i = 0; i < k; i++)
			printf("LRRL");
		for (i = 0; i < l - 1; i++)
			putchar('F');
		putchar('R');
	} else if (l > 0 && ((t - 10) % 8 == 0 || (t - 11) % 8 == 0)) {
		k = (t - 10) / 8;

		printf("%d\n", 12 + 8*k + 2*(l - 1));
		putchar('R');
		for (i = 0; i < l - 1; i++)
			putchar('F');
		for (i = 0; i < k; i++)
			printf("LRRL");
		printf("LRRLRFRFRL");
		for (i = 0; i < k; i++)
			printf("LRRL");
		for (i = 0; i < l - 1; i++)
			putchar('F');
		putchar('R');
        } else if (t >=16 && ((t - 16) % 8 == 0 ||
                (t - 17) % 8 == 0 || (t - 18) % 8 == 0
                || (t - 19) % 8 == 0)) {
		k = (t - 8) / 8;

		printf("%d\n", 8 + 8*k + 2*l);
		putchar('R');
		for (i = 0; i < l; i++)
			putchar('F');
		for (i = 0; i < k - 1; i++)
			printf("LRRL");
		printf("LRLRRLRRLRLRRL");
		for (i = 0; i < k - 1; i++)
			printf("LRRL");
		for (i = 0; i < l; i++)
			putchar('F');
		putchar('R');
	} else  {
		k = (t - 4) / 8;

		printf("%d\n", 4 + 8*k + 2*l);
		putchar('R');
		for (i = 0; i < l; i++)
			putchar('F');
		for (i = 0; i < k; i++)
			printf("LRRL");
		printf("RR");
		for (i = 0; i < k; i++)
			printf("LRRL");
		for (i = 0; i < l; i++)
			putchar('F');
		putchar('R');
	}

	return 0;
}
