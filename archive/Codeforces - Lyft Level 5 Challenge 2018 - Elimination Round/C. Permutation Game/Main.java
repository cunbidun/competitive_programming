import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.AbstractCollection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.LinkedList;
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
        CPermutationGame solver = new CPermutationGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPermutationGame {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            ArrayList<Integer>[] adjList = new ArrayList[n + 1];
            ArrayList<Integer>[] par = new ArrayList[n + 1];

            for (int i = 1; i <= n; i++) {
                adjList[i] = new ArrayList<>();
                par[i] = new ArrayList<>();
            }
            for (int i = 1; i <= n; i++) {
                int cur = a[i];
                while (true) {
                    if (i + cur > n && i - cur < 1) break;
                    if (i + cur <= n && a[i + cur] > a[i]) {
                        par[a[i + cur]].add(a[i]);
                        adjList[a[i]].add(a[i + cur]);
                    }
                    if (i - cur >= 1 && a[i - cur] > a[i]) {
                        par[a[i - cur]].add(a[i]);
                        adjList[a[i]].add(a[i - cur]);
                    }
                    cur += a[i];
                }
            }
            int[] ans = new int[n + 1];
            Arrays.fill(ans, -1);
            LinkedList<Integer> q = new LinkedList<>();

            for (int i = 1; i <= n; i++) {
                if (adjList[a[i]].size() == 0) {
                    q.add(a[i]);
                    ans[a[i]] = 0;
                }
            }
            while (!q.isEmpty()) {
                int u = q.pop();
                if (ans[u] == 0) {
                    for (int v : par[u]) {
                        if (ans[v] == -1) {
                            ans[v] = 1;
                            q.add(v);
                        }
                    }
                } else {
                    for (int v : par[u])
                        if (ans[v] == -1) {
                            boolean f = false;
                            for (int x : adjList[v])
                                if (ans[x] != 1) {
                                    f = true;
                                    break;
                                }
                            if (!f) {
                                ans[v] = 0;
                                q.add(v);
                            }

                        }
                }
            }
            for (int i = 1; i <= n; i++) {
                if (ans[a[i]] == 0) out.print("B");
                else out.print("A");
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