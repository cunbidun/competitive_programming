import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.io.BufferedWriter;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        Task1278C solver = new Task1278C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1278C {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                n *= 2;
                int[] lb = new int[n / 2 + 1];
                int[] lr = new int[n / 2 + 1];
                int[] rb = new int[n / 2 + 1];
                int[] rr = new int[n / 2 + 1];
                int[] a = in.nextIntArray(n, 1);
                for (int i = 1; i <= n / 2; i++) {
                    lb[i] = lb[i - 1];
                    lr[i] = lr[i - 1];
                    if (a[i] == 1) lb[i]++;
                    else lr[i]++;
                }
                int cnt = 1;
                for (int i = n; i >= n / 2 + 1; i--) {
                    rb[cnt] = rb[cnt - 1];
                    rr[cnt] = rr[cnt - 1];

                    if (a[i] == 1) rb[cnt]++;
                    else rr[cnt]++;
                    cnt++;
                }
                cnt--;
                TreeMap<Integer, Integer> map = new TreeMap<>();
                map.merge(0, 0, Integer::max);
                for (int i = 1; i <= cnt; i++) {
                    map.merge(lb[i] - lr[i], i, Integer::max);
                }

                int ans = INF;
                for (int i = cnt; i >= 0; i--) {
                    if (map.containsKey(rr[i] - rb[i])) {
                        ans = MaxMin.Min(ans, cnt - i + cnt - map.get(rr[i] - rb[i]));
                    }
                }
                out.println(ans);
            }
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public void println(int i) {
            out.println(i);
        }

    }
}