int main() {
	int s = 0;
	// int dx[] = {1,2,3,4}, dy[] = {4,3,2,1};
	for (int i = 0; i < (int)1e8; i++) {
		int x = (int[]){1,2,3,4}[i%4],
		   y = (int[]){4,3,2,1}[i%4];
		// int x = dx[i%4], y = dy[i%4];
		s += x + y;
	}

	return 0;
}
