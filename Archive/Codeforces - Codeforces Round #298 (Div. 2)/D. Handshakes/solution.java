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
        DHandshakes solver = new DHandshakes();
        solver.solve(1, in, out);
        out.close();
    }

    static class DHandshakes {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            ArrayList<Integer>[] index = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++)
                index[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                index[a[i]].add(i);
            }

            ArrayList<Integer> ans = new ArrayList<>();
            boolean d = false;
            int cur = 0;
            while (ans.size() != n) {
                if (index[cur].size() != 0) {
                    ans.add(index[cur].get(index[cur].size() - 1));
                    index[cur].remove(index[cur].size() - 1);
                    cur++;
                } else {
                    while (index[cur].size() == 0) {
                        cur -= 3;
                        if (cur < 0) {
                            out.println("Impossible");
                            return;
                        }
                    }
                    ans.add(index[cur].get(index[cur].size() - 1));
                    index[cur].remove(index[cur].size() - 1);
                    cur++;
                }
            }
            out.println("Possible");
            for (int i : ans) {
                out.print(i + " ");
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