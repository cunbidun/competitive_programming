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
        F1TreeCuttingEasyVersion solver = new F1TreeCuttingEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class F1TreeCuttingEasyVersion {
        private static final int MAXA = (int) 3e5 + 10;
        private int cntR = 0;
        private int cntB = 0;
        ArrayList<Integer>[] adj = new ArrayList[MAXA];
        int[] a;
        int[] r = new int[MAXA];
        int[] b = new int[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            a = in.nextIntArray(n, 1);
            for (int i = 1; i <= n; i++) {
                adj[i] = new ArrayList<>();
                if (a[i] == 1) cntR++;
                if (a[i] == 2) cntB++;
            }
            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            dfs(1, 1);
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                //  out.println(r[i] +  " " + b[i]);
                if (r[i] >= 1 && b[i] >= 1) continue;
                if ((cntB - b[i]) >= 1 && (cntR - r[i]) >= 1) continue;
                ans++;
            }
            out.println(ans);
        }

        void dfs(int u, int l) {
            for (int v : adj[u]) {
                if (v != l) {
                    dfs(v, u);
                    r[u] += r[v];
                    b[u] += b[v];
                }
            }
            if (a[u] == 1) r[u]++;
            if (a[u] == 2) b[u]++;

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
            int[] arr = new int[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}