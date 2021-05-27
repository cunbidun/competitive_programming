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
        CMedianSmoothing solver = new CMedianSmoothing();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMedianSmoothing {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int cnt = 0;
            int ans = 0;

            int pos = INF;
            for (int i = 2; i <= n; i++) {
                if (i != n && a[i] != a[i - 1] && a[i] != a[i + 1]) {
                    pos = MaxMin.Min(pos, i - 1);
                    cnt++;
                } else {
                    if (pos == INF) continue;
                    ans = MaxMin.Max(ans, (i - pos - 1) / 2 + (i - pos - 1) % 2);
                    if (a[i] == a[pos]) {
                        for (int j = pos + 1; j <= i; j++) a[j] = a[pos];
                    } else {
                        for (int j = pos + 1; j <= (i + pos) / 2; j++) a[j] = a[pos];
                        for (int j = (i + pos) / 2 + 1; j < i; j++) a[j] = a[i];
                    }
                    pos = INF;
                }
            }

            out.println(ans);
            for (int i = 1; i <= n; i++) out.print(a[i] + " ");
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}