int main() {
	struct point { int x, y; };

	point a;
	a = (point) { 1, 1 };

	int s = 0;
	for (int i = 0; i < n; i++) {
		int dx = (int[]){1,2,3,4}[i%4],
		   dy = (int[]){4,3,2,1}[i%4];
		s += dx + dy;
	}

	return 0;
}
