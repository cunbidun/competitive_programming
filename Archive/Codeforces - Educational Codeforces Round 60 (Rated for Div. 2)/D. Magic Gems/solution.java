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
        DMagicGems solver = new DMagicGems();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMagicGems {
        private static final long MOD = (long) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            int m = in.nextInt();
            int[][] columnVector = new int[m + 1][2];
            int[][] base = new int[m + 1][m + 1];

            for (int i = 1; i <= m; i++) {
                columnVector[i][1] = 1;
                for (int j = 1; j <= m; j++) {
                    if (i >= j) base[i][j] = 1;
                }
                base[i][m] = 1;
            }
            base[m][m] = 2;

//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= m; j++) {
//                out.print(base[i][j] + " ");
//            }
//            out.println();
//        }
//        out.println();
            long power;
            if ((n + 1) % m != 0) power = (n + 1) / m;
            else power = ((n + 1) / m) - 1;
            int[][] powerBase = MatrixOperation.powMatrix(base, power, (int) MOD);
            int[][] ansVector = MatrixOperation.mulMatrixMatrix(powerBase, columnVector, (int) MOD);

//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= m; j++) {
//                out.print(powerBase[i][j] + " ");
//            }
//            out.println();
//        }
//        out.println();
            int tmp = (int) ((n + 1) % m);
            if (tmp == 0) tmp = m;
            out.println(ansVector[tmp][1]);
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

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return (x + y) % MOD;
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) (x % MOD) * (y % MOD)) % MOD);
        }

    }

    static class MatrixOperation {
        public static int[][] mulMatrixMatrix(int[][] x, int[][] y, int MOD) {
            int xR = x.length - 1;
            int xC = x[1].length - 1;
            int yC = y[1].length - 1;
            int[][] ans = new int[xR + 1][yC + 1];
            for (int i = 1; i <= xR; i++) {
                for (int j = 1; j <= yC; j++) {
                    for (int l = 1; l <= xC; l++) {
                        ans[i][j] = Op.addMod(ans[i][j], Op.mulMod(x[i][l], y[l][j], MOD), MOD);
                    }
                }
            }
            return ans;
        }

        public static int[][] powMatrix(int[][] x, long n, int MOD) {
            if (n == 0) {
                int len = x.length - 1;
                int[][] I = new int[len + 1][len + 1];
                for (int i = 1; i <= len; i++) {
                    I[i][i] = 1;
                }
                return I;
            }
            if (n == 1) return x;
            int[][] t = powMatrix(x, n / 2, MOD);
            return mulMatrixMatrix(mulMatrixMatrix(t, t, MOD), powMatrix(x, n % 2, MOD), MOD);
        }

    }
}