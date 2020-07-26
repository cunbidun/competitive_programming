import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        CSagheerAndNubianMarket solver = new CSagheerAndNubianMarket();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSagheerAndNubianMarket {
        private int n;
        private long s;
        private long[] a;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            s = in.nextLong();
            a = in.nextLongArray(n, 1);
            int l = 0, r = n;
            long ans = 0;
            while (l != r) {
                if (l == r - 1) {
                    long tmp = ch(r);
                    if (tmp != -1) {
                        ans = tmp;
                        l = r;
                    } else ans = ch(l);
                    break;
                }
                int m = (l + r) >> 1;
                long tmp = ch(m);
                if (tmp != -1) {
                    ans = tmp;
                    l = m;
                } else r = m - 1;
            }
            out.print(l + " " + ans);
        }

        private long ch(int m) {
            long[] b = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                b[i] = a[i] + (long) i * m;
            }
            Arrays.sort(b, 1, n + 1);
            long cur = 0;
            for (int i = 1; i <= m; i++) cur += b[i];
            if (cur > s) return -1;
            else return cur;
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