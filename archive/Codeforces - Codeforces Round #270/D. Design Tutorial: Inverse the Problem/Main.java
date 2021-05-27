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
import java.util.Collections;
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
        Task472D solver = new Task472D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task472D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[][] d = in.nextIntTable(n, n, 1, 1);
            ArrayList<PairII>[] tree = new ArrayList[n + 1];
            ArrayList<TripIII> list = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
                if (d[i][i] != 0) {
                    out.print("NO");
                    return;
                }
                for (int j = i + 1; j <= n; j++) {
                    if (d[i][j] != d[j][i]) {
                        out.print("NO");
                        return;
                    }
                    list.add(new TripIII(d[i][j], i, j));
                }
            }
            Collections.sort(list);
            UnionFind dsu = new UnionFind(n);
            int edge = 0;
            for (TripIII t : list) {
                if (t.first == 0 || dsu.isSameSet(t.second, t.third)) continue;
                tree[t.second].add(new PairII(t.third, t.first));
                tree[t.third].add(new PairII(t.second, t.first));
                dsu.mergeSet(t.second, t.third);
//            out.println(t.second + " " + t.third + " " + t.first);
                edge++;
                if (edge == n - 1) break;
            }
            if (edge != n - 1) {
                out.print("NO");
                return;
            }
            LCAWeighted lca = new LCAWeighted(tree, n, 1);
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (lca.distance(i, j) != d[i][j]) {
//                    out.println(i + " " + j);
                        out.print("NO");
                        return;
                    }
                }
            }
            out.print("YES");
        }

    }

    static class TripIII implements Comparable<TripIII> {
        public int first;
        public int second;
        public int third;

        public TripIII(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            TripIII trip = (TripIII) o;

            return first == trip.first && second == trip.second && third == trip.third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(TripIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            return Integer.compare(third, o.third);
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

        public int[][] nextIntTable(int row, int col, int rowSt, int colSt) {
            int[][] arr = new int[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextInt();
                }
            }
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class LCAWeighted {
        protected ArrayList<PairII>[] adjList;
        protected int[] level;
        protected int[][] SpTLCA;
        private int[] dis;

        public LCAWeighted(ArrayList<PairII>[] adjListWeighted, int numNode, int root) {
            level = new int[numNode + 1];
            dis = new int[numNode + 1];
            SpTLCA = new int[numNode + 1][21];
            this.adjList = adjListWeighted;
            level[root] = 1;
            SpTLCA[root][0] = 0;
            dis[root] = 0;
            dfs(root, root);
            for (int j = 1; j <= 20; j++)
                for (int i = 1; i <= numNode; i++) SpTLCA[i][j] = SpTLCA[SpTLCA[i][j - 1]][j - 1];
        }

        private void dfs(int u, int p) {
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u].get(i).first;
                int w = adjList[u].get(i).second;
                if (v != p) {
                    dis[v] = dis[u] + w;
                    level[v] = level[u] + 1;
                    SpTLCA[v][0] = u;
                    dfs(v, u);
                }
            }
        }

        public int lca(int u, int v) {
            if (level[u] > level[v]) {
                int t = u;
                u = v;
                v = t;
            }
            for (int i = 20; i >= 0; i--) {
                if (level[SpTLCA[v][i]] >= level[u]) v = SpTLCA[v][i];
            }
            if (u == v) return v;
            for (int i = 20; i >= 0; i--) {
                if (SpTLCA[v][i] != SpTLCA[u][i]) {
                    v = SpTLCA[v][i];
                    u = SpTLCA[u][i];
                }
            }
            return SpTLCA[u][0];
        }

        public int distance(int u, int v) {
            return dis[u] + dis[v] - 2 * dis[lca(u, v)];
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

    static class UnionFind {
        private int[] p;
        private int[] rank;
        private int[] size;
        private int dsuSize;

        public UnionFind(int N) {
            dsuSize = N;
            p = new int[N + 1];
            rank = new int[N + 1];
            size = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                p[i] = i;
                size[i] = 1;
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
                dsuSize--;
                x = findSet(x);
                y = findSet(y);
                if (rank[x] > rank[y]) {
                    size[x] += size[y];
                    p[y] = x;
                } else {
                    p[x] = y;
                    size[y] += size[x];
                    if (rank[x] == rank[y]) rank[y]++;
                }
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

        public void print(String i) {
            out.print(i);
        }

    }
}