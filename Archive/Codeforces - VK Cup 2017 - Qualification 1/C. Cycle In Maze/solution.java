import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.LinkedList;
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
        CCycleInMaze solver = new CCycleInMaze();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCycleInMaze {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private int n;
        private int m;
        private int k;
        private int[] dx = {1, 0, 0, -1};
        private int[] dy = {0, -1, 1, 0};
        private char[] sym = {'D', 'L', 'R', 'U'};
        private char[][] a;
        private ArrayList<Character> ans = new ArrayList<>();
        ArrayList<PairII>[] adj;
        int[] d;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            adj = new ArrayList[n * m + 1];
            d = new int[n * m + 1];
            if (k % 2 != 0) {
                out.println("IMPOSSIBLE");
                return;
            }
            a = in.nextCharTable(n, m, 1, 1);
            int posI = -1;
            int posJ = -1;

            for (int i = 1; i <= n * m; i++) {
                adj[i] = new ArrayList<>();
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == 'X') {
                        posI = i;
                        posJ = j;
                    }
                    if (outSide(i, j)) continue;
                    if (!outSide(i + 1, j)) {
                        adj[index(i, j)].add(new PairII(1, index(i + 1, j)));
                    }
                    if (!outSide(i - 1, j)) {
                        adj[index(i, j)].add(new PairII(1, index(i - 1, j)));
                    }
                    if (!outSide(i, j + 1)) {
                        adj[index(i, j)].add(new PairII(1, index(i, j + 1)));
                    }
                    if (!outSide(i, j - 1)) {
                        adj[index(i, j)].add(new PairII(1, index(i, j - 1)));
                    }
                }
            }

            dijkstra(index(posI, posJ));
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                out.println(d[index(i, j)]);
//            }
//        }

            LinkedList<PairII> q = new LinkedList<>();
            q.add(new PairII(posI, posJ));
            int remain = k;
            while (!q.isEmpty()) {
                PairII cor = q.pop();
                int i = cor.first;
                int j = cor.second;
                for (int dir = 0; dir < 4; dir++) {
                    if (!outSide(i + dx[dir], j + dy[dir])) {
                        if (d[index(i + dx[dir], j + dy[dir])] <= remain) {
                            ans.add(sym[dir]);
                            remain--;
                            q.add(new PairII(i + dx[dir], j + dy[dir]));
                            break;
                        }
                    }
                }
                if (remain == 0) break;
            }
            if (ans.size() == 0) {
                out.println("IMPOSSIBLE");
                return;
            }
            for (char c : ans) {
                out.print(c);
            }
        }

        private boolean outSide(int i, int j) {
            return i > n || i <= 0 || j > m || j <= 0 || (a[i][j] == '*');
        }

        private int index(int i, int j) {
            return m * (i - 1) + j;
        }

        private void dijkstra(int start) {
            PriorityQueue<PairII> pq = new PriorityQueue<>();
            for (int i = 1; i <= n * m; i++) d[i] = INF;

            d[start] = 0;
            pq.add(new PairII(0, start));
            while (!pq.isEmpty()) {
                int u = pq.peek().second;
                int du = pq.peek().first;
                pq.poll();
                if (du > d[u]) continue;
                for (PairII p : adj[u]) {
                    int v = p.second;
                    int uv = p.first;
                    if (d[v] > du + uv) {
                        d[v] = du + uv;
                        pq.add(new PairII(d[v], v));
                    }
                }
            }
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

        public char[][] nextCharTable(int row, int col, int rowSt, int colSt) {
            char[][] arr = new char[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextCharacter();
                }
            }
            return arr;
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