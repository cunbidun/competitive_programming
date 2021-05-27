import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        EGuessTheRoot solver = new EGuessTheRoot();
        solver.solve(1, in, out);
        out.close();
    }

    static class EGuessTheRoot {
        private static final int MOD = (int) 1e6 + 3;
        private InputReader in;
        private PrintWriter out;
        private int[] co;
        private MOD mod = new MOD(MOD);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int[][] A = new int[11][11];
            int[] B = new int[11];
            for (int i = 0; i <= 10; i++) B[i] = ask(i);
            for (int i = 0; i <= 10; i++) {
                A[i][0] = 1;
                for (int j = 1; j < 11; j++) {
                    A[i][j] = mod.mulMod(A[i][j - 1], i);
                }
            }
            co = lsolve(A, B);
            for (int i = 0; i <= 1000002; i++) {
                if (cal(i) == 0) {
                    ans(i);
                    return;
                }
            }
            ans(-1);
        }

        private int cal(int x) {
            int res = 0;
            for (int i = 0; i < 11; i++) {
                res = mod.addMod(res, mod.mulMod(co[i], mod.powMod(x, i)));
            }
            return res;
        }

        private int ask(int x) {
            out.println("? " + x);
            out.flush();
            return in.nextInt();
        }

        private void ans(int x) {
            out.println("! " + x);
            out.flush();
        }

        private int[] lsolve(int[][] A, int[] b) {
            int n = b.length;
            System.out.println();
            for (int p = 0; p < n; p++) {
                int max = p;
                for (int i = p + 1; i < n; i++) {
                    if (Math.abs(A[i][p]) > Math.abs(A[max][p])) {
                        max = i;
                    }
                }
                int[] temp = A[p];
                A[p] = A[max];
                A[max] = temp;
                int t = b[p];
                b[p] = b[max];
                b[max] = t;

                for (int i = p + 1; i < n; i++) {
                    int alpha = mod.mulMod(A[i][p], mod.inv(A[p][p]));
                    b[i] = mod.subMod(b[i], mod.mulMod(alpha, b[p]));
                    for (int j = p; j < n; j++) {
                        A[i][j] = mod.subMod(A[i][j], mod.mulMod(alpha, A[p][j]));
                    }
                }
            }
            int[] x = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int sum = 0;
                for (int j = i + 1; j < n; j++) sum = mod.addMod(sum, mod.mulMod(A[i][j], x[j]));
                x[i] = mod.mulMod(mod.subMod(b[i], sum), mod.inv(A[i][i]));
            }
            return x;
        }

    }

    static class MOD {
        private int MOD;

        public MOD(int MOD) {
            this.MOD = MOD;
        }

        public int addMod(int x, int y) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public int subMod(int x, int y) {
            return ((x - y) < 0 ? x - y + MOD : x - y);
        }

        public int mulMod(int x, int y) {
            return (int) (((long) x * y) % MOD);
        }

        public int powMod(int x, long p) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t), x);
            return mulMod(t, t);
        }

        public int inv(int x) {
            return powMod(x, MOD - 2);
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