#include <stdio.h>
#include <string.h>

int low(int i) {
	return i & (i+1);
}

int high(int i) {
	return i | (i+1);
}

int n;
int v[128][128][128];

int ylp(int x, int y, int z) {
	int p = 0;

	while (z >= 0) {
		p += v[x][y][z];
		z = low(z) - 1;
	}

	return p;
}

int yproduct(int x, int y, int z, int zz) {
	return ylp(x, y, zz) - ylp(x, y, z-1);
}

int xlp(int x, int y, int z, int zz) {
	int p = 0;

	while (y >= 0) {
		p += yproduct(x, y, z, zz);
		y = low(y) - 1;
	}

	return p;
}

int xproduct(int x, int y, int z, int yy, int zz) {
	return xlp(x, yy, z, zz) - xlp(x, y-1, z, zz);
}

int lp(int x, int y, int z, int yy, int zz) {
	int p = 0;

	while (x >= 0) {
		p += xproduct(x, y, z, yy, zz);
		x = low(x) - 1;
	}

	return p;
}

int product(int x, int y, int z, int xx, int yy, int zz) {
	return lp(xx, y, z, yy, zz) - lp(x-1, y, z, yy, zz);
	
}

void yupdate(int x, int y, int z, int k) {
	while (z < n) {
		v[x][y][z] += k;
		z = high(z);
	}
}

void xupdate(int x, int y, int z, int k) {
	while (y < n) {
		yupdate(x, y, z, k);
		y = high(y);
	}
}

void update(int x, int y, int z, int k) {
	while (x < n) {
		xupdate(x, y, z, k);
		x = high(x);
	}
}

int main() {
	int m, x, y, z, k, xx, yy, zz;

	memset(v, 0, sizeof(v));
		
	scanf("%d", &n);

	scanf("%d", &m);
	while (m != 3) {
		if (m == 1) {
			scanf("%d%d%d%d", &x, &y, &z, &k);
			update(x, y, z, k);
		} else if (m == 2) {
			scanf("%d%d%d%d%d%d", &x, &y, &z, &xx, &yy, &zz);
			printf("%d\n", product(x, y, z, xx, yy, zz));
		}

		scanf("%d", &m);
	}
	
	return 0;
}

