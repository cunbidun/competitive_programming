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
        Task1197D solver = new Task1197D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1197D {
        private InputReader in;
        private OutputWriter out;
        private int k;
        private int m;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            long[] f = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                f[i] = MaxMin.Max(0L, f[i] - k);
                long sum = a[i];
                for (int j = i - 1; j >= MaxMin.Max(0, i - m); j--) {
                    f[i] = MaxMin.Max(f[i], f[j] + sum - k);
                    sum += a[j];
                }
            }
            out.println(ArrayUtils.getMax(f, 1, n));
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
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

    static class ArrayUtils {
        public static long getMax(long[] array, int stIndex, int enIndex) {
            long max = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                max = MaxMin.Max(max, array[i]);
            }
            return max;
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