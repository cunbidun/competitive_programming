import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        FAsyaAndKittens solver = new FAsyaAndKittens();
        solver.solve(1, in, out);
        out.close();
    }

    static class FAsyaAndKittens {
        private int[] l;
        private int[] p;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            UnionFind dsu = new UnionFind(n);
            p = new int[n + 1];
            l = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                p[i] = i;
                l[i] = i;
            }
            int pos = 0;
            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();

                if (!dsu.isSameSet(u, v)) {
                    p[dsu.findSet(v)] = l[dsu.findSet(u)];
                    l[dsu.findSet(u)] = l[dsu.findSet(v)];
                    dsu.mergeSet(u, v);
                }
            }
            for (int i = 1; i <= n; i++) {
                if (p[i] == i) pos = i;
            }
            int cur = l[pos];
            while (cur != pos) {
                out.print(cur + " ");
                cur = p[cur];
            }
            out.print(pos);
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
                p[y] = x;
//            if (rank[x] > rank[y])p[y] = x;
//            else {
//                p[x] = y;
//                if (rank[x] == rank[y]) rank[y]++;
//            }
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