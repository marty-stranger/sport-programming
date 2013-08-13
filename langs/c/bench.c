int main() {
	int s = 0;
	int t;
	for (int x = 0; x < (int)1e4; x++)
		for (int y = 0; y < (int)1e4; y++) {
			t = x+y;
			s += t;
		}
}
