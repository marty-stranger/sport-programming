int main() {
	int n, k, i, j, b;
	long long s, c1[11], c11[11], c2[11], c21[11];

	scanf("%d%d", &n, &k);

	s = 0;
	if (n % 2) {
		memset(c1, 0, sizeof(c1));
		memset(c11, 0, sizeof(c11));
		c1[0] = 1;
		for (i = 1; i <= n; i++) {
			if (i % 2)
				b = i;
			else
				b = i-1;

			c11[0] = 1;
			for (j = 1; j <= i && j <= k; j++)
				c11[j] = c1[j] + c1[j-1]*(b - j+1);

			memcpy(c1, c11, sizeof(c1));
		}

		memset(c2, 0, sizeof(c2));
		memset(c21, 0, sizeof(c21));
		c2[0] = 1;
		for (i = 1; i <= n-1; i++) {
			if (i % 2)
				b = i+1;
			else
				b = i;

			c21[0] = 1;
			for (j = 1; j <= i && j <= k; j++)
				c21[j] = c2[j] + c2[j-1]*(b -j+1);

			memcpy(c2, c21, sizeof(c2));			
		}

		for (i = 0; i <= k; i++)
			if (i <= n && k-i <= n)
				s += c1[i]*c2[k-i];			       	
	} else {
		memset(c1, 0, sizeof(c1));
		memset(c11, 0, sizeof(c11));
		c1[0] = 1;
		for (i = 1; i <= n-1; i++) {
			if (i % 2)
				b = i+1;
			else
				b = i;

			c11[0] = 1;
			for (j = 1; j <= i && j <= k; j++)
				c11[j] = c1[j] + c1[j-1]*(b -j+1);

			memcpy(c1, c11, sizeof(c1));
		}

		for (i = 0; i <= k; i++)
			if (i <= n && k-i <= n)
			s += c1[i]*c1[k-i];
	}

	printf("%lld", s);

	return 0