import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
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
        OutputWriter out = new OutputWriter(outputStream);
        EOpenStreetMap solver = new EOpenStreetMap();
        solver.solve(1, in, out);
        out.close();
    }

    static class EOpenStreetMap {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            int g0 = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            int z = in.nextInt();
            long ans = 0;
            int[][] array = new int[n + 1][m + 1];
            int[][] min = new int[n + 1][m + 1];
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    array[i][j] = g0;
                    g0 = Op.addMod(Op.mulMod(g0, x, z), y, z);
                }
            }
            for (int j = 1; j <= m; j++) {
                MinQueue q = new MinQueue();
                for (int i = 1; i <= n; i++) {
                    q.add(array[i][j]);
                    if (i >= a) {
                        min[i][j] = q.getMin();
                        q.remove(array[i - a + 1][j]);
                    }
                }
            }
            for (int i = a; i <= n; i++) {
                MinQueue q = new MinQueue();

                for (int j = 1; j <= m; j++) {
                    q.add(min[i][j]);
                    if (j >= b) {
                        ans += q.getMin();
                        q.remove(min[i][j - b + 1]);
                    }
                }
            }
            out.println(ans);
        }

        class MinQueue {
            Deque<Integer> q = new LinkedList<>();

            public void add(int val) {
                while (!q.isEmpty() && q.peekLast() > val) q.pollLast();
                q.addLast(val);
            }

            public void remove(int val) {
                while (!q.isEmpty() && q.peekFirst() == val) q.pollFirst();
            }

            public int getMin() {
                return q.peekFirst();
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(long i) {
            out.println(i);
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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