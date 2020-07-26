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
        BPermutations solver = new BPermutations();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPermutations {
        private static final int INF = (int) 2e9 + 7;
        private int n;
        private int k;
        private boolean[] used = new boolean[10];
        private int[] a = new int[10];
        private int ans = INF;
        private char[][] c;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            c = in.nextCharTable(n, k, 1, 1);
            bt(1);
            out.println(ans);
        }

        private void bt(int pos) {
            if (pos == k + 1) {

                int max = 0;
                int min = INF;
                for (int i = 1; i <= n; i++) {
                    int cur = 0;
                    for (int j = 1; j <= k; j++) {
                        cur *= 10;
                        cur += c[i][a[j]] - '0';
                    }
                    max = MaxMin.Max(max, cur);
                    min = MaxMin.Min(min, cur);
                }
                ans = MaxMin.Min(ans, max - min);
            }
            for (int i = 1; i <= k; i++)
                if (!used[i]) {
                    a[pos] = i;
                    used[i] = true;
                    bt(pos + 1);
                    used[i] = false;
                }
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public char[][] nextCharTable(int row, int col, int rowSt, int colSt) {
            char[][] arr = new char[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextCharacter();
                }
            }
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}