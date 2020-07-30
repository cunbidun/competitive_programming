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
        FGraphWithoutLongDirectedPaths solver = new FGraphWithoutLongDirectedPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class FGraphWithoutLongDirectedPaths {
        private int[] color;
        private boolean[] vis;
        private boolean[] ans;
        private boolean f = true;
        private ArrayList<TripIII>[] adj;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            color = new int[n + 1];
            ans = new boolean[m + 1];
            vis = new boolean[n + 1];
            adj = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adj[u].add(new TripIII(v, 0, i));
                adj[v].add(new TripIII(u, 1, i));
            }
            color[1] = 1;
            dfs(1);
            if (!f) {
                out.println("NO");
                return;
            }
            for (int i = 1; i <= n; i++) {
                for (TripIII p : adj[i]) {
                    if (color[i] == color[p.first]) {
                        out.println("NO");
                        return;
                    } else {
                        if (color[i] == 2 && p.second == 1) ans[p.third] = true;
                        if (color[i] == 1 && p.second == 0) ans[p.third] = true;
                    }
                }
            }
            out.println("YES");
            for (int i = 1; i <= m; i++) {
                if (ans[i]) out.print(1);
                else out.print(0);
            }
        }

        private void dfs(int u) {
            vis[u] = true;
            for (TripIII p : adj[u]) {
                int v = p.first;
                if (!vis[v]) {
                    if (color[v] == 0) {
                        color[v] = 3 - color[u];
                    } else {
                        if (color[v] != 3 - color[u]) {
                            f = false;
                            return;
                        }
                    }
                    dfs(v);
                }
            }
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