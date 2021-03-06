import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        CRestoreGraph solver = new CRestoreGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class CRestoreGraph {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int k = in.nextInt();
            int[] cap = new int[n + 1];
            Arrays.fill(cap, k);
            PairII[] a = new PairII[n + 1];
            ArrayList<PairII> ans = new ArrayList<>();
            ArrayList<Integer>[] adj = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++)
                adj[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++)
                a[i] = new PairII(in.nextInt(), i);

            Arrays.sort(a, 1, n + 1);
            if (a[1].first != 0) {
                out.println(-1);
                return;
            }
            adj[0].add(a[1].second);
            for (int i = 2; i <= n; i++) {

                if (a[i].first == 0 || adj[a[i].first - 1].size() == 0) {
                    out.println(-1);
                    return;
                }
                int tmp = adj[a[i].first - 1].get(adj[a[i].first - 1].size() - 1);
                cap[tmp]--;
                cap[a[i].second]--;
                if (cap[tmp] == 0) adj[a[i].first - 1].remove(adj[a[i].first - 1].size() - 1);
                if (cap[a[i].second] != 0)
                    adj[a[i].first].add(a[i].second);

                ans.add(new PairII(tmp, a[i].second));
            }
            out.println(ans.size());
            for (PairII p : ans) {
                out.println(p.first + " " + p.second);
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
}