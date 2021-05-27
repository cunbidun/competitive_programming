import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        DDimaAndBacteria solver = new DDimaAndBacteria();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDimaAndBacteria {
        private static final int INF = (int) 1e9 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int[] a = in.nextIntArray(k, 1);
            int[] type = new int[n + 1];
            UnionFind dsu = new UnionFind(n);
            int cur = 0;
            int sum = 0;
            int index = 1;
            while (cur <= k) {
                if (index != sum + 1) {
                    type[index] = cur;
                    index++;
                    if (index > n) break;
                } else {
                    cur++;
                    type[index] = cur;
                    index++;
                    if (index > n) break;
                    sum += a[cur];
                }
            }
            int[][] matrix = new int[k + 1][k + 1];
            for (int i = 1; i <= k; i++) {
                Arrays.fill(matrix[i], INF);
            }
            for (int i = 1; i <= k; i++) matrix[i][i] = 0;
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                if (w == 0) dsu.mergeSet(u, v);
                matrix[type[u]][type[v]] = MaxMin.Min(matrix[type[v]][type[u]], w);
                matrix[type[v]][type[u]] = MaxMin.Min(matrix[type[v]][type[u]], w);
            }
            for (int i = 1; i <= n; i++) {
                if (type[i] == type[i - 1] && dsu.findSet(i) != dsu.findSet(i - 1)) {
                    out.println("No");
                    return;
                }
            }
            out.println("Yes");
            for (int l = 1; l <= k; l++)
                for (int i = 1; i <= k; i++)
                    for (int j = 1; j <= k; j++)
                        if (matrix[i][l] != INF && matrix[l][j] != INF) {
                            matrix[i][j] = MaxMin.Min(matrix[i][j], matrix[i][l] + matrix[l][j]);
                        }

            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= k; j++) {
                    if (matrix[i][j] == INF) matrix[i][j] = -1;
                    out.print(matrix[i][j] + " ");
                }
                out.println();
            }
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}