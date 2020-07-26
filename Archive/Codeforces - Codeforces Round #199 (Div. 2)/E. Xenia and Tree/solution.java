import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        PrintWriter out = new PrintWriter(outputStream);
        EXeniaAndTree solver = new EXeniaAndTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class EXeniaAndTree {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private ArrayList<Integer>[] centroidTree;
        private ArrayList<Integer>[] tree;
        private LCA lca;
        private int root;
        private int[] dis;
        private int[] par;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            dis = new int[n + 1];
            par = new int[n + 1];
            Arrays.fill(dis, INF);
            tree = in.nextTree(n);
            CentroidDecomposition cd = new CentroidDecomposition(tree, n);
            centroidTree = cd.buildCentroid();
            root = cd.getRoot();
            lca = new LCA(tree, n, root);
            par[root] = 0;
            dfs(root, root);


            update(1);
            while (m-- > 0) {
                int cmd = in.nextInt();
                if (cmd == 1) update(in.nextInt());
                else {
                    out.println(get(in.nextInt()));
                }
            }
//        out.println(root);
//        for (int i = 1; i <= n; i++) {
//            for (int j : centroidTree[i]) {
//                out.println(i + " " + j);
//
//            }
//        }
        }

        private void dfs(int u, int l) {
            for (int v : centroidTree[u])
                if (v != l) {
                    par[v] = u;
                    dfs(v, u);
                }
        }

        private int get(int u) {
            int tmp = u;
            int cur = INF;
            while (u != 0) {
                cur = MaxMin.Min(cur, lca.numEdgeBetween(u, tmp) + dis[u]);
                u = par[u];
            }
            return cur;
        }

        private void update(int u) {
            int tmp = u;
            while (u != 0) {
                dis[u] = MaxMin.Min(dis[u], lca.numEdgeBetween(u, tmp));
                u = par[u];
            }
        }

    }

    static class CentroidDecomposition {
        private boolean[] isCentroid;
        private int[] numChild;
        private ArrayList<Integer>[] originalTree;
        private ArrayList<Integer>[] centroidTree;
        private int root;

        public CentroidDecomposition(ArrayList<Integer>[] tree, int n) {
            isCentroid = new boolean[n + 1];
            numChild = new int[n + 1];
            originalTree = tree;
            centroidTree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) centroidTree[i] = new ArrayList<>();
        }

        private int getSub(int u, int l) {
            numChild[u] = 1;
            for (int v : originalTree[u])
                if (v != l && !isCentroid[v]) numChild[u] += getSub(v, u);
            return numChild[u];
        }

        private int findCentroid(int u, int l, int numNode) {
            for (int v : originalTree[u])
                if (v != l && numChild[v] * 2 > numNode && !isCentroid[v]) return findCentroid(v, u, numNode);
            isCentroid[u] = true;
            return u;
        }

        private int buildCentroid(int u, int l) {
            getSub(u, l);
            int numNode = numChild[u];
            int curr = findCentroid(u, l, numNode);
            if (l == -1) root = curr;
            for (int v : originalTree[curr]) {
                if (!isCentroid[v]) {
                    int next = buildCentroid(v, curr);
                    centroidTree[curr].add(next);
                    centroidTree[next].add(curr);
                }
            }
            return curr;
        }

        public ArrayList<Integer>[] buildCentroid() {
            buildCentroid(1, -1);
            return centroidTree;
        }

        public int getRoot() {
            return root;
        }

    }

    static class LCA {
        private ArrayList<Integer>[] adjList;
        private int[] level;
        private int[][] SpTLCA;

        public LCA(ArrayList<Integer>[] adjList, int numNode, int root) {
            level = new int[numNode + 1];
            SpTLCA = new int[numNode + 1][21];
            this.adjList = adjList;
            level[root] = 1;
            SpTLCA[root][0] = 0;
            dfs(root, root);
            for (int j = 1; j <= 20; j++)
                for (int i = 1; i <= numNode; i++) SpTLCA[i][j] = SpTLCA[SpTLCA[i][j - 1]][j - 1];
        }

        private void dfs(int u, int p) {
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u].get(i);
                if (v != p) {
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

        public int numEdgeBetween(int u, int v) {
            int w = lca(u, v);
            return level[u] + level[v] - 2 * level[w];
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
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}