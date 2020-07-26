import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        Task92D solver = new Task92D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task92D {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private OutputWriter out;
        private int[][] rmq = new int[100010][20];
        private int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            for (int i = 1; i <= n; i++) Arrays.fill(rmq[i], INF);
            for (int i = 1; i <= n; i++) rmq[i][0] = a[i];
            for (int j = 1; j <= 18; j++) {
                for (int i = 1; i <= n; i++) {
                    rmq[i][j] = MaxMin.Min(rmq[i][j - 1], rmq[MaxMin.Min(i + (1 << (j - 1)), n)][j - 1]);
                }
            }
            for (int i = 1; i <= n; i++) {
                int l = i;
                int r = n;
                while (l != r) {
                    if (l == r - 1) {
                        if (ch(r, a[i])) l = r;
                        break;
                    }
                    int m = (r + l) >> 1;
                    if (ch(m, a[i])) l = m;
                    else r = m - 1;
                }
                out.print((l - i - 1) + " ");
            }
        }

        private boolean ch(int r, int x) {
            return x > getMin(r, n);
        }

        private int getMin(int i, int j) {
            if (i > j) {
                int t = i;
                i = j;
                j = t;
            }

            int p = 1;
            int cnt = 0;
            while (p * 2 <= j - i + 1) {
                p *= 2;
                cnt++;
            }
            return MaxMin.Min(rmq[i][cnt], rmq[j - (1 << cnt) + 1][cnt]);
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

        public void print(String i) {
            out.print(i);
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
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