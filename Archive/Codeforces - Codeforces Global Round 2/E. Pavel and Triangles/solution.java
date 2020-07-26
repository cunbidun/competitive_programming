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
        EPavelAndTriangles solver = new EPavelAndTriangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPavelAndTriangles {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long ans = 0;
            long[] a = in.nextLongArray(n, 1);
            STPointSumLong tree = new STPointSumLong(n, a);
            for (int i = 1; i <= n; i++) {
                long curSum = tree.getSum(1, i - 1);
                long tmp = MaxMin.Min(curSum, a[i] / 2);
                ans += tmp;
                tree.update(1, -tmp);
                tree.update(i, -2 * tmp);
                curSum = tree.getSum(i, i) / 3;
                ans += curSum;
                tree.update(i, -curSum * 3);
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

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class STPointSumLong {
        private long[] segment;
        private long[] array;
        private int N;

        public STPointSumLong(int n) {
            segment = new long[4 * n];
            N = n;
        }

        public STPointSumLong(int n, long[] inputArray) {
            segment = new long[4 * n];
            this.array = inputArray;
            N = n;
            buildTree(1, 1, N);
        }

        private void buildTree(int i, int l, int r) {
            if (l > r) return;
            if (l == r) {
                segment[i] = array[l];
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
            segment[i] = segment[i * 2] + segment[i * 2 + 1];
        }

        public void update(int p, long val) {
            update(1, 1, N, p, val);
        }

        private void update(int i, int l, int r, int p, long val) {
            if (l > p || r < p) return;
            if (l == r) {
                segment[i] += val;
                return;
            }
            int m = (l + r) >> 1;
            update(i * 2, l, m, p, val);
            update(i * 2 + 1, m + 1, r, p, val);
            segment[i] = segment[i * 2] + segment[i * 2 + 1];
        }

        public long getSum(int l, int r) {
            return getSum(1, 1, N, l, r);
        }

        private long getSum(int i, int l, int r, int L, int R) {

            if (l > r || l > R || r < L) return 0;
            if (l >= L && r <= R) return segment[i];
            int m = (l + r) >> 1;
            return getSum(i * 2, l, m, L, R) + getSum(i * 2 + 1, m + 1, r, L, R);
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