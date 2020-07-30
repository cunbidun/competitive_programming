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
        CClassyNumbers solver = new CClassyNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class CClassyNumbers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                long l = in.nextLong();
                long r = in.nextLong();
                long ans = 0;
                while (cnt(r) < 3) {
                    ans++;
                    r--;
                }
                while (cnt(l - 1) < 3) {
                    ans--;
                    l--;
                }
                out.println(sol(r) - sol(l - 1) + ans);
            }

        }

        private int cnt(long r) {
            int cnt = 0;
            while (r != 0) {
                if (r % 10 != 0) cnt++;
                r /= 10;
            }
            return cnt;
        }

        private long sol(long x) {
            if (x <= 1110) return x;
            long ans = 0;
            String tmp = Long.toString(x);
            int n = tmp.length();
            ans += C(n - 1, 3) * 9 * 9 * 9 + C(n - 1, 2) * 9 * 9 + (n - 1) * 9;
            ans += (tmp.charAt(0) - '0' - 1) * (C(n - 1, 2) * 9 * 9 + (n - 1) * 9 + 1);

            int pos = 0;
            int val = 0;
            for (int i = 1; i < n; i++) {
                if (tmp.charAt(i) != '0') {
                    val = tmp.charAt(i) - '0';
                    pos = i;
                    break;
                }
            }

            ans += C(n - pos - 1, 2) * 9 * 9 + 9 * (n - pos - 1) + 1;
            ans += (val - 1) * ((n - pos - 1) * 9 + 1);

            for (int i = pos + 1; i < n; i++) {
                if (tmp.charAt(i) != '0') {
                    val = tmp.charAt(i) - '0';
                    pos = i;
                    break;
                }
            }

            ans += (n - pos - 1) * 9;
            ans++;
            ans += val;
            return ans;
        }

        private long C(int n, int k) {
            double res = 1;
            for (int i = 1; i <= k; ++i)
                res = res * (n - k + i) / i;
            return (long) (res + 0.01);
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}