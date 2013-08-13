#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define llabs _abs64

int main() {
	int n, i, j, fa, fb;
	long long max;

	scanf("%d", &n);
	scanf("%d", &fa);
	max = 0;
	for (i = 1; i < n; ++i) {
		scanf("%d", &fb);		

		if (llabs((long long)fb - fa) > max) {
			max = llabs((long long)fb - fa);
			j = i;
		}

		fa = fb; 
	}

	printf("%d %d\n", j, j+1);

	return 0;
}
