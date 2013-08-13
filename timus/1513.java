import java.io.*;
import java.math.*;
import java.util.*;

public class c {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int n = s.nextInt();
		int k = s.nextInt();

		BigInteger[] c = new BigInteger[n + 1];

		BigInteger a = BigInteger.ONE;
		BigInteger two = BigInteger.valueOf(2);
		for (int i = 0; i <= k; i++) {
			c[i] = a;
			a = a.multiply(two);
		}

		if (k + 1 <= n) {
			int i = k + 1;
			c[i] = BigInteger.ZERO;	
			for (int j = 1; j <= k + 1; j++)
				c[i] = c[i].add(c[i - j]);
		}

		for (int i = k + 2; i <= n; i++)
			c[i] = c[i - 1].multiply(two).subtract(c[i - k - 2]);

		System.out.println(c[n]);
	}
}
