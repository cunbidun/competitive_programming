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
import java.util.TreeSet;
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
        DArrayDivision solver = new DArrayDivision();
        solver.solve(1, in, out);
        out.close();
    }

    static class DArrayDivision {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            long sum = ArrayUtils.getSum(a, 1, n);
            long[] s = new long[n + 1];

            TreeSet<Long> set = new TreeSet<>();
            for (int i = 1; i <= n; i++) {
                s[i] = s[i - 1] + a[i];
                if (s[i] * 2 == sum) {
                    out.println("YES");
                    return;
                }
            }
            for (int i = 1; i <= n; i++) {
                set.add(a[i]);
                long tmp = s[i] - (s[n] - s[i]);
                if (tmp % 2 == 0 && tmp >= 0) {
                    if (set.contains(tmp / 2)) {
                        out.println("YES");
                        return;
                    }
                }
            }

            set = new TreeSet<>();
            for (int i = n; i >= 1; i--) {
                set.add(a[i]);
                long tmp = (s[n] - s[i - 1]) - s[i - 1];
                if (tmp % 2 == 0 && tmp >= 0) {
                    if (set.contains(tmp / 2)) {
                        out.println("YES");
                        return;
                    }
                }
            }
            out.println("NO");
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

        public void println(String i) {
            out.println(i);
        }

    }

    static class ArrayUtils {
        public static long getSum(long[] a, int st, int en) {
            long ans = 0;
            for (int i = st; i <= en; i++) ans += a[i];
            return ans;
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}