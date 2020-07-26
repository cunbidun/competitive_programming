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
        EPolicePatrol solver = new EPolicePatrol();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPolicePatrol {
        static final int MAXA = (int) 1e6 + 10;
        static final int INF = (int) 2e9 + 7;
        int n;
        int m;
        long[] a = new long[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();

            for (int i = 1; i <= n; i++) {
                a[i] = in.nextLong();
            }
            long l = -INF, r = INF;
            while (l < r) {
                long mid = (l + r) / 2;
                if (l == r - 1) {
                    out.println(Math.min(f(l), f(l + 1)));
                    break;
                }
                if (f(mid) == f(mid + 1)) {
                    out.println(f(mid));
                    break;
                }
                if (f(mid) > f(mid + 1)) l = mid + 1;
                else r = mid;
            }
            if (l >= r) {
                out.println(Math.min(f(l), f(l + 1)));
            }
        }

        private long f(long l) {
            int pos = BinarySearch.lowerBound(a, n, 1, l);
            long ans = 0;
            for (int i = n; i >= pos; i -= m) {
                ans += 2 * Math.abs(l - a[i]);
            }
            for (int i = 1; i < pos; i += m) {
                ans += 2 * Math.abs(l - a[i]);
            }
            return ans;
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

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class BinarySearch {
        public static int lowerBound(long[] array, int length, int indexSt, long value) {
            int low = indexSt;
            int high = length;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value <= array[mid]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

    }
}