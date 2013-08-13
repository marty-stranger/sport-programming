#include <math.h>
#include <stdio.h>

int main() {
	int ad, ac, bd, bc;

	double cosalpha2;

	scanf("%d%d%d%d", &ad, &ac, &bd, &bc);

	if (bc*ac == bd*ad)
		puts("Impossible.");
	else {
		cosalpha2 = (1.0 * bc*bc + bd*bd - ac*ac - ad*ad) / (1.0*bc*bd - ac*ad);
		printf("Distance is %.0lf km.", sqrt(1.0*bc*bc + bd*bd - bc*bd*cosalpha2)*1000);
	}
	
	return 0;
}
