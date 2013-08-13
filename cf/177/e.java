import java.io.*;
import java.math.*;
import java.util.*;

public class e {
    static int n, c;
    static int[] a, b;

    static int cmp(long x) {
        BigInteger s = BigInteger.ZERO;
        for (int i = 0; i < n; i++) {
            BigInteger p = BigInteger.valueOf(a[i]).multiply(BigInteger.valueOf(x)).
                divide(BigInteger.valueOf(b[i]));
            // System.out.println("i = " + i + " s = " + p.toString());

            s = s.add(p);

//            if (s.compareTo(BigInteger.valueOf(c-n)) > 0)
 //             return 1;
        }

//        System.out.println("x = " + x + " s = " + s.toString());

        return s.compareTo(BigInteger.valueOf(c-n));
    }

    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);

        n = s.nextInt();
        c = s.nextInt();

        if (c < n) {
            System.out.println("0");
            return;
        }

        a = new int[n];
        b = new int[n];
        boolean f = true;
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
            b[i] = s.nextInt();

            if (a[i] != 0)
                f = false;
        }

        if (f) {
            if (c == n)
                System.out.println("-1");
            else
                System.out.println("0");
            return;
        }

        long l = 1, r = 1000000000000000000l;
        // long l = 1, r = 100;
        while (l < r) {
            long m = (l+r)/2;
            if (cmp(m) < 0)
                l = m+1;
            else if (cmp(m) > 0)
                r = m-1;
            else
                r = m;
        }

        if (cmp(l) != 0) {
            System.out.println("0");
            return;
        }

        long ll = l;

 //       System.out.println("ll = " + ll);

        l = 1; r = 1000000000000000000l;
        // l = 1; r = 100;
        while (l < r) {
            long m = (l+r+1)/2;

            if (cmp(m) < 0)
                l = m+1;
            else if (cmp(m) > 0)
                r = m-1;
            else
                l = m;
        }

        long rr = r;

//        System.out.println("rr = " + rr);

        System.out.println(rr-ll+1);
    }
}
