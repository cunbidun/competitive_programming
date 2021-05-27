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
        CMaximumSubrectangle solver = new CMaximumSubrectangle();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMaximumSubrectangle {
        private static final int INF = (int) 2e9 + 7;
        private int n;
        private int m;
        private int x;
        private int[] a;
        private int[] b;
        private int[] f;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextIntArray(n, 1);
            b = in.nextIntArray(m, 1);
            x = in.nextInt();
            f = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                f[i] = INF;
                a[i] += a[i - 1];
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j + i - 1 <= n; j++) {
                    f[i] = MaxMin.Min(f[i], a[j + i - 1] - a[j - 1]);
                }
            }

            for (int i = 1; i <= m; i++) {
                b[i] += b[i - 1];
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int l = 0, r = m;
                while (l != r) {
                    if (l == r - 1) {
                        if (ch(i, r)) {
                            l = r;
                        }
                        break;
                    }
                    int mid = (l + r) >> 1;
                    if (ch(i, mid)) l = mid;
                    else r = mid - 1;
                }
                ans = MaxMin.Max(ans, i * l);
            }
            out.println(ans);
        }

        private boolean ch(int cur, int mid) {
            for (int i = 1; i + mid - 1 <= m; i++) {
                if ((long) f[cur] * (b[i + mid - 1] - b[i - 1]) <= (long) x) {
                    return true;
                }
            }
            return false;
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
}