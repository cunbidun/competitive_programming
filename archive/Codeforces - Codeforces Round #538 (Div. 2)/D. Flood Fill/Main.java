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
        DFloodFill solver = new DFloodFill();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFloodFill {
        private static final int MAXA = (int) 5e3 + 10;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] compressed = new int[MAXA];
            int pos = 1;
            for (int i = 1; i <= n; i++)
                if (a[i] != a[i - 1]) {
                    compressed[pos] = a[i];
                    pos++;
                }
            int[] reCompressed = new int[MAXA];
            int cur = 1;
            for (int i = pos; i >= 1; i--) {
                reCompressed[cur] = compressed[i];
                cur++;
            }
            //out.println(cur);
            int[][] f = new int[MAXA][MAXA];
            for (int i = 1; i <= cur; i++) {
                for (int j = 1; j <= cur; j++) {
                    if (compressed[i] == reCompressed[j]) {
                        f[i][j] = f[i - 1][j - 1] + 1;
                    } else {
                        f[i][j] = MaxMin.Max(f[i - 1][j], f[i][j - 1]);
                    }
                }
            }
            out.println((cur - 3 - f[cur - 1][cur - 1] / 2));
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}