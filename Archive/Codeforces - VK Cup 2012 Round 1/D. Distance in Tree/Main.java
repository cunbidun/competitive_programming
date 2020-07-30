import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        DDistanceInTree solver = new DDistanceInTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDistanceInTree {
        private InputReader in;
        private PrintWriter out;
        private int[][] dis;
        private int n;
        private int k;
        private ArrayList<Integer>[] tree;
        private long ans = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            k = in.nextInt();
            dis = new int[n + 1][k + 1];
            tree = in.nextTree(n);
            cal(1, 1);
            out.println(ans);

//        int cnt = 0;
//        LCA lca = new LCA(tree, n, 1);
//        for (int i = 1; i <= n; i++) {
//            for (int j = i + 1; j <= n; j++) {
//                if (lca.numEdgeBetween(i, j) == k) {
//                    System.out.println(i + " " + j);
//                    cnt++;
//                }
//            }
//        }
        }

        private void cal(int u, int l) {
            dis[u][0] = 1;
            for (int v : tree[u]) {
                if (v != l) {
                    cal(v, u);
                    for (int i = 0; i <= k - 1; i++) {
                        ans += (long) dis[u][i] * dis[v][k - i - 1];
                    }
                    for (int i = 1; i <= k; i++) {
                        dis[u][i] += dis[v][i - 1];
                    }
                }
            }
//        if (u == 5) System.out.println(ans);
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
}