// ok
#include <stdio.h>
#include <string.h>

int main() {
	long long a;
	int n, i, j, r, c, cc, b[4];
	char s[21];

	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(s);

		a = 0; c = cc = 0;
		b[0] = b[1] = b[2] = b[3] = 0;
		for (j = 0; j < strlen(s); j++)
			if (0 < s[j] - '0' && s[j] - '0' <= 4 && !b[s[j] - '0' - 1])
				b[s[j] - '0' - 1] = 1;
		        else {
		        	if (s[j] != '0') {
		        		cc++;
			        	a *= 10;
			        	a += s[j] - '0';
		        	} else
		        		c++;
		        }

		if (cc == 0) {
			printf("3241");
			for (j = 0; j < c; j++)
				putchar('0');
		} else {
			for (j = 0; j < c; j++)
				a *= 10;

		        printf("%I64d", a); // exclusive for intel c 7
		        // printf("%lld", a);

		        r = ((a % 7) * (10000 % 7)) % 7;
		        // printf("r = %d\n", r);
			r = 7 - r;
		        if (r == 7)
		        	puts("3241");
		        else if (r == 1)
		        	puts("1324");
		        else if (r == 2)
		        	puts("1234");
		        else if (r == 3)
		        	puts("2341");
		        else if (r == 4)
		        	puts("1243");
		        else if (r == 5)
		        	puts("1342");
		        else if (r == 6)
		        	puts("2134");
		}
		putchar('\n');
	}

	return 0;
}
