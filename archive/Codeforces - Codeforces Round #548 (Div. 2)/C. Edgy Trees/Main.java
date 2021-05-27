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
        CEdgyTrees solver = new CEdgyTrees();
        solver.solve(1, in, out);
        out.close();
    }

    static class CEdgyTrees {
        private static final int MOD = (int) 1e9 + 7;
        private ArrayList<Integer>[] tree;
        private int[] size;
        private boolean[] vis;
        SBTree<PairII> set;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            tree = new ArrayList[n + 1];
            size = new int[n + 1];
            vis = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            ArrayList<PairII> black = new ArrayList<>();
            set = new SBTree<>();
            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int col = in.nextInt();
                if (col == 1) {
                    set.add(new PairII(u, v));
                    set.add(new PairII(v, u));
                }
                tree[u].add(v);
                tree[v].add(u);
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    dfs(i);
                    ans = Op.addMod(ans, Op.powMod(size[i], k, MOD), MOD);
                }
            }
            out.println(Op.subMod(Op.powMod(n, k, MOD), ans, MOD));
        }

        private void dfs(int u) {
            size[u] = 1;
            vis[u] = true;
            for (int v : tree[u]) {
                if (!vis[v] && !set.find(new PairII(u, v))) {
                    dfs(v);
                    size[u] += size[v];
                }
            }
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int subMod(int x, int y, int MOD) {
            return ((x - y) < 0 ? x - y + MOD : x - y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

        public static int powMod(int x, long p, int MOD) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2, MOD);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t, MOD), x, MOD);
            return mulMod(t, t, MOD);
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

    static class SBTree<T extends Comparable<T>> {
        private Node<T> root;

        public SBTree() {
            root = new Node<>();
        }

        private Node<T> rotate(Node<T> a, boolean flag) {
            int d = 0;
            if (flag) d = 1;
            Node<T> b = a.ch[1 - d];
            a.ch[1 - d] = b.ch[d];
            b.ch[d] = a;
            b.size = a.size;
            a.size = a.ch[0].size + a.ch[1].size + 1;
            return b;
        }

        private Node<T> maintain(Node<T> n, boolean flag) {
            if (n.size == 0) return n;
            int d = 0;
            if (flag) d = 1;
            if (n.ch[d].size > 0 && n.ch[d].ch[d].size > n.ch[1 - d].size) {
                n = rotate(n, !flag);
            } else if (n.ch[d].size > 0 && n.ch[d].ch[1 - d].size > n.ch[1 - d].size) {
                n.ch[d] = rotate(n.ch[d], flag);
                n = rotate(n, !flag);
            } else
                return n;
            n.ch[1] = maintain(n.ch[1], true);
            n.ch[0] = maintain(n.ch[0], false);
            n = maintain(n, true);
            n = maintain(n, false);
            return n;
        }

        private Node<T> add(Node<T> n, T key) {
            if (n.size == 0) {
                n = new Node<>(key);
                return n;
            } else {
                ++n.size;
                int flag = n.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                n.ch[d] = add(n.ch[d], key);
                n = maintain(n, flag < 0);
            }
            return n;
        }

        public void add(T key) {
            root = add(root, key);
        }

        public boolean find(T key) {
            Node<T> o = root;
            while (o.size > 0 && !o.key.equals(key)) {
                int flag = o.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                o = o.ch[d];
            }
            return o.size > 0;
        }

        private class Node<T> {
            Node<T>[] ch = new Node[2];
            T key;
            int size;

            Node(T key) {
                this.key = key;
                this.size = 1;
                ch[1] = ch[0] = new Node<>();
            }

            Node() {
                key = null;
                size = 0;
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
}