/* tle */
import java.io.*;
import java.util.*;

public class e {
	void run() throws IOException {
		List<String> a = new ArrayList<String>();

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String ss = in.readLine();
		while (ss != null) {
			a.add(ss);
			ss = in.readLine();
		}

		in.close();
	
		Collections.sort(a, new Comparator<String>() {
			public int compare(String s1, String s2) {
				int l1 = s1.length();
				int l2 = s2.length();

				int i = 0, j = 0, d = 0;
				while (i < l1 && j < l2)
					if (Character.isDigit(s1.charAt(i)) && Character.isDigit(s2.charAt(j))) {
						int i1 = i, j1 = j;
						while (i < l1 && s1.charAt(i) == '0')
							i++;
						while (j < l2 && s2.charAt(j) == '0')
							j++;

						int i2 = i, j2 = j;
						while (i < l1 && Character.isDigit(s1.charAt(i)))
							i++;
						while (j < l2 && Character.isDigit(s2.charAt(j)))
							j++;

						if (i - i2 != j - j2)
							return i - i2 - (j - j2);

						for (int ii = 0; ii < i - i2; ii++)
							if (s1.charAt(i2 + ii) != s2.charAt(j2 + ii))
								return s1.charAt(i2 + ii) - s2.charAt(j2 + ii);

						if (i - i1 != j - j1 && d == 0)
							d = j - j1 - (i - i1);
					} else {
						if (s1.charAt(i) != s2.charAt(j))
							return s1.charAt(i) - s2.charAt(j);

						i++; j++;
					}

				if (i < l1)
					return 1;
				if (j < l2)
					return -1;

				if (d != 0)
					return d;

				return 0;
			}
		});

		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		for (String s : a)
			out.println(s);

		out.close();
	}

	public static void main(String[] args) throws IOException {
		new e().run();
	}
}
