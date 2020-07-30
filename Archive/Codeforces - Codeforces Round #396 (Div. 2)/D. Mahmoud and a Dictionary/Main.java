import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashMap;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task766D solver = new Task766D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task766D {
        private static final int NUM = (int) 1e5;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int q = in.nextInt();
            HashMap<String, Integer> map = new HashMap<>();
            for (int i = 1; i <= n; i++) {
                map.put(in.nextString(), i);
            }
            UnionFind dsu = new UnionFind(n + NUM);
            for (int i = 1; i <= m; i++) {
                int t = in.nextInt();
                int u = map.get(in.nextString());
                int v = map.get(in.nextString());

                if (!dsu.isSameSet(u, v) && !dsu.isSameSet(u + NUM, v)) {
                    out.println("YES");
                    if (t == 1) {
                        dsu.mergeSet(u, v);
                        dsu.mergeSet(u + NUM, v + NUM);
                    } else {
                        dsu.mergeSet(u, v + NUM);
                        dsu.mergeSet(u + NUM, v);
                    }
                } else {
                    if (t == 1 && dsu.isSameSet(u, v)) {
                        out.println("YES");
                    } else if (t == 2 && !dsu.isSameSet(u, v))
                        out.println("YES");
                    else
                        out.println("NO");
                }
            }
            for (int i = 1; i <= q; i++) {
                int u = dsu.findSet(map.get(in.nextString()));
                int v = dsu.findSet(map.get(in.nextString()));
                if (u == v)
                    out.println(1);
                else if (u + NUM == v || v + NUM == u)
                    out.println(2);
                else
                    out.println(3);
            }
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read()))
                ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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
                    if (rank[x] == rank[y])
                        rank[y]++;
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

        public void println(int i) {
            out.println(i);
        }

        public void println(String i) {
            out.println(i);
        }

    }
}