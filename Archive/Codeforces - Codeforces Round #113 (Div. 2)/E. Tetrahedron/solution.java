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
        ETetrahedron solver = new ETetrahedron();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETetrahedron {
        static final long MOD = (long) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[][] f = new long[5][5];
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    if (i != j) f[i][j] = 1;
                }
            }
            long[][] ans = new long[5][2];
            for (int i = 1; i <= 3; i++) ans[i][1] = 1;
            ans[4][1] = 0;
            ans = MatrixOperation.mulMatrixMatrix(MatrixOperation.powMatrix(f, (long) n - 1, MOD), ans, MOD);
            out.println(ans[4][1]);
        }

    }

    static class MatrixOperation {
        public static long[][] mulMatrixMatrix(long[][] x, long[][] y, long MOD) {
            int xR = x.length - 1;
            int xC = x[1].length - 1;
            int yC = y[1].length - 1;
            long[][] ans = new long[xR + 1][yC + 1];
            for (int i = 1; i <= xR; i++) {
                for (int j = 1; j <= yC; j++) {
                    for (int l = 1; l <= xC; l++) {
                        ans[i][j] = ModularArithmetic.add(ans[i][j], ModularArithmetic.mul(x[i][l], y[l][j], MOD), MOD);
                    }
                }
            }
            return ans;
        }

        public static long[][] powMatrix(long[][] x, long n, long MOD) {
            if (n == 0) {
                int len = x.length - 1;
                long[][] I = new long[len + 1][len + 1];
                for (int i = 1; i <= len; i++) {
                    I[i][i] = 1;
                }
                return I;
            }
            if (n == 1) return x;
            long[][] t = powMatrix(x, n / 2, MOD);
            return mulMatrixMatrix(mulMatrixMatrix(t, t, MOD), powMatrix(x, n % 2, MOD), MOD);
        }

    }

    static class ModularArithmetic {
        public static long add(long x, long y, long MOD) {
            return (x + y) % MOD;
        }

        public static long mul(long x, long y, long MOD) {
            return ((x % MOD) * (y % MOD)) % MOD;
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

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}