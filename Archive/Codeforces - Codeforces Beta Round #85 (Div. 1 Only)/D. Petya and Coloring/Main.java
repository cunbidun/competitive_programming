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
        DPetyaAndColoring solver = new DPetyaAndColoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPetyaAndColoring {
        private static final int MOD = (int) 1e9 + 7;
        private int[] fac = new int[1000030];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            if (m == 1) {
                out.println(Op.powMod(k, n, MOD));
                return;
            }
            int ans = 0;
            fac[0] = 1;
            for (int i = 1; i <= 1000010; i++) {
                fac[i] = Op.mulMod(fac[i - 1], i, MOD);
            }
            int[][] C = MathAlgorithm.binomialTable(2010, MOD);
            int[][] f = new int[n + 1][n + 1];
            f[1][1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    f[i][j] = Op.addMod(Op.mulMod(f[i - 1][j], j, MOD), f[i - 1][j - 1], MOD);
                }
            }
            for (int j = 0; j <= n; j++) {
                for (int i = j; i <= n; i++)
                    if (2 * i - j <= k) {
                        int tmp = C(k, 2 * i - j);
                        tmp = Op.mulMod(tmp, C[2 * i - j][i - j], MOD);
                        tmp = Op.mulMod(tmp, C[i][i - j], MOD);
                        tmp = Op.mulMod(tmp, fac[i], MOD);
                        tmp = Op.mulMod(tmp, fac[i], MOD);
                        tmp = Op.mulMod(tmp, f[n][i], MOD);
                        tmp = Op.mulMod(tmp, f[n][i], MOD);
                        tmp = Op.mulMod(tmp, Op.powMod(j, n * (m - 2), MOD), MOD);
                        ans = Op.addMod(tmp, ans, MOD);
                    }
            }
            out.println(ans);
        }

        private int C(int n, int k) {
            return Op.mulMod(Op.mulMod(fac[n], Op.inv(fac[k], MOD), MOD), Op.inv(fac[n - k], MOD), MOD);
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

        public static int powMod(int x, long p, int MOD) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2, MOD);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t, MOD), x, MOD);
            return mulMod(t, t, MOD);
        }

        public static int inv(int x, int MOD) {
            return powMod(x, MOD - 2, MOD);
        }

    }

    static class MathAlgorithm {
        public static int[][] binomialTable(int n, int MOD) {
            int[][] c = new int[n + 1][n + 1];
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= i; j++)
                    c[i][j] = (j == 0) ? 1 : Op.addMod(c[i - 1][j - 1], c[i - 1][j], MOD);
            return c;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}