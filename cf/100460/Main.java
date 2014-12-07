import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		D solver = new D();
		solver.solve(1, in, out);
		out.close();
	}
}

class D {
    static final char FOREST = 'F';
    static final char PLAIN = '.';

    static final int INF = (int) 1e9;

    static final int[] DX = {0, 1, 0, -1};
    static final int[] DY = {1, 0, -1, 0};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        int v = in.readInt();
        int startX = in.readInt() - 1, startY = in.readInt() - 1;
        int finishX = in.readInt() - 1, finishY = in.readInt() - 1;
        char[][] a = IOUtils.readTable(in, n, m);
        a[startX][startY] = FOREST;
        a[finishX][finishY] = FOREST;

        // v == 4
        // [#][1][2][1][#]    - maxDist = 2, canGoFromMaxDist = false
        // [#][1][2][2][1][#] - maxDist = 2, canGoFromMaxDist = false
        // v == 5
        // [#][1][2][1][#]    - maxDist = 2, canGoFromMaxDist = true
        // [#][1][2][2][1][#] - maxDist = 2, canGoFromMaxDist = true
        int maxDist = v / 2;
        boolean canGoFromMaxDist = v % 2 != 0;

        boolean[][][] validEdge = new boolean[4][n][m];
        int[][] dist = new int[n][m];
        ArrayUtils.fill(dist, INF);
        int[] queueX = new int[n * m];
        int[] queueY = new int[n * m];
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != FOREST && a[i][j] != PLAIN) {
                    throw new RuntimeException("Wrong character in matrix");
                }
                if (a[i][j] == FOREST) {
                    queueX[tail] = i;
                    queueY[tail++] = j;
                    dist[i][j] = 0;
                }
            }
        }
        while (head < tail) {
            int curX = queueX[head];
            int curY = queueY[head++];
            if (dist[curX][curY] > maxDist) {
                continue;
            }
            if (dist[curX][curY] == maxDist && !canGoFromMaxDist) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int newX = curX + DX[k];
                int newY = curY + DY[k];
                if (MiscUtils.isValidCell(newX, newY, n, m)) {
                    if (dist[newX][newY] > dist[curX][curY] + 1) {
                        dist[newX][newY] = dist[curX][curY] + 1;
                        queueX[tail] = newX;
                        queueY[tail++] = newY;
                        validEdge[k][curX][curY] = true;
                        validEdge[(k + 2) % 4][newX][newY] = true;
                        continue;
                    }
                    if (dist[newX][newY] <= dist[curX][curY] + 1) {
                        validEdge[k][curX][curY] = true;
                        validEdge[(k + 2) % 4][newX][newY] = true;
                    }
                }
            }
        }

        int[][] dist2 = new int[n][m];
        ArrayUtils.fill(dist2, INF);
        head = tail = 0;
        queueX[tail] = startX;
        queueY[tail++] = startY;
        dist2[startX][startY] = 0;
        while (head < tail) {
            int curX = queueX[head];
            int curY = queueY[head++];
            if (dist[curX][curY] > maxDist) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int newX = curX + DX[k];
                int newY = curY + DY[k];
                if (MiscUtils.isValidCell(newX, newY, n, m)) {
                    if (validEdge[k][curX][curY]) {
                        if (dist2[newX][newY] > dist2[curX][curY] + 1) {
                            dist2[newX][newY] = dist2[curX][curY] + 1;
                            queueX[tail] = newX;
                            queueY[tail++] = newY;
                        }
                    }
                }
            }
        }

        if (dist2[finishX][finishY] < INF) {
            out.printLine("Hello, Deimos!");
        } else {
            out.printLine("Dire victory");
        }
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}

class MiscUtils {

    public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	}

