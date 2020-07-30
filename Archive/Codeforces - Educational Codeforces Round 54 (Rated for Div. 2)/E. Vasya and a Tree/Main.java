import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        Task1076E solver = new Task1076E();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1076E {
        private InputReader in;
        private OutputWriter out;
        private STRangeAddSumLong tree;
        private ArrayList<Integer>[] a;
        private ArrayList<PairII>[] q;
        private long[] ans;
        private int[] lvl;
        private int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            a = in.nextTree(n);
            q = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                q[i] = new ArrayList<>();
            }
            int t = in.nextInt();
            while (t-- > 0) q[in.nextInt()].add(new PairII(in.nextInt(), in.nextInt()));
            tree = new STRangeAddSumLong(n);
            ans = new long[n + 1];
            lvl = new int[n + 1];
            lvl[1] = 1;
            dfs(1, 1);
            out.println(ans, 1, n);
        }

        private void dfs(int u, int l) {
            for (PairII p : q[u])
                tree.update(lvl[u], MaxMin.Min(lvl[u] + p.first, n), p.second);
            for (int v : a[u]) {
                if (v != l) {
                    lvl[v] = lvl[u] + 1;
                    dfs(v, u);
                }
            }
            ans[u] = tree.getSum(lvl[u], lvl[u]);
            for (PairII p : q[u]) tree.update(lvl[u], MaxMin.Min(lvl[u] + p.first, n), -p.second);
        }

    }

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
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

        public ArrayList<Integer>[] nextTree(int n) {
            ArrayList<Integer>[] tree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                int u = nextInt();
                int v = nextInt();
                tree[u].add(v);
                tree[v].add(u);
            }
            return tree;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public void print(long[] a, int start, int end) {
            for (int i = start; i <= end; i++) {
                out.print(a[i] + " ");
            }
        }

        public void println(long[] a, int start, int end) {
            print(a, start, end);
            out.println();
        }

    }
}