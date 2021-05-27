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
        FMSTUnification solver = new FMSTUnification();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMSTUnification {
        static final int MAXA = (int) 2e5 + 10;
        ArrayList<PairIntInt>[] adj = new ArrayList[MAXA];
        ArrayList<PairIntInt>[] tree = new ArrayList[MAXA];
        ArrayList<QuartetIntIntIntInt> edgeList = new ArrayList<>();
        boolean[] ch = new boolean[MAXA];
        int[][] LCA = new int[MAXA][22];
        int[][] LCAMax = new int[MAXA][22];
        int[] lvl = new int[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            for (int i = 0; i <= n; i++) {
                ch[i] = false;
                adj[i] = new ArrayList<>();
                tree[i] = new ArrayList<>();
            }
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                adj[u].add(new PairIntInt(v, w));
                adj[v].add(new PairIntInt(u, w));
                edgeList.add(new QuartetIntIntIntInt(w, u, v, i));
            }

            UnionFind dsu = new UnionFind(n);
            Collections.sort(edgeList);

            for (int i = 0; i < edgeList.size(); i++) {
                int w = edgeList.get(i).first;
                int u = edgeList.get(i).second;
                int v = edgeList.get(i).third;
                int id = edgeList.get(i).fourth;
                if (!dsu.isSameSet(u, v)) {
                    ch[id] = true;
                    dsu.mergeSet(u, v);
                    //out.println(u + " " + v);
                    tree[u].add(new PairIntInt(v, w));
                    tree[v].add(new PairIntInt(u, w));
                }
            }

            dfs(1, 1);
            for (int j = 1; j <= 20; j++) {
                for (int i = 1; i <= n; i++) {
                    LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
                    LCAMax[i][j] = Math.max(LCAMax[i][j], LCAMax[i][j - 1]);
                    LCAMax[i][j] = Math.max(LCAMax[i][j], LCAMax[LCA[i][j - 1]][j - 1]);
                }
            }
            int ans = 0;
            for (int i = 0; i < edgeList.size(); i++) {
                if (!ch[edgeList.get(i).fourth]) {
                    int w = edgeList.get(i).first;
                    int u = edgeList.get(i).second;
                    int v = edgeList.get(i).third;
                    if (lca(u, v) == w) {
                        ans++;
                    }
                }
            }
            out.println(ans);
        }

        private int lca(int u, int v) {
            int res = 0;
            if (lvl[u] < lvl[v]) {
                int t = u;
                u = v;
                v = t;
            }
            for (int i = 20; i >= 0; i--) {
                if (lvl[LCA[u][i]] >= lvl[v]) {
                    res = Math.max(res, LCAMax[u][i]);
                    u = LCA[u][i];
                }
            }
            if (u == v) {
                return res;
            }
            for (int i = 20; i >= 0; i--) {
                if (LCA[u][i] != LCA[v][i]) {
                    res = Math.max(res, LCAMax[u][i]);
                    res = Math.max(res, LCAMax[v][i]);
                    u = LCA[u][i];
                    v = LCA[v][i];
                }
            }
            res = Math.max(res, LCAMax[u][0]);
            res = Math.max(res, LCAMax[v][0]);
            return res;
        }

        private void dfs(int u, int l) {
            for (PairIntInt cur : tree[u]) {
                int v = cur.first;
                int w = cur.second;
                if (v != l) {
                    lvl[v] = lvl[u] + 1;
                    LCA[v][0] = u;
                    LCAMax[v][0] = w;
                    dfs(v, u);
                }
            }
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
                if (rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }

    }

    static class PairIntInt implements Comparable<PairIntInt> {
        public int first;
        public int second;

        public PairIntInt(int first, int second) {
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

            PairIntInt pair = (PairIntInt) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairIntInt o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class QuartetIntIntIntInt implements Comparable<QuartetIntIntIntInt> {
        public int first;
        public int second;
        public int third;
        public int fourth;

        public QuartetIntIntIntInt(int first, int second, int third, int fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            QuartetIntIntIntInt quar = (QuartetIntIntIntInt) o;

            return first == quar.first && second == quar.second && third == quar.third && fourth == quar.fourth;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + "," + fourth + ")";
        }

        public int compareTo(QuartetIntIntIntInt o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(third, o.third);
            if (value != 0) {
                return value;
            }
            return Integer.compare(fourth, o.fourth);
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

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}