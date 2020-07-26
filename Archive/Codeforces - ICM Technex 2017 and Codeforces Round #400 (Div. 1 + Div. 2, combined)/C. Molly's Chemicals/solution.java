import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashMap;
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
        Task776C solver = new Task776C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task776C {
        private InputReader in;
        private OutputWriter out;
        private long[] s = new long[(int) 1e5 + 1];
        private int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            int k = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            for (int i = 1; i <= n; i++) {
                s[i] = s[i - 1] + a[i];
            }
            if (k == 1) {
                out.println(count(1));
                return;
            }
            if (k == -1) {
                out.println(count(1) + count(-1));
                return;
            }
            long cur = 1;
            long ans = 0;
            while (Math.abs(cur) <= (long) 1e9 * 1e5) {
                ans += count(cur);
                cur *= k;
            }
            out.println(ans);
        }

        private long count(long cur) {
            Counter cnt = new Counter();
            long res = 0;
            cnt.increase(0L);
            for (int i = 1; i <= n; i++) {
                res += cnt.get(s[i] - cur);
                cnt.increase(s[i]);
            }
            return res;
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

    static class Counter {
        public HashMap<Long, Integer> map = new HashMap<>();

        void increase(long key) {
            map.merge(key, 1, Integer::sum);
        }

        public int get(long key) {
            return map.getOrDefault(key, 0);
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
}