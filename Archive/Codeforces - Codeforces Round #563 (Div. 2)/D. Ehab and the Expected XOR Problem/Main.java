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
        DEhabAndTheExpectedXORProblem solver = new DEhabAndTheExpectedXORProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class DEhabAndTheExpectedXORProblem {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int x = in.nextInt();
            boolean[] used = new boolean[(1 << 18)];
            used[x] = true;
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = 1; i < (1 << n); i++)
                if (!used[i]) {
                    list.add(i);
                    int cur = list.size();
                    for (int j = 1; j < (1 << cur); j++) {
                        int sum = 0;
                        for (int k = 0; k < cur; k++) {
                            if (((j >> k) & 1) == 1) {
                                sum ^= list.get(k);
                            }
                        }
                        used[sum] = true;
                        used[x ^ sum] = true;
                    }
                }
//        out.println(list.size());
            if (list.size() == 0) {
                out.println(0);
                return;
            }
            ArrayList<Integer> ans = new ArrayList<>();
            ans.add(list.get(0));

            for (int i = 1; i < list.size(); i++) {
                ArrayList tmpList = new ArrayList(ans);
                ans.add(list.get(i));
                ans.addAll(tmpList);
            }
            out.println(ans.size());
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