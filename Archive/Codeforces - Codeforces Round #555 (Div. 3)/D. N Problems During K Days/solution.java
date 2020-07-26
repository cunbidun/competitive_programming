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
        DNProblemsDuringKDays solver = new DNProblemsDuringKDays();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNProblemsDuringKDays {
        private InputReader in;
        private PrintWriter out;
        private long n;
        private long k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextLong();
            k = in.nextLong();
            int sum = 0;
            long[] a = new long[100010];
            if (k * (k + 1) / 2 > n) {
                out.println("NO");
                return;
            }
            int pos;
            int l = 1, r = 1000000000;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(r)) l = r;
                    break;
                }
                int m = (l + r) >> 1;
                if (ch(m)) l = m;
                else r = m - 1;
            }
            pos = l;
            long tmp = pos;
            for (int i = 1; i <= k; i++) {
                a[i] = tmp;
                tmp++;
            }
            tmp = n - (long) k * (pos + pos + k - 1) / 2;
            int cur = 1;
            while (tmp > 0) {
                for (long i = k; i >= cur; i--) {
                    if (i != 1 && a[(int) i] + 1 > 2 * a[(int) (i - 1)]) {
                        cur++;
                        break;
                    }
                    a[(int) i]++;
                    tmp--;
                    if (tmp == 0) break;
                }
                if (tmp == 0) break;
                if (cur > k) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
            for (int i = 1; i <= k; i++) {
                out.print(a[i] + " ");
            }
        }

        private boolean ch(int m) {
            return k * (m + m + k - 1) / 2 <= n;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}