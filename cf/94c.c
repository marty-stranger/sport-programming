#include <stdio.h>

int main() {
	int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);

	if ((a-1)/m == (b-1)/m) {
		puts("1");
		return 0;
	}

	if ((a-1)/m + 1 == (b-1)/m) {
		if ((a-1) % m == 0 && b%m == 0)
			puts("1");
		else if ((a-1) % m != 0 && b%m == 0)
			puts("2");
		else if (b%m != 0)
			if (b == n)
				if ((a-1) % m == 0)
					puts("1");
				else
					puts("2");
			else
				if ((a-1) % m == 0)
					puts("2");
				else
					puts("2");

		return 0;
	}

	if ((a-1) % m == 0 && b%m == 0)
		puts("1");
	else if ((a-1) % m != 0 && b%m == 0)
		puts("2");
	else if (b%m != 0)
		if (b == n)
			if ((a-1) % m == 0)
				puts("1");
			else
				puts("2");
		else
			if ((a-1) % m == 0)
				puts("2");
			else if ((b-1)%m + 1 == (a-1)%m)
				puts("2");
			else
				puts("3");

	return 0;
}
