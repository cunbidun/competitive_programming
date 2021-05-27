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
        CCircularRMQ solver = new CCircularRMQ();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCircularRMQ {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            STRSumRMaxMin segmentTree = new STRSumRMaxMin(n, a);
//        out.println(segmentTree.getMin(2,4?));
            int q = in.nextInt();
            while (q-- > 0) {
                String[] inp = in.readLine().split(" ");
                int l = Integer.parseInt(inp[0]) + 1;
                int r = Integer.parseInt(inp[1]) + 1;
                if (inp.length == 3) {
                    long v = Long.parseLong(inp[2]);
                    if (l <= r)
                        segmentTree.update(l, r, v);
                    else {
                        segmentTree.update(1, r, v);
                        segmentTree.update(l, n, v);
                    }
                } else {
                    if (l <= r)
                        out.println(segmentTree.getMin(l, r));
                    else out.println(MaxMin.Min(segmentTree.getMin(1, r), segmentTree.getMin(l, n)));
                }
            }
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
            long[] arr = new long[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private String readLineHelper() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = readLineHelper();
            while (s.trim().length() == 0) {
                s = readLineHelper();
            }
            return s;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

    static class STRSumRMaxMin {
        private long[] segmentMax;
        private long[] segmentMin;
        private long[] lazyMax;
        private long[] lazyMin;
        private long[] array;
        private int N;
        private long MOD;
        private long INF = (long) 9e18 + 7;

        public STRSumRMaxMin(int n) {
            segmentMax = new long[4 * n + 10];
            segmentMin = new long[4 * n + 10];
            Arrays.fill(segmentMax, -INF);
            Arrays.fill(segmentMin, -INF);
            lazyMax = new long[4 * n + 10];
            lazyMin = new long[4 * n + 10];
            N = n;
        }

        public STRSumRMaxMin(int n, long[] inputArray) {
            segmentMax = new long[4 * n + 10];
            segmentMin = new long[4 * n + 10];
            Arrays.fill(segmentMax, -INF);
            Arrays.fill(segmentMin, -INF);
            lazyMax = new long[4 * n + 10];
            lazyMin = new long[4 * n + 10];
            this.array = inputArray;
            N = n;
            buildTree(1, 1, N);
        }

        public STRSumRMaxMin(int n, long MOD) {
            segmentMax = new long[4 * n + 10];
            segmentMin = new long[4 * n + 10];
            Arrays.fill(segmentMax, -INF);
            Arrays.fill(segmentMin, -INF);
            lazyMax = new long[4 * n + 10];
            lazyMin = new long[4 * n + 10];
            N = n;
            this.MOD = MOD;
        }

        public STRSumRMaxMin(int n, long[] inputArray, long MOD) {
            segmentMax = new long[4 * n + 10];
            segmentMin = new long[4 * n + 10];
            Arrays.fill(segmentMax, -INF);
            Arrays.fill(segmentMin, -INF);
            lazyMax = new long[4 * n + 10];
            lazyMin = new long[4 * n + 10];
            this.array = inputArray;
            N = n;
            this.MOD = MOD;
            buildTree(1, 1, N, MOD);
        }

        private void buildTree(int i, int l, int r) {
            if (l > r) return;
            if (l == r) {
                segmentMax[i] = array[l];
                segmentMin[i] = array[l];
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
            segmentMax[i] = MaxMin.Max(segmentMax[i * 2], segmentMax[i * 2 + 1]);
            segmentMin[i] = MaxMin.Min(segmentMin[i * 2], segmentMin[i * 2 + 1]);
        }

        private void buildTree(int i, int l, int r, long MOD) {
            if (l > r) return;
            if (l == r) {
                segmentMax[i] = array[l] % MOD;
                segmentMin[i] = array[l] % MOD;
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m, MOD);
            buildTree(i * 2 + 1, m + 1, r, MOD);
            segmentMax[i] = MaxMin.Max(segmentMax[i * 2], segmentMax[i * 2 + 1]);
            segmentMin[i] = MaxMin.Min(segmentMin[i * 2], segmentMin[i * 2 + 1]);
        }

        private void trueVal(int i, int l, int r) {
            segmentMax[i] += lazyMax[i];
            if (l != r) {
                lazyMax[i * 2] += lazyMax[i];
                lazyMax[i * 2 + 1] += lazyMax[i];
            }
            lazyMax[i] = 0;
            segmentMin[i] += lazyMin[i];
            if (l != r) {
                lazyMin[i * 2] += lazyMin[i];
                lazyMin[i * 2 + 1] += lazyMin[i];
            }
            lazyMin[i] = 0;
        }

        public void update(int l, int r, long val) {
            update(1, 1, N, l, r, val);
        }

        private void update(int i, int l, int r, int L, int R, long val) {
            trueVal(i, l, r);
            if (l > R || L > r || l > r) return;
            if (L <= l && r <= R) {
                segmentMin[i] += val;
                segmentMax[i] += val;
                if (l != r) {
                    lazyMax[i * 2] += val;
                    lazyMax[i * 2 + 1] += val;
                    lazyMin[i * 2] += val;
                    lazyMin[i * 2 + 1] += val;
                }
                return;
            }
            int m = (l + r) >> 1;
            update(i * 2, l, m, L, R, val);
            update(i * 2 + 1, m + 1, r, L, R, val);
            segmentMin[i] = MaxMin.Min(segmentMin[i * 2], segmentMin[i * 2 + 1]);
            segmentMax[i] = MaxMin.Max(segmentMax[i * 2], segmentMax[i * 2 + 1]);
        }

        public long getMin(int l, int r) {
            return getMin(1, 1, N, l, r);
        }

        private long getMin(int i, int l, int r, int L, int R) {
            trueVal(i, l, r);
            if (l > R || L > r || l > r) return INF;
            if (L <= l && r <= R) return segmentMin[i];
            int m = (l + r) >> 1;
            return MaxMin.Min(getMin(i * 2, l, m, L, R), getMin(i * 2 + 1, m + 1, r, L, R));
        }

    }
}