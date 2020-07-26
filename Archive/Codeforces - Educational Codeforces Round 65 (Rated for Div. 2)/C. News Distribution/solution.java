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
        CNewsDistribution solver = new CNewsDistribution();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNewsDistribution {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            UnionFind dsu = new UnionFind(n);
            for (int i = 1; i <= m; i++) {
                int k = in.nextInt();
                if (k != 0) {
                    int first = in.nextInt();
                    for (int j = 2; j <= k; j++) {
                        dsu.mergeSet(first, in.nextInt());
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                out.print(dsu.getSize(dsu.findSet(i)) + " ");
            }
        }

    }

    static class UnionFind {
        private int[] p;
        private int[] rank;
        private int[] size;

        public UnionFind(int N) {
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

        public int getSize(int i) {
            return size[i];
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