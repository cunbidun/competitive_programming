import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
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
        CQueen solver = new CQueen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CQueen {
        private int[] val;
        private ArrayList<Integer>[] tree;
        private int root = 0;
        private int[] cnt;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            tree = new ArrayList[n + 1];
            val = new int[n + 1];
            cnt = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 1; i <= n; i++) {
                int p = in.nextInt();
                int c = in.nextInt();
                if (c == 1) {
                    cnt[p]++;
                }
                val[i] = c;
                if (p == -1) {
                    root = i;
                    continue;
                }
                tree[p].add(i);
            }
            ArrayList<Integer> ans = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == tree[i].size() && val[i] == 1) {
                    ans.add(i);
                }
            }
            if (ans.size() == 0) {
                out.println(-1);
                return;
            }
            Collections.sort(ans);
            for (int i : ans) out.print(i + " ");
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