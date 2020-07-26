import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CXorTree solver = new CXorTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class CXorTree {
        private InputReader in;
        private PrintWriter out;
        private int[] times;
        private int[] init;
        private int[] goal;
        private ArrayList<Integer>[] tree;
        private boolean[] vis;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            times = new int[n + 1];
            vis = new boolean[n + 1];
            tree = in.nextTree(n);
            init = in.nextIntArray(n, 1);
            goal = in.nextIntArray(n, 1);
            LinkedList<Integer> q = new LinkedList<>();
            q.add(1);
            ArrayList<Integer> ans = new ArrayList<>();
            while (!q.isEmpty()) {
                int u = q.poll();
                vis[u] = true;
                for (int v : tree[u])
                    if (!vis[v]) {
                        q.add(v);
                    }

                if (init[u] == goal[u] && times[u] % 2 == 1) {
                    ans.add(u);
                    times[u]++;
                }
                if (init[u] != goal[u] && times[u] % 2 == 0) {
                    ans.add(u);
                    times[u]++;
                }
                for (int v : tree[u])
                    if (!vis[v]) {
                        for (int cv : tree[v])
                            if (!vis[cv]) {
                                times[cv] += times[u];
                            }
                    }
            }
            out.println(ans.size());
            for (int i : ans) out.println(i);
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

        public ArrayList<Integer>[] nextTree(int n) {
            ArrayList<Integer>[] tree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                int u = nextInt();
                int v = nextInt();
                tree[u].add(v);
                tree[v].add(u);
            }
            return tree;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}