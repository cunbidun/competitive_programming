import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DBeautifulArray solver = new DBeautifulArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBeautifulArray {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int x = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            long[][] f = new long[n + 1][3];
            for (int i = 1; i <= n; i++) {
                f[i][2] = MaxMin.Max(0L, a[i], a[i] + f[i - 1][1], a[i] + f[i - 1][2]);
                f[i][1] = MaxMin.Max(0L, a[i] * x, a[i] * x + f[i - 1][0], a[i] * x + f[i - 1][1]);
                f[i][0] = MaxMin.Max(0L, a[i], a[i] + f[i - 1][0]);
            }
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                ans = MaxMin.Max(ans, f[i][0], f[i][1], f[i][2]);
            }
            out.println(ans);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y, T z) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            if (z.compareTo(max) > 0) max = z;
            return max;
        }

        public static <T extends Comparable<T>> T Max(T x, T y, T z, T a) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            if (z.compareTo(max) > 0) max = z;
            if (a.compareTo(max) > 0) max = a;
            return max;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
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
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}