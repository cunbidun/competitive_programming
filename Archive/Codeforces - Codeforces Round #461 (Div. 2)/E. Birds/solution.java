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
        HBirds solver = new HBirds();
        solver.solve(1, in, out);
        out.close();
    }

    static class HBirds {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long w = in.nextLong();
            long b = in.nextLong();
            long x = in.nextLong();
            int[] c = new int[n + 1];
            long[] cost = new long[n + 1];
            int tot = 0;
            int ans = 0;

            for (int i = 1; i <= n; i++) {
                c[i] = in.nextInt();
                tot += c[i];
            }
            for (int i = 1; i <= n; i++) {
                cost[i] = in.nextLong();
            }
            long[][] f = new long[n + 1][tot + 1];
            for (int i = 0; i <= n; i++) {
                Arrays.fill(f[i], -1);
            }
            f[0][0] = w;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= tot; j++) {
                    for (int k = 0; k <= Math.min(j, c[i]); k++) {
                        if (f[i - 1][j - k] != -1) {
                            long tmp = Math.min(w + (j - k) * b, f[i - 1][j - k] + x) - cost[i] * k;
                            if (tmp >= 0) {
                                f[i][j] = Math.max(f[i][j], tmp);
                                ans = Math.max(ans, j);
                            }
                        }
                    }
                }
            }
            out.println(ans);
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
}