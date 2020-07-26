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
        ATimofeyAndATree solver = new ATimofeyAndATree();
        solver.solve(1, in, out);
        out.close();
    }

    static class ATimofeyAndATree {
        private InputReader in;
        private PrintWriter out;
        private ArrayList<Integer>[] tree;
        private int[] a;
        private int[] cnt;
        private int pos1 = -1;
        private int pos2 = -1;
        private boolean check = true;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            tree = in.nextTree(n);
            a = in.nextIntArray(n, 1);
            cnt = new int[n + 1];
            find(1, 1);
//        out.println(pos1 + " " + pos2);
            if (pos1 == -1) {
                out.println("YES");
                out.println(1);
                return;
            }
            check = true;
            for (int i : tree[pos1]) dfs(i, pos1);
            if (check) {
                out.println("YES");
                out.println(pos1);
                return;
            }
            check = true;
            for (int i : tree[pos2]) dfs(i, pos2);
            if (check) {
                out.println("YES");
                out.println(pos2);
                return;
            }
            out.println("NO");
        }

        private void find(int u, int l) {
            for (int v : tree[u])
                if (v != l) {
                    if (a[u] != a[v]) {
                        pos1 = u;
                        pos2 = v;
                    }
                    find(v, u);
                }
        }

        private void dfs(int u, int l) {
            for (int v : tree[u])
                if (v != l) {
                    if (a[u] != a[v]) check = false;
                    dfs(v, u);
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