#include <stdio.h>

int n, a[100000];

void init() {
	n = 0;
}

void up(int i) {
	int v = a[i];
	while (i != 0) {
		int j = (i-1)/2;

		if (!(v < a[j]))
			break;

		a[i] = a[j];
		i = j;
	}

	a[i] = v;
}

void insert(int v) {
	a[n] = v; n++;
	up(n-1);
}

void down(int i) {
	int v = a[i];
	while (2*i+1 < n) {
		int j = 2*i+1;
		if (j+1 < n && a[j+1] < a[j])
			j++;

		if (!(v > a[j]))
			break;

		a[i] = a[j];
		i = j;
	}

	a[i] = v;
}


int extract() {
	int v = a[0];
	a[0] = a[n-1];
	n--;

	down(0);

	return v;
}

void print() {
	for (int *v = a; v != a+n; v++)
		printf("%d ", *v);
	putchar('\n');
}

int main() {
	init();

	for (;;) {
		char c[100]; scanf("%s", c);
		switch (c[0]) {
			int v;

			case 'i':
				scanf("%d", &v);
				insert(v);
				break;
			case 'e':
				printf("%d\n", extract());
				break;
			// case 'd':
			//	int i, d; scanf("%d%d", &i, &d);
			//	decrease(&h, i, d);
			//	break;
			case 'p':
				print();
				break;
		}
	}

	return 0;
}
