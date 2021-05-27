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
        OutputWriter out = new OutputWriter(outputStream);
        Task1287D solver = new Task1287D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1287D {
        private InputReader in;
        private OutputWriter out;
        int N = (int) 2e3 + 1;
        ArrayList<Integer>[] tree = new ArrayList[N];
        int[] c = new int[N];
        int[] ans = new int[N];
        int[] size = new int[N];
        boolean[] used = new boolean[N];
        boolean done;
        int n;

        void dfs(int u) {
            int cnt = 0;
            int val = 0;
            size[u] = 1;
            while (cnt <= c[u]) {
                val++;
                if (val > n)
                    done = true;
                if (!used[val])
                    cnt++;
            }
            ans[u] = val;
            used[val] = true;
            for (int v : tree[u]) {
                dfs(v);
                size[u] += size[v];
            }
            if (c[u] >= size[u])
                done = true;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();
            int root = -1;
            for (int i = 1; i <= n; i++) {
                int p = in.nextInt();
                c[i] = in.nextInt();
                if (p == 0) root = i;
                else
                    tree[p].add(i);
            }
            dfs(root);
            if (!done) {
                out.println("YES");
                out.println(ans, 1, n);
            } else out.println("NO");
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

        public void println(String i) {
            out.println(i);
        }

        public void print(int[] a, int start, int end) {
            for (int i = start; i <= end; i++) {
                out.print(a[i] + " ");
            }
        }

        public void println(int[] a, int start, int end) {
            print(a, start, end);
            out.println();
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}