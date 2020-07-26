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
        DR2D2AndDroidArmy solver = new DR2D2AndDroidArmy();
        solver.solve(1, in, out);
        out.close();
    }

    static class DR2D2AndDroidArmy {
        private InputReader in;
        private PrintWriter out;
        private STPointAddMax[] st;
        private int n;
        private int m;
        private int k;
        private int start = 0;
        private int end = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            st = new STPointAddMax[m + 1];
            for (int i = 1; i <= m; i++) {
                st[i] = new STPointAddMax(n);
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    st[j].update(i, in.nextInt());
                }
            }
            int l = 0, r = n;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(r)) l = r;
                    break;
                }
                int mid = (l + r) >> 1;
                if (ch(mid)) l = mid;
                else r = mid - 1;
            }
            if (l == 0) {
                for (int i = 1; i <= m; i++) {
                    out.print(0 + " ");
                }
                return;
            }
//        out.println(l);
            ch(l);
//        out.println(start + " " + end);
            for (int i = 1; i <= m; i++) {
                out.print(st[i].getMax(start, end) + " ");
            }
            out.println();
        }

        private boolean ch(int mid) {
            for (int i = 1; i <= n - mid + 1; i++) {
                int tmp = 0;
                for (int j = 1; j <= m; j++) {
                    tmp += st[j].getMax(i, i + mid - 1);
                }
                if (tmp <= k) {
                    start = i;
                    end = i + mid - 1;
                    return true;
                }
            }
            return false;
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class STPointAddMax {
        private int[] segmentMax;
        private int[] array;
        private int N;
        private int INF = (int) 1e9 + 7;

        public STPointAddMax(int n) {
            segmentMax = new int[4 * n];
            N = n;
        }

        public STPointAddMax(int n, int[] inputArray) {
            segmentMax = new int[4 * n];
            this.array = inputArray;
            N = n;
            buildTree(1, 1, N);
        }

        private void buildTree(int i, int l, int r) {
            if (l > r) return;
            if (l == r) {
                segmentMax[i] = array[l];
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
            segmentMax[i] = MaxMin.Max(segmentMax[i * 2], segmentMax[i * 2 + 1]);
        }

        public void update(int p, int val) {
            update(1, 1, N, p, val);
        }

        private void update(int i, int l, int r, int p, int val) {
            if (l > p || p > r) return;
            if (l == r) {
                segmentMax[i] += val;
                return;
            }
            int m = (l + r) >> 1;
            update(i * 2, l, m, p, val);
            update(i * 2 + 1, m + 1, r, p, val);
            segmentMax[i] = MaxMin.Max(segmentMax[i * 2], segmentMax[i * 2 + 1]);
        }

        public int getMax(int l, int r) {
            return getMax(1, 1, N, l, r);
        }

        private int getMax(int i, int l, int r, int L, int R) {
            if (l > R || L > r || l > r) return -INF;
            if (L <= l && r <= R) return segmentMax[i];
            int m = (l + r) >> 1;
            return MaxMin.Max(getMax(i * 2, l, m, L, R), getMax(i * 2 + 1, m + 1, r, L, R));
        }

    }
}