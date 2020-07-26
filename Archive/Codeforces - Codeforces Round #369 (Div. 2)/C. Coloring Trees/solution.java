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
        CColoringTrees solver = new CColoringTrees();
        solver.solve(1, in, out);
        out.close();
    }

    static class CColoringTrees {
        private static final long INFLL = (long) 9e15 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            long[][] cost = in.nextLongTable(n, m, 1, 1);
            long[][][] f = new long[n + 1][m + 1][k + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    Arrays.fill(f[i][j], INFLL);
                }
            }
            if (a[1] != 0) f[1][a[1]][1] = 0;
            else for (int i = 1; i <= m; i++) f[1][i][1] = cost[1][i];
            for (int i = 1; i <= n; i++) {
                if (a[i] != 0) {
                    for (int j = 1; j <= m; j++) {
                        for (int l = 1; l <= k; l++) {
                            if (a[i] != j) {
                                f[i][a[i]][l] = MaxMin.Min(f[i][a[i]][l], f[i - 1][j][l - 1]);
                            } else f[i][a[i]][l] = MaxMin.Min(f[i][a[i]][l], f[i - 1][j][l]);
                        }
                    }
                } else {
                    for (int j = 1; j <= m; j++) {
                        for (int l = 1; l <= m; l++) {
                            for (int o = 1; o <= k; o++) {
                                if (l != j) f[i][j][o] = MaxMin.Min(f[i][j][o], f[i - 1][l][o - 1] + cost[i][j]);
                                else f[i][l][o] = MaxMin.Min(f[i][l][o], f[i - 1][j][o] + cost[i][j]);
                            }
                        }
                    }
                }
            }
            long ans = INFLL;
            for (int i = 1; i <= m; i++) ans = MaxMin.Min(ans, f[n][i][k]);
            if (ans == INFLL) out.println(-1);

            else out.println(ans);
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        public long[][] nextLongTable(int row, int col, int rowSt, int colSt) {
            long[][] arr = new long[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextLong();
                }
            }
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}