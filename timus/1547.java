import java.math.*;
import java.util.*;

public class f {
	String letters(BigInteger n) {
		String s = "";

		BigInteger c = BigInteger.ZERO;
		int k = 1;

		BigInteger cc = c.add(BigInteger.ONE).multiply(BigInteger.valueOf(26));
		while (n.compareTo(cc) >= 0) {
			c = cc;
			cc = c.add(BigInteger.ONE).multiply(BigInteger.valueOf(26));
			k++;
		}
		
		n = n.subtract(c);
		
		for (int i = 0; i < k; i++) {
			s = (char)('a' + n.remainder(BigInteger.valueOf(26)).intValue()) + s;
			n = n.divide(BigInteger.valueOf(26));
		}

		return s;
	}
		
	void run() {
		Scanner in = new Scanner(System.in);

		int n = in.nextInt(), m = in.nextInt();

		in.close();

		letters(BigInteger.valueOf(26));
		letters(BigInteger.valueOf(27));
		letters(BigInteger.valueOf(215));

		BigInteger c = BigInteger.ZERO;
		for (int i = 0; i < n; i++)
			c = c.add(BigInteger.ONE).multiply(BigInteger.valueOf(26));

		BigInteger[] dr = c.divideAndRemainder(BigInteger.valueOf(m));
		BigInteger cc = dr[0];
		int k = dr[1].intValue();

		BigInteger s = BigInteger.ZERO;
		for (int i = 0; i < m; i++) {
			BigInteger e = s.add(cc);
			if (i < k)
				e = e.add(BigInteger.ONE);

			System.out.printf("%s-%s%n", letters(s), letters(e.subtract(BigInteger.ONE)));

			s = e;
		}
	}

	public static void main(String[] args) {
		new f().run();
	}
}
