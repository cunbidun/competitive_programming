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
        CPresent solver = new CPresent();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPresent {
        private InputReader in;
        private PrintWriter out;
        private int n;
        private int w;
        private long m;
        private long[] a;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            m = in.nextInt();
            w = in.nextInt();
            a = in.nextLongArray(n, 1);
            long l = ArrayAlgorithm.getMin(a, 1, n);
            long r = l + m;
            while (l != r) {
                if (l == (r - 1)) {
                    if (ch(r)) l = r;
                    break;
                }
                long mid = (l + r) >> 1;
                if (ch(mid)) l = mid;
                else r = mid - 1;
            }
            out.println(l);
        }

        private boolean ch(long mid) {
            STRangeAddSumLong st = new STRangeAddSumLong(n, a);
            long res = 0;
            for (int i = 1; i <= n; i++) {
                long tmp = st.getSum(i, i);
                if (tmp < mid) {
                    st.update(i, MaxMin.Min(n, i + w - 1), mid - tmp);
                    res += mid - tmp;
                }
            }
            return res <= m;
        }

    }

    static class ArrayAlgorithm {
        public static long getMin(long[] array, int stIndex, int enIndex) {
            long min = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                min = MaxMin.Min(min, array[i]);
            }
            return min;
        }

    }

    static class STRangeAddSumLong {
        private long[] segment;
        private long[] lazy;
        private long[] array;
        private int N;

        public STRangeAddSumLong(int n) {
            segment = new long[4 * n];
            lazy = new long[4 * n];
            N = n;
        }

        public STRangeAddSumLong(int n, long[] inputArray) {
            segment = new long[4 * n];
            lazy = new long[4 * n];
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

        private void trueVal(int i, int l, int r) {
            if (lazy[i] == 0) return;
            segment[i] += lazy[i] * (r - l + 1);
            if (l != r) {
                lazy[i * 2] += lazy[i];
                lazy[i * 2 + 1] += lazy[i];
            }
            lazy[i] = 0;
        }

        public void update(int l, int r, long val) {
            update(1, 1, N, l, r, val);
        }

        private void update(int i, int l, int r, int L, int R, long val) {
            trueVal(i, l, r);
            if (l > r || l > R || r < L) return;
            if (l >= L && r <= R) {
                segment[i] += val * (r - l + 1);
                if (l != r) {
                    lazy[i * 2] += val;
                    lazy[i * 2 + 1] += val;
                }
                return;
            }
            int m = (l + r) >> 1;
            update(i * 2, l, m, L, R, val);
            update(i * 2 + 1, m + 1, r, L, R, val);
            segment[i] = segment[i * 2] + segment[i * 2 + 1];
        }

        public long getSum(int l, int r) {
            return getSum(1, 1, N, l, r);
        }

        private long getSum(int i, int l, int r, int L, int R) {
            trueVal(i, l, r);
            if (l > r || l > R || r < L) return 0;
            if (l >= L && r <= R) return segment[i];
            int m = (l + r) >> 1;
            return getSum(i * 2, l, m, L, R) + getSum(i * 2 + 1, m + 1, r, L, R);
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}