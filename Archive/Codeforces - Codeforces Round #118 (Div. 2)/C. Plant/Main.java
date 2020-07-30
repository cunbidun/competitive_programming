import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task186C solver = new Task186C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task186C {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int[][] b = new int[3][3];
            b[1][1] = 3;
            b[1][2] = 1;
            b[2][1] = 1;
            b[2][2] = 3;
            long n = in.nextLong();
            b = MatrixOp.powMatrix(b, n, (int) (1e9 + 7));
            int[][] ans = new int[2][3];
            ans[1][1] = 1;
            ans[1][2] = 0;
            ans = MatrixOp.mulMatrixMatrix(ans, b);
            out.println(ans[1][1]);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

    }

    static class MatrixOp {
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

        public static int[][] mulMatrixMatrix(int[][] x, int[][] y) {
            int xR = x.length - 1;
            int xC = x[1].length - 1;
            int yC = y[1].length - 1;
            int[][] ans = new int[xR + 1][yC + 1];
            for (int i = 1; i <= xR; i++) {
                for (int j = 1; j <= yC; j++) {
                    for (int l = 1; l <= xC; l++) {
                        ans[i][j] += (x[i][l] * y[l][j]);
                    }
                }
            }
            return ans;
        }

    }
}