import java.io.*;
import java.math.*;
import java.util.*;

public class d {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);

		int n; n = s.nextInt();

		if (n == 2) {
			System.out.println("-1");
			return;
		}

		/* int[] p = new int[2500];
		int i = 3, pn = 0;

		p[pn] = 2;
		pn++;

		while (pn < n*(n-1)/2) {
			boolean y = true;
			for (int j = 0; j < pn && p[j]*p[j] <= i; j++)
				if (i % p[j] == 0) {
					y = false;
					break;
				}

			if (y) {
				// System.out.println(i);
				p[pn] = i;
				pn++;
			}

			i += 2;
		} */

		BigInteger[] a = new BigInteger[50];
		a[0] = BigInteger.valueOf(6);
		a[1] = BigInteger.valueOf(10);
		a[2] = BigInteger.valueOf(15);
		for (int i = 3; i < n; i++)
			a[i] = a[i-3].multiply(BigInteger.valueOf(2));

		for (int i = 0; i < n; i++)
			System.out.println(a[i].toString());
	}
}

