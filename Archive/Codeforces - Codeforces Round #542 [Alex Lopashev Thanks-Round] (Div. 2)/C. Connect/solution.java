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
        CConnect solver = new CConnect();
        solver.solve(1, in, out);
        out.close();
    }

    static class CConnect {
        private static final int INF = (int) 2e9 + 7;
        private int n;
        private int x1;
        private int x2;
        private int y1;
        private int y2;
        private ArrayList<PairII> l1 = new ArrayList<>();
        private ArrayList<PairII> l2 = new ArrayList<>();
        private char[][] a = new char[100][100];
        private int[] dx = {0, 0, -1, 1};
        private int[] dy = {-1, 1, 0, 0};
        private boolean[][] visited = new boolean[100][100];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            x1 = in.nextInt();
            y1 = in.nextInt();
            x2 = in.nextInt();
            y2 = in.nextInt();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    a[i][j] = in.nextCharacter();
                }
            }
            dfs1(x1, y1);
            if (visited[x2][y2]) {
                out.println(0);
                return;
            }
            dfs2(x2, y2);
            int ans = INF;
            for (PairII p1 : l1) {
                for (PairII p2 : l2) {
                    ans = MaxMin.Min(ans, (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
                }
            }
            out.println(ans);
        }

        private void dfs1(int x, int y) {
            if (!inside(x, y)) return;
            visited[x][y] = true;
            l1.add(new PairII(x, y));
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (!visited[xx][yy]) {
                    dfs1(xx, yy);
                }
            }
        }

        private void dfs2(int x, int y) {
            if (!inside(x, y)) return;
            visited[x][y] = true;
            l2.add(new PairII(x, y));
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (!visited[xx][yy]) {
                    dfs2(xx, yy);
                }
            }
        }

        private boolean inside(int x, int y) {
            return x >= 1 && y >= 1 && x <= n && y <= n && a[x][y] == '0';
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}