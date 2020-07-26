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
        CPolycarpRestoresPermutation solver = new CPolycarpRestoresPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPolycarpRestoresPermutation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.nextLongArray(n - 1, 1);
            int cur = 0;
            int pos = -1;
            for (int i = 1; i <= n - 1; i++) {
                if (cur < 0) {
                    cur = 0;
                }
                cur += a[i];
                if (cur == n - 1) {
                    pos = i + 1;
                    break;
                }
            }
            if (pos == -1) {
                cur = 0;
                for (int i = 1; i <= n - 1; i++) {
                    if (cur > 0) {
                        cur = 0;
                    }
                    cur += a[i];
                    if (cur == -(n - 1)) {
                        pos = i + 1;
                        break;
                    }
                }
                if (pos == -1) {
                    out.println(-1);
                    return;
                }

                cur = 1;
                if (pos != 1) {
                    for (int i = pos - 1; i >= 1; i--) {
                        cur -= a[i];
                    }
                }
                boolean[] ch = new boolean[n + 1];
                if (cur <= 0 || cur > n) {
                    out.println(-1);
                    return;
                }
                ch[cur] = true;
                int tmp = cur;
                for (int i = 1; i <= n - 1; i++) {
                    tmp += a[i];
                    if (tmp <= 0 || tmp > n) {
                        out.println(-1);
                        return;
                    }
                    ch[tmp] = true;
                }
                for (int i = 1; i <= n; i++) {
                    if (!ch[i]) {
                        out.println(-1);
                        return;
                    }
                }
                out.print(cur + " ");
                for (int i = 1; i <= n - 1; i++) {
                    cur += a[i];
                    out.print(cur + " ");
                }
                return;
            }
            cur = n;
            if (pos != 1) {
                for (int i = pos - 1; i >= 1; i--) {
                    cur -= a[i];
                }
            }
            boolean[] ch = new boolean[n + 1];
            if (cur <= 0 || cur > n) {
                out.println(-1);
                return;
            }
            ch[cur] = true;
            int tmp = cur;
            for (int i = 1; i <= n - 1; i++) {
                tmp += a[i];
                if (tmp <= 0 || tmp > n) {
                    out.println(-1);
                    return;
                }
                ch[tmp] = true;
            }
            for (int i = 1; i <= n; i++) {
                if (!ch[i]) {
                    out.println(-1);
                    return;
                }
            }
            out.print(cur + " ");
            for (int i = 1; i <= n - 1; i++) {
                cur += a[i];
                out.print(cur + " ");
            }
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