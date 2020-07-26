import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

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
        ETreePainting solver = new ETreePainting();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETreePainting {
        private InputReader in;
        private OutputWriter out;
        private ArrayList<Integer>[] tree;
        private long[] ans;
        private long[] preCal;
        private long[] size;
        private int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            tree = in.nextTree(n);
            ans = new long[n + 1];
            size = new long[n + 1];
            preCal = new long[n + 1];
            dfs(1, 1);
            cal(1, 1);
            ans[1] = preCal[1];
            sol(1, 1);
            out.println(ArrayUtils.getMax(ans, 1, n));
        }

        private void sol(int u, int l) {
            for (int v : tree[u]) {
                if (v != l) {
                    ans[v] = ans[u] - 2 * size[v] + n;
                    sol(v, u);
                }
            }
        }

        private void dfs(int u, int l) {
            size[u] = 1;
            for (int v : tree[u]) {
                if (v != l) {
                    dfs(v, u);
                    size[u] += size[v];
                }
            }
        }

        private void cal(int u, int l) {
            preCal[u] = size[u];
            for (int v : tree[u]) {
                if (v != l) {
                    cal(v, u);
                    preCal[u] += preCal[v];
                }
            }
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class ArrayUtils {
        public static long getMax(long[] array, int stIndex, int enIndex) {
            long max = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                max = MaxMin.Max(max, array[i]);
            }
            return max;
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

        public void println(long i) {
            out.println(i);
        }

    }
}