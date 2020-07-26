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
        F1SpanningTreeWithMaximumDegree solver = new F1SpanningTreeWithMaximumDegree();
        solver.solve(1, in, out);
        out.close();
    }

    static class F1SpanningTreeWithMaximumDegree {
        private static final int MAXA = (int) 2e5 + 10;
        ArrayList<Integer>[] g = new ArrayList[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            for (int i = 1; i <= n; i++) {
                g[i] = new ArrayList<>();
            }
            int max = 0;
            int pos = 0;
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                g[u].add(v);
                g[v].add(u);
                if (g[u].size() > max) {
                    pos = u;
                    max = g[u].size();
                }
                if (g[v].size() > max) {
                    pos = v;
                    max = g[v].size();
                }
            }
            UnionFind dsu = new UnionFind(n);
            for (int v : g[pos]) {
                out.println(pos + " " + v);
                dsu.mergeSet(pos, v);
            }
            for (int i = 1; i <= n; i++) {
                for (int j : g[i]) {
                    if (!dsu.isSameSet(i, j)) {
                        out.println(i + " " + j);
                        dsu.mergeSet(i, j);
                    }
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class UnionFind {
        private int[] p;
        private int[] rank;

        public UnionFind(int N) {
            p = new int[N + 1];
            rank = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                p[i] = i;
            }
        }

        public int findSet(int x) {
            return (p[x] == x) ? x : (p[x] = findSet(p[x]));
        }

        public boolean isSameSet(int x, int y) {
            return findSet(x) == findSet(y);
        }

        public void mergeSet(int x, int y) {
            if (!isSameSet(x, y)) {
                x = findSet(x);
                y = findSet(y);
//            p[y] = x;
                if (rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }

    }
}