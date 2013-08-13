import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {
	private static BigInteger det(BigInteger a[][]) {
		return BigInteger.ZERO.
			add(a[0][0].multiply(a[1][1]).multiply(a[2][2])).
			add(a[0][1].multiply(a[1][2]).multiply(a[2][0])).
			subtract(a[0][2].multiply(a[1][1]).multiply(a[2][0])).
			subtract(a[0][0].multiply(a[1][2]).multiply(a[2][1])).
			subtract(a[0][1].multiply(a[1][0]).multiply(a[2][2])).
			add(a[0][2].multiply(a[1][0]).multiply(a[2][1]));
	}

	public static int count(BigInteger a, BigInteger b, BigInteger c, BigInteger d) {
		if (a.add(b).add(c).add(d).equals(BigInteger.ZERO))
			return 0;

		return count(b.subtract(a).abs(),
				c.subtract(b).abs(),
				d.subtract(c).abs(),
				a.subtract(d).abs()) + 1;
	}

	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new FileInputStream("input.txt"));

		PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));

		int n = s.nextInt();

		if (n == 0) {
			out.println("0 0 0 0");
			out.close();
			return;
		}
		
		if (n == 1) {
			out.println("1 1 1 1");
			out.close();
			return;
		}

		BigInteger[][] a = new BigInteger[4][3];
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 4; k++)
				a[k][j] = BigInteger.ZERO;
		a[1][0] = a[2][1] = a[3][2] = BigInteger.ONE;

		BigInteger[][] b = new BigInteger[4][3];
		for (int i = 0; i < n-2; i++) {
			for (int j = 0; j < 3; j++) {
				b[0][j] = a[1][j].subtract(a[0][j]);
				b[1][j] = a[2][j].subtract(a[1][j]);
				b[2][j] = a[3][j].subtract(a[2][j]);
				b[3][j] = a[3][j].subtract(a[0][j]);
			}

			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 4; k++)
					a[k][j] = b[k][j];
		}

		for (int j = 0; j < 3; j++) {
			b[0][j] = a[1][j].subtract(a[0][j]);
			b[1][j] = a[1][j].subtract(a[2][j]);
			b[2][j] = a[3][j].subtract(a[2][j]);
			b[3][j] = a[3][j].subtract(a[0][j]);
		}

		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 4; k++)
				a[k][j] = b[k][j];

		BigInteger d = det(a);
		// System.out.println("d = " + d.toString());
		BigInteger c[] = new BigInteger[3];
		for (int p = 0; p < 1000; p++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
						a[k][j] = b[k][j];

				a[0][i] = a[1][i] = a[2][i] = BigInteger.ONE.shiftLeft(p);
				BigInteger dd = det(a);
				// System.out.println("dd = " + dd.toString());
				c[i] = dd.divide(d);
			}

			if (count(BigInteger.ZERO, c[0], c[1], c[2]) == n)
				break;
		}

		out.println("0 " + c[0].toString() + " " + c[1].toString() + " " + c[2].toString());
		out.close();
	}
}
