import java.io.*;
import java.util.*;

public class p1422 {
	public static int gcd(int a, int b) {
		int t;
		while (b != 0) {
			t = a % b;
			a = b;
			b = t;
		}

		return a;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int n = s.nextInt();
		
		if (n == 1) {
			System.out.println("1");
			return;
		}

		int[] x = new int[n];
		int[] y = new int[n];
		int[] z = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = s.nextInt();
			y[i] = s.nextInt();
			z[i] = s.nextInt();
		}

		final int[] dx = new int[n];
		final int[] dy = new int[n];
		final int[] dz = new int[n];
		Integer[] p = new Integer[n];

		int m = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dx[j] = x[j] - x[i];
				dy[j] = y[j] - y[i];
				dz[j] = z[j] - z[i];

				int d = gcd(Math.abs(dx[j]), gcd(Math.abs(dy[j]), Math.abs(dz[j])));
				if (d != 0) {
					dx[j] /= d;
					dy[j] /= d;
					dz[j] /= d;
				}

				p[j] = j;
			}

			Arrays.sort(p, new Comparator<Integer>() {
				public int compare(Integer i, Integer j) {
					if (dx[i] < dx[j])
						return -1;
					else if (dx[i] > dx[j])
						return 1;
					if (dy[i] < dy[j])
						return -1;
					else if (dy[i] > dy[j])
						return 1;
					if (dz[i] < dz[j])
						return -1;
					else if (dz[i] > dy[j])
						return 1;
					return 0;
				}
			});

			int c = 1;
			for (int j = 1; j < n; j++)
				if (dx[p[j]] == dx[p[j-1]] &&
						dy[p[j]] == dy[p[j-1]] &&
						dz[p[j]] == dz[p[j-1]])
					c++;
				else {
					if (c + 1 > m)
						m = c + 1;
					c = 1;
				}
			if (c + 1 > m)
				m = c + 1;

		}

		System.out.println(m);
	}
}
