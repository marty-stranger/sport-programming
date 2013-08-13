#include <stdio.h>
#include <sys/time.h>
#include <time.h>

struct timespec start_time;

void start() {
	clock_gettime(CLOCK_REALTIME, &start_time);
}

void end() {
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	fprintf(stderr, "%lf\n", ((end.tv_sec - start_time.tv_sec)*0 + (end.tv_sec - start_time.tv_nsec)) / 1e9);
}


int a[1000000];

void s(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, p = a[(l + r) / 2];
	while (i <= j)
		if (a[i] < p)
			i++;
		else if (a[j] > p)
			j--;
		else {
			int t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	s(l, j); s(i, r);
}

int main() {
	start();
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	end();

	start();
	s(0, n - 1);
	end();

	start();
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
	end();

	return 0;
}
