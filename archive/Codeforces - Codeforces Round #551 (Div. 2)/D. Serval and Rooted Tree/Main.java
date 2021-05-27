import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        DServalAndRootedTree solver = new DServalAndRootedTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class DServalAndRootedTree {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private ArrayList<Integer>[] tree;
        private int[] a;
        private int[] f;
        int cntLeave = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            a = in.nextIntArray(n, 1);
            tree = new ArrayList[n + 1];
            f = new int[n + 1];
            for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();
            for (int i = 2; i <= n; i++) {
                int x = in.nextInt();
                tree[x].add(i);
            }
            dfs(1);
//        for (int i = 1; i <= n; i++) {
//            out.print(f[i] + " ");
//        }
//        out.println();
            out.println(cntLeave - f[1] + 1);
        }

        private int dfs(int u) {
            if (tree[u].size() == 0) {
                cntLeave++;
                return f[u] = 1;
            }
            if (a[u] == 1) {
                f[u] = INF;
                for (int v : tree[u]) {
                    f[u] = MaxMin.Min(f[u], f[v] = dfs(v));
                }
            } else {
                for (int v : tree[u]) {
                    f[u] += f[v] = dfs(v);
                }
            }
            return f[u];
        }

    }

    static class MaxMin {
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
}