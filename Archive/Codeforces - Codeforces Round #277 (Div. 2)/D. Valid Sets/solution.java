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
        Task486D solver = new Task486D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task486D {
        private static final int MOD = (int) 1e9 + 7;
        private InputReader in;
        private OutputWriter out;
        private ArrayList<Integer>[] tree;
        private int d;
        private int[] a;
        private int[] res;
        private boolean[] check;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            d = in.nextInt();
            int n = in.nextInt();
            a = in.nextIntArray(n, 1);
            tree = in.nextTree(n);

            check = new boolean[n + 1];
            res = new int[n + 1];

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                check[i] = true;
                dfs(i, i, a[i]);
                ans = Op.addMod(ans, res[i], MOD);
            }
            out.println(ans);
        }

        private void dfs(int u, int l, int val) {
            res[u] = 1;
            for (int v : tree[u])
                if (v != l && val <= a[v] && a[v] <= val + d) {
                    if (a[v] == val && check[v]) continue;
                    dfs(v, u, val);
                    res[u] = Op.mulMod(res[u], res[v] + 1, MOD);
                }
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

        public void println(int i) {
            out.println(i);
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
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
}