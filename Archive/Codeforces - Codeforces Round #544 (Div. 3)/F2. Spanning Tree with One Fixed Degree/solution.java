import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
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
        F2SpanningTreeWithOneFixedDegree solver = new F2SpanningTreeWithOneFixedDegree();
        solver.solve(1, in, out);
        out.close();
    }

    static class F2SpanningTreeWithOneFixedDegree {
        ArrayList<Integer>[] g;
        private ArrayList<Integer> nfree = new ArrayList<>();
        private boolean[] visited;
        private boolean[] free;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            visited = new boolean[n + 1];
            free = new boolean[n + 1];
            int m = in.nextInt();
            int d = in.nextInt();
            g = in.nextGraph(n, m);
            if (g[1].size() < d) {
                out.println("NO");
                return;
            }

            for (int i = 1; i <= n; i++) {
                Collections.sort(g[i]);
            }

            UnionFind dsu = new UnionFind(n);
            ArrayList<PairII> ans = new ArrayList<>();
            visited[1] = true;
            for (int i : g[1]) {
                if (!visited[i])
                    dfs(i);
                else free[i] = true;
            }
            for (int i : g[1]) {
                if (!free[i]) nfree.add(i);
            }
            if (nfree.size() > d) {
                out.println("NO");
                return;
            }
            for (int i : nfree) {
                dsu.mergeSet(i, 1);
                ans.add(new PairII(i, 1));
            }
            d -= nfree.size();
            for (int i : g[1]) {
                if (d == 0) break;
                if (free[i]) {
                    dsu.mergeSet(i, 1);
                    ans.add(new PairII(i, 1));
                    d--;
                }
            }
            for (int i = 2; i <= n; i++) {
                for (int j : g[i]) {
                    if (!dsu.isSameSet(i, j) && j != 1) {
                        dsu.mergeSet(i, j);
                        ans.add(new PairII(i, j));
                    }
                }
            }
            if (ans.size() != n - 1) {
                out.println("NO");
                return;
            }
            out.println("YES");
            for (PairII p : ans) {
                out.println(p.first + " " + p.second);
            }
        }

        private void dfs(int u) {
            visited[u] = true;
            for (int v : g[u]) {
                if (!visited[v]) {
                    if (g[v].get(0) == 1) free[v] = true;
                    dfs(v);
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

        public ArrayList<Integer>[] nextGraph(int n, int m) {
            ArrayList<Integer>[] g = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++)
                g[i] = new ArrayList<>();
            for (int i = 1; i <= m; i++) {
                int u = nextInt();
                int v = nextInt();
                g[u].add(v);
                g[v].add(u);
            }
            return g;
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
}